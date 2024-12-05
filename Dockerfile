FROM ubuntu:24.10
RUN apt-get update \
  && apt-get -y install build-essential clang-format cmake gdb git  \
  && apt-get clean \
  && git clone https://github.com/nlohmann/json.git /usr/src/json \
  && git clone https://github.com/jarro2783/cxxopts.git /usr/src/cxxopts
WORKDIR /usr/src/json
RUN cmake -B build -S ./ \
  && cmake --build build --target install
WORKDIR /usr/src/cxxopts
RUN cmake -B build -S ./ \
  && cmake --build build --target install

WORKDIR /usr/src/app
