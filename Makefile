CC = g++
CFLAGS = -Wall -std=c++11

# Object files
OBJS = geometry.o app.o test.o

# Executable files
EXEC = app test

all: $(EXEC)

# Compile geometry.cpp to geometry.o
geometry.o: geometry.cpp geometry.hpp
	$(CC) $(CFLAGS) -c geometry.cpp

# Compile app.cpp to app.o
app.o: app.cpp geometry.hpp
	$(CC) $(CFLAGS) -c app.cpp

# Compile test.cpp to test.o
test.o: test.cpp geometry.hpp
	$(CC) $(CFLAGS) -c test.cpp

# Link object files to create app executable
app: geometry.o app.o
	$(CC) $(CFLAGS) -o app geometry.o app.o

# Link object files to create test executable
test: geometry.o test.o
	$(CC) $(CFLAGS) -o test geometry.o test.o

clean:
	rm -f $(OBJS) $(EXEC)
