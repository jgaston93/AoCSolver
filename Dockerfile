FROM ubuntu:latest
RUN apt-get update \
  && apt-get -y install git \
  && apt-get clean \
  && git clone https://github.com/nlohmann/json.github /usr/src/json
WORKDIR /usr/src/json
RUN cmake -B build -S ./ \
  && cmake --build build --parallel 4 \
  && cmake --install build --config Release \
  && git clone https://github.com/jarro2783/cxxopts.git /usr/src/cxxopts
WORKDIR /usr/src/cxxopts
RUN cmake -B build -S ./ \
  && cmake --build build --parallel 4 \
  && cmake --install build --config Release \
  && git clone https://github.com/jgaston93/AoCSolver.git /usr/src/app
WORKDIR /usr/src/app
