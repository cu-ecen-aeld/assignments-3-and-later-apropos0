SRC := writer.c
TARGET = writer
OBJS := $(SRC:.c=.o)
CC = $(CROSS_COMPILE)gcc
$(TARGET) : $(OBJS)
	$(CROSS_COMPILE)gcc $(OBJS) -o $(TARGET)

clean:
	-rm -f *.o $(TARGET) *.elf *.map
