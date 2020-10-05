FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN gcc lexical.cpp -o lexical
RUN chmod +x lexical