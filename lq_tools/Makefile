CFLAGS=-g -Wall -Wextra -fPIC -std=c99
OBJECTS_DIR=objects
TARGET_DIR=bin
TARGET=demo_run

SOURCES=cfiles/net/tcp_server.c\
	cfiles/main.c

OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

all: $(OBJECTS)
	$(CC) -o2 $(OBJECTS_DIR)/* -o $(TARGET_DIR)/$(TARGET)

$(OBJECTS): %.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	cp $@ $(OBJECTS_DIR)/$(notdir $@)
	-$(RM) $@


.PHONY: clean
clean:
	-$(RM) $(OBJECTS_DIR)/* $(TARGET_DIR)/$(TARGET) 
