FROM ubuntu:24.04

RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang-19 \
    clangd-19 \
    llvm-19 \
    libclang-rt-19-dev \
    cmake \
    gdb \
    wget \
    ca-certificates \
    git \
    valgrind \
    bzip2 \
    htop

RUN update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-19 100

# Set environment variables for ASan
ENV ASAN_SYMBOLIZER_PATH=/usr/bin/llvm-symbolizer-19 \
    ASAN_OPTIONS=verbosity=1:detect_leaks=1

WORKDIR /tmp