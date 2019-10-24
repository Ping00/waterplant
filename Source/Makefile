####################################################
#
# WATERPLANT v1.0 (Build 042) MAKEFILE
#
####################################################

CC = g++
CFLAGS = -Wall -pthread -D_REENTRANT -lwiringPi -lcurses -std=c++17
TARGET = waterplant

# Additional Sourcefiles
SOURCES = main.cpp


all : $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean :
	rm $(TARGET) *~
 
