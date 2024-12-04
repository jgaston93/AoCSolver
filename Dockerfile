FROM ubuntu:24.10
RUN apt-get update \
  && apt-get -y install build-essential clang-format cmake gdb git  \
  && apt-get clean \
  && git clone https://github.com/nlohmann/json.git /usr/src/json \
  && git clone https://github.com/jarro2783/cxxopts.git /usr/src/cxxopts \
  && cp -r /usr/src/json/single_include/nlohmann /usr/local/include \
  && cp /usr/src/cxxopts/include/cxxopts.hpp /usr/local/include \
  && adduser user
WORKDIR /usr/src/app
COPY . .
RUN cmake -B build -S ./ \
  && cmake --build build \
  && chown -R user ./

USER user