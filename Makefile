BINDIR = bin
SRCDIR = src
INCLUDEDIR = include
APPDIR = application
OBJDIR = build

.PHONY: all init

all: appdir

CC = g++
CFLAGS = -g -O0 -Wall -std=c++14 -pedantic -I $(INCLUDEDIR)

BIN = ${BINDIR}/loja
APP = ${APPDIR}/main.cpp

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
APPOBJ = $(patsubst $(APPDIR)/%.cpp,$(OBJDIR)/%.o,$(APP))

$(BIN): $(OBJS) $(APPOBJ)
	$(CC) -o $(BIN) $(APPOBJ) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(APPOBJ): $(APP)
	$(CC) -c -o $@ $< $(CFLAGS)
	
${OBJDIR}/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(BIN) $(OBJS) $(APPOBJ)

doxy:
	doxygen -g

doc:
	$(RM) $(DOC_DIR)/*
	doxygen
