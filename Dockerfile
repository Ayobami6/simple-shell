FROM alphine
COPY . /app/files.zip /bin/
WORKDIR /bin/
RUN unzip /bin/files.zip -d /bin
CMD /bin/hsh
