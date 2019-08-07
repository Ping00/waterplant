####################################################
#
# WATERPLANT V0.01 MAKEFILE
#
####################################################

CC = g++
CFLAGS = -Wall -pthread -D_REENTRANT -lwiringPi -lcurses
TARGET = waterplant

# Additional Sourcefiles
SOURCES = main.cpp


all : $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean :
	rm $(TARGET) *~
 
