FROM gcc:10
WORKDIR /
COPY ./* ./
RUN gcc lexical.cpp -o lexical
RUN chmod +x lexical