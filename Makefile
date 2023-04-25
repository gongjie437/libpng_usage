CC := g++
OUT := sample_app
CXXFLAGS = -Wall -g -I.
LFLAGS = -lpng12 -lz
OUT_DIR=out

DEPS := \
	test-libpng.o \
	test.o
SRCS = \
	lib-libpng.cpp \
	test.cpp

.PHONY: all clean

all: $(SRCS)
	$(CC) $? $(CXXFLAGS) $(LFLAGS) -o $(OUT)

clean:
	rm -f *.o
	rm -f $(OUT)
