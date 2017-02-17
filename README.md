# reporting-cpp
Client-Server Reporting System

[![Build status](https://ci.appveyor.com/api/projects/status/q6pdrrkc7y8k2pwh?svg=true)](https://ci.appveyor.com/project/spaque/reporting-cpp)


# Requirements
* cmake 3.1+
* gcc-4.9+ on Linux/Mac
* Visual Studio 2013+ on Windows
* Boost

# Building
On Linux/Mac:

	$ make build

On Windows:

	$ make <debugbuild|releasebuild>

## Build Variables
You might need to define a number of variables to successfully build the project:

* `CC`: Alternative path to the C compiler if needed.
* `CXX`: Alternative path to the C++ compiler if needed.
* `BOOST_ROOT`: Boost installation directory, e.g. `C:/boost_1_63_0`, `/usr/local/boost_1_63_0`.
* `Boost_NO_BOOST_CMAKE`: Set to ON to force usage of `BOOST_ROOT`.
* `Boost_USE_STATIC_LIBS`, `Boost_USE_MULTITHREADED`, `Boost_USE_STATIC_RUNTIME`: Set to ON or OFF if needed.

```
	$ make build BOOST_ROOT=C:/boost_1_63_0
```

Artifacts can be found in the `cmake.bld` subdirectory.

# Running tests
On Linux/Mac:

	$ make ctests

On Windows:

	$ make <debugctests|releasectests>

# Running client & server
On different Linux/Mac terminals run:

	$ make server
	$ make client

or from Windows:

	$ make <debugserver|releaseserver>
	$ make <debugclient|releaseclient>

Note the input files `sample.log` and `config.json` needed by the applications will be copied to the output directory on a successful build.
