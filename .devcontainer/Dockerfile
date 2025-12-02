FROM ubuntu:latest
RUN apt-get update \
  && apt-get -y install build-essential clang-format cmake gdb git  \
  && apt-get clean \
  && git clone https://github.com/nlohmann/json.git /usr/src/json \
  && git clone https://github.com/jarro2783/cxxopts.git /usr/src/cxxopts
WORKDIR /usr/src/json
RUN cmake -B build -S ./ -DCMAKE_BUILD_TYPE=Release -DJSON_BuildTests=OFF \
  && cmake --build build --target install
WORKDIR /usr/src/cxxopts
RUN cmake -B build -S ./ -DCMAKE_BUILD_TYPE=Release -DCXXOPTS_BUILD_EXAMPLES=OFF -DCXXOPTS_BUILD_TESTS=OFF \
  && cmake --build build --target install \
  && git clone https://github.com/jgaston93/AoCSolver.git /AoCSolver

WORKDIR /AoCSolver

ENTRYPOINT [ "/bin/bash", "-c" ]
CMD ["tail", "-f", "/dev/null"]


