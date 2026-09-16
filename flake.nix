{
  description = "Development environment & packaging for OpenCL-Headers";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in {
        checks.c-tests = pkgs.stdenv.mkDerivation {
          name = "opencl-headers-c-tests";
          nativeBuildInputs = [ pkgs.cmake ];

          src = ./.;

          cmakeFlags = [
            "-DOPENCL_HEADERS_BUILD_TESTING=ON"
            "-DOPENCL_HEADERS_BUILD_CXX_TESTS=OFF"
          ];

          doCheck = true;
        };
        checks.cpp-tests = self.packages.${system}.default;
        checks.pkg-config = self.packages.${system}.default.passthru.tests.pkg-config;

        packages.default = pkgs.stdenv.mkDerivation (finalAttrs: rec {
          name = "opencl-headers";
          nativeBuildInputs = [ pkgs.cmake ];

          src = ./.;

          doCheck = true;

          passthru.tests = with pkgs; {
            pkg-config = pkgs.testers.hasPkgConfigModules {
              package = finalAttrs.finalPackage;
              moduleNames = [ "OpenCL-Headers" ];
            };
          };
        });

        devShells.default = pkgs.mkShell {
          buildInputs = [
            pkgs.pkg-config
            self.packages.${system}.default 
          ];

          doCheck = false; # Disables automatically running tests for `$ nix develop` and direnv

          shellHook = ''
            export ZDOTDIR=$(mktemp -d)
            cat > "$ZDOTDIR/.zshrc" << 'EOF'
              source ~/.zshrc # Source the original ~/.zshrc, required.

              function parse_git_branch {
                git branch --no-color 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/\ ->\ \1/'
              }

              function display_jobs_count_if_needed {
                local job_count=$(jobs -s | wc -l | tr -d " ")

                if [ $job_count -gt 0 ]; then
                  echo "%B%F{yellow}%j| ";
                fi
              }

              # NOTE: Custom prompt with a snowflake: signals we are in `$ nix develop` shell
              PROMPT="%F{blue}$(date +%H:%M:%S) $(display_jobs_count_if_needed)%B%F{green}%n %F{blue}%~%F{cyan} ❄%F{yellow}$(parse_git_branch) %f%{$reset_color%}"
            EOF

            if [ -z "$DIRENV_IN_ENVRC" ]; then # This makes `$ nix develop` universally working with direnv without infinite loop
              exec ${pkgs.zsh}/bin/zsh -i
            fi
          '';
        };
      });
}
