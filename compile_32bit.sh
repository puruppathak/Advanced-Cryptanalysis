g++ -o ghotekar-pathak-encrypt ghotekar-pathak-encrypt.cpp -lssl -lcrypto
g++ -o ghotekar-pathak-authorize ghotekar-pathak-authorize.cpp -lssl -lcrypto
g++ -o ghotekar-pathak-decrypt ghotekar-pathak-decrypt.cpp -lssl -lcrypto
g++ -g -O -c ghotekar-pathak-aws-s3-cloud-upload.cpp -I./chilkat-9.5.0-x86-linux-gcc/include/
g++ -o ghotekar-pathak-aws-s3-cloud-upload ghotekar-pathak-aws-s3-cloud-upload.o -L./chilkat-9.5.0-x86-linux-gcc/lib -lchilkat-9.5.0 -lresolv -lpthread
g++ -g -O -c ghotekar-pathak-aws-s3-cloud-download.cpp -I./chilkat-9.5.0-x86-linux-gcc/include/
g++ -o ghotekar-pathak-aws-s3-cloud-download ghotekar-pathak-aws-s3-cloud-download.o -L./chilkat-9.5.0-x86-linux-gcc/lib -lchilkat-9.5.0 -lresolv -lpthread

