
CC=gcc
OBJECT= main.o dmo_datetime.o dmo_add.o dmo_average.o 


INCLUDE = 
LIB = -llua -lstdc++
WALL= -Wall

TARGET= TestMain
all: $(OBJECT) $(TARGET)


TestMain: $(OBJECT)
	$(CC) $(WALL) -o TestMain $(OBJECT)  $(LIB)

main.o:main.cpp
	$(CC) $(WALL) -c main.cpp $(INCLUDE) $(LIB)
	
dmo_datetime.o:dmo_datetime.cpp dmo_datetime.h
	$(CC) $(WALL) -c dmo_datetime.cpp $(INCLUDE) $(LIB)

dmo_add.o:dmo_add.cpp dmo_add.h
	$(CC) $(WALL) -c dmo_add.cpp $(INCLUDE) $(LIB)
	
dmo_average.o:dmo_average.cpp dmo_average.h
	$(CC) $(WALL) -c dmo_average.cpp  $(INCLUDE) $(LIB)

	
clean:
	rm -f *.lib *.o *.a $(TARGET) $(OBJECT)

