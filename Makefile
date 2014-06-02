TARGET=mand
MODULES=mand.o
LIBBMP=-I/usr/local/include -L/usr/local/lib -lbmp
CFLAGS=-Wall -Wextra -std=c99

$(TARGET): $(MODULES)
	gcc $(MODULES) $(CFLAGS) $(LIBBMP) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	/bin/rm *.o $(TARGET)

all: clean $(TARGET)

mand.o: mand.c
