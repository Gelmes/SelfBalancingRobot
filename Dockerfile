FROM gcc:latest

WORKDIR /home

RUN apt-get update && \
    apt-get -y install lcov && \
    git clone https://github.com/cpputest/cpputest.git && \
    cd cpputest && \
    autoreconf . -i && \
    ./configure && \
    make install 

ENV CPPUTEST_HOME="/home/cpputest"

WORKDIR /home/src