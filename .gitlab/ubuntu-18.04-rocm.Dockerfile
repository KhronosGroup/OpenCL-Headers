FROM streamhpc/opencl-sdk-base:ubuntu-18.04-20211103
RUN set -ex; \
    export DEBIAN_FRONTEND=noninteractive ; \
    apt update -qq; \
#   Register ROCm APT repo
    wget -q -O - https://repo.radeon.com/rocm/rocm.gpg.key | apt-key add - ; \
    apt-add-repository 'deb [arch=amd64] https://repo.radeon.com/rocm/apt/debian/ ubuntu main' ; \
#   Install OpenCL package only (and dependency)
    apt install -y -qq rocm-opencl-dev libnuma-dev ; \
    ln -s /opt/rocm-4.5.0 /opt/rocm