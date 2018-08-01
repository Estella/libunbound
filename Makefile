REPO := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
BUILD_DIR := $(REPO)/build
DNS_LIB := $(BUILD_DIR)/libunbound.a


all: clean build

ensure:
	mkdir -p $(BUILD_DIR)

configure: ensure
	cd $(BUILD_DIR) && cmake $(REPO) -GNinja

build: configure
	cd $(BUILD_DIR) && ninja 

clean:
	rm -fr $(BUILD_DIR)