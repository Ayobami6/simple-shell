FROM ubuntu
COPY . /zip/hsh /zip/publish /zip/tic-tac /bin/
WORKDIR /bin/
CMD /bin/hsh
