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
build: cmake
	@cd $(BUILD_DIR) && msbuild report.sln
else
build: cmake
	@cd $(BUILD_DIR) && make
endif

clean:
	@rm -rf $(BUILD_DIR)

cmake:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake $(CMAKE_ARGS) $(CURR_DIR)

tests:
	$(BUILD_DIR)/bin/$(BINARY_PREFIX)tests$(BINARY_SUFFIX)

ctests:
	@cd $(BUILD_DIR) && make test

client:
	$(BUILD_DIR)/bin/$(BINARY_PREFIX)client$(BINARY_SUFFIX)

server:
	$(BUILD_DIR)/bin/$(BINARY_PREFIX)server$(BINARY_SUFFIX)

.PHONY: default build clean cmake tests ctests client server
