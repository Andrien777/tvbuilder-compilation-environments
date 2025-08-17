FROM ubuntu:24.04
WORKDIR /opt/tvb-compilation
RUN apt-get update && apt-get install -y --no-install-recommends \
	software-properties-common \
	gpg-agent \
    build-essential \
	gcc-riscv64-unknown-elf
RUN add-apt-repository "deb http://ppa.launchpad.net/tkchia/build-ia16/ubuntu jammy main" && \
	apt-get update && apt-get install -y --no-install-recommends \
    gcc-ia16-elf
