FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN gcc Lexical.cpp -o lexical
RUN chmod +x lexical