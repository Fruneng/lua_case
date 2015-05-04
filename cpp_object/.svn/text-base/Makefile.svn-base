
CC=gcc
OBJECT=
TARGET= demo

INCLUDE=
LIB= -llua -lstdc++
WALL= 

all: $(OBJECT) $(TARGET)

demo: demo.cpp
	$(CC) $(WALL) -o demo demo.cpp $(INCLUDE) $(LIB)

clean:
	rm -f *.lib *.o *.a $(TARGET) $(OBJECT)
