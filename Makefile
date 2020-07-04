fileNameDecode:
	gcc main.c urldecode.c -o fileNameDecode


clean:
	rm fileNameDecode
install:
	sudo mv ./fileNameDecode /usr/bin/fileNameDecode


