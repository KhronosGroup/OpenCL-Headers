from cpt.packager import ConanMultiPackager
import datetime

if __name__ == "__main__":
    builder = ConanMultiPackager(
    	username="khronos",
    	login_username="khronos",
    	channel="stable"
	)
    builder.add_common_builds()
    builder.run()
