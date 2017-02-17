BUILD_DIR?=cmake.bld

CMAKE_ARGS=
ifdef CC
CMAKE_ARGS += -DCMAKE_C_COMPILER=$(CC)
endif

ifdef CXX
CMAKE_ARGS +=-DCMAKE_CXX_COMPILER=$(CXX)
endif

ifdef BOOST_ROOT
CMAKE_ARGS += -DBOOST_ROOT=$(BOOST_ROOT)
endif

ifdef Boost_NO_BOOST_CMAKE
CMAKE_ARGS += -DBoost_NO_BOOST_CMAKE=$(Boost_NO_BOOST_CMAKE)
endif

ifdef Boost_USE_STATIC_LIBS
CMAKE_ARGS += -DBoost_USE_STATIC_LIBS=$(Boost_USE_STATIC_LIBS)
endif

ifdef Boost_USE_MULTITHREADED
CMAKE_ARGS += -DBoost_USE_MULTITHREADED=$(Boost_USE_MULTITHREADED)
endif

ifdef Boost_USE_STATIC_RUNTIME
CMAKE_ARGS += -DBoost_USE_STATIC_RUNTIME=$(Boost_USE_STATIC_RUNTIME)
endif

CURR_DIR=$(shell pwd)

BINARY_PREFIX=
BINARY_SUFFIX=
ifeq ($(OS),Windows_NT)
BINARY_PREFIX=Debug/
BINARY_SUFFIX=.exe
endif

default: test

ifeq ($(OS),Windows_NT)
debugbuild: cmake
	@cd $(BUILD_DIR) && cmake --build . --config Debug
releasebuild: cmake
	@cd $(BUILD_DIR) && cmake --build . --config Release
else
build: cmake
	@cd $(BUILD_DIR) && make
endif

clean:
	@rm -rf $(BUILD_DIR)

cmake:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake $(CMAKE_ARGS) $(CURR_DIR)

ifeq ($(OS),Windows_NT)
debugctests: debugbuild
	@cd $(BUILD_DIR) && ctest -C Debug
releasectests: releasebuild
	@cd $(BUILD_DIR) && ctest -C Release
else
ctests: build
	@cd $(BUILD_DIR) && ctest
endif

ifeq ($(OS),Windows_NT)
debugtests:
	$(BUILD_DIR)/bin/Release/tests.exe

releasetests:
	$(BUILD_DIR)/bin/Release/tests.exe

debugclient:
	$(BUILD_DIR)/bin/Debug/client.exe

releaseclient:
	$(BUILD_DIR)/bin/Release/client.exe

debugserver:
	$(BUILD_DIR)/bin/Debug/server.exe

releaseserver:
	$(BUILD_DIR)/bin/Release/server.exe
else
tests:
	$(BUILD_DIR)/bin/tests

client:
	$(BUILD_DIR)/bin/client

server:
	$(BUILD_DIR)/bin/server
endif

.PHONY: default debugbuild releasebuild build clean cmake debugctests releasectests ctests debugtests releasetests debugclient releaseclient debugserver releaseserver tests client server 
