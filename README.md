# reporting-cpp
Client-Server Reporting System

# Requirements
* gcc-4.9+ on Linux/Mac.
* Visual Studio 2013+ on Windows.
* Boost.

# Building

	$ make build

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

Artifacts can be found in the cmake.bld subdirectory.

# Running tests
	$ make tests

# Running client & server
On different terminals run:

	$ make server

and

	$ make client

Note the input file `sample.log` needed by the client will be copied to the output directory on a successful build.
