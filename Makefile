CC = g++
OBJECT1 = main.o
OBJECT2 = tree.o

TARGET1 = P0

FLAGS = -std=c++11 -lm -g -Wall

all: $(TARGET1)

$(TARGET1): $(OBJECT1)
	$(CC) $< -o $@ $(FLAGS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o $(TARGET1) temp_data.fl2021
