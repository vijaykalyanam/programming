TARGET = printf 
OBJS = print.o nomain.o

$(TARGET):$(OBJS)
	cc -nostartfiles -o $(TARGET) $(OBJS)

clean:
	rm -rf *.o printf
