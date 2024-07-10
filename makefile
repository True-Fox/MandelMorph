CC = g++

SRC_DIR = .
HEADERS_DIR = ./headers
CALLBACKS_DIR = ./callbacks
CALLBACK_HELPERS_DIR = ./callbacks/callback_helpers

SOURCES = $(SRC_DIR)/main.cpp \
          $(HEADERS_DIR)/glad.c \
          $(CALLBACKS_DIR)/main.cpp \
          $(CALLBACK_HELPERS_DIR)/main.cpp

TARGET = app

CFLAGS = -I$(HEADERS_DIR) -lglfw -ldl

$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET)
