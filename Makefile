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

CURR_DIR=$(shell pwd)

BINARY_SUFFIX=
ifeq ($(OS),Windows_NT)
BINARY_SUFFIX=.exe
endif

default: test

build: cmake
	@cd $(BUILD_DIR) && make

clean:
	@rm -rf $(BUILD_DIR)

cmake:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake $(CMAKE_ARGS) $(CURR_DIR)

test: build
	@cd $(BUILD_DIR) && make test

client:
	$(BUILD_DIR)/bin/client$(BINARY_SUFFIX)

server:
	$(BUILD_DIR)/bin/server$(BINARY_SUFFIX)

.PHONY: default build clean cmake test client server
