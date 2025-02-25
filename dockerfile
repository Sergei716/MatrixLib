FROM ubuntu:22.04

RUN apt update \
    && apt install vim -y \
    && apt install build-essential -y \
    && apt install check -y 

WORKDIR /project

COPY . .

CMD ["bash"]
