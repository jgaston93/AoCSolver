FROM ubuntu:24.10
RUN apt-get update \
  && apt-get -y install build-essential cmake git \
  && apt-get clean \
  && git clone https://github.com/nlohmann/json.git /usr/src/json
WORKDIR /usr/src/json
RUN cmake -B build -S ./ \
  && cmake --build build \
  && cmake --install build --config Release \
  && git clone https://github.com/jarro2783/cxxopts.git /usr/src/cxxopts
WORKDIR /usr/src/cxxopts
RUN cmake -B build -S ./ \
  && cmake --build build \
  && cmake --install build --config Release

WORKDIR /usr/src/app

COPY ./configuration ./configuration
COPY ./src ./src
COPY ./CMakeLists.txt .
