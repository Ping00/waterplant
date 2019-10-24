####################################################
#
# WATERPLANT v1.0 (Build 042) MAKEFILE
#
####################################################

CC = g++
CFLAGS = -Wall -pthread -D_REENTRANT -lwiringPi -lcurses -std=c++17
TARGET = waterplant

# Additional Sourcefiles
SOURCES = main.cpp \
Core/Engine/engine.cpp \
Core/GUI/GUI.cpp \
Core/Controller/controller.cpp \
Core/Controller/valve.cpp \
Core/GUI/States/GUI_BASE.cpp \
Core/GUI/States/GUI_Overview.cpp \
Core/GUI/States/GUI_Settings.cpp \
Core/GUI/States/GUI_Startup.cpp \
Core/GUI/States/GUI_Statistics.cpp \
Core/GUI/States/GUI_Status.cpp \
Core/GUI/Widgets/display_component.cpp \
Core/GUI/Widgets/graphic.cpp \
Core/GUI/Widgets/horizontal_menu.cpp \
Core/GUI/Widgets/vertical_menu.cpp \
Core/GUI/Widgets/message.cpp \
Hardware/Microproccesors/MCP3008/MCP3008.cpp \
Hardware/Sensors/SPI/SMSM/SMSM.cpp \
Hardware/Sensors/SPI/SPI_SENSOR/SPI_SENSOR.cpp \
Hardware/Sensors/SPI/TMP36/TMP36.cpp \
Utilities/WATERPLANT_FILE.cpp \
Utilities/utilities.cpp \
Utilities/timer.cpp \

all : $(TARGET)

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@

clean :
	rm $(TARGET) *~
 
