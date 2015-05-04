
CC=gcc
OBJECT= main.o dmo_dateTime.o dmo_add.o dmo_average.o 


INCLUDE = 
					
LIB = -llua -lstdc++
WALL= 

TARGET= TestMain
all: $(OBJECT) $(TARGET)


TestMain: $(OBJECT)
	$(CC) $(WALL) -o TestMain $(OBJECT)  $(LIB)

main.o:main.cpp
	$(CC) $(WALL) -c main.cpp $(INCLUDE)
	
dmo_dateTime.o:dmo_dateTime.cpp dmo_dateTime.h
	$(CC) $(WALL) -c dmo_dateTime.cpp $(INCLUDE)

dmo_add.o:dmo_add.cpp dmo_add.h
	$(CC) $(WALL) -c dmo_add.cpp $(INCLUDE)
	
dmo_average.o:dmo_average.cpp dmo_average.h
	$(CC) $(WALL) -c dmo_average.cpp  $(INCLUDE)

	
clean:
	rm -f *.lib *.o *.a $(TARGET) $(OBJECT)

