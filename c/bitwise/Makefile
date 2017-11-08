STATIC=YES
LINK_STATIC=-static

binary: common.o main.o
	gcc -static -o binary common.o main.o
bits_utils.so:
	gcc $(LINK_STATIC) -o bits_utils.so common.o main.o
clean:
	rm -rf *.o binary
