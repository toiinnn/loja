# Arquivo principal para compilar
BINDIR = bin
SRCDIR = src
INCLUDEDIR = include
APPDIR = application
OBJDIR = build

# Flags necessarias
CC = g++
CFLAGS = -g -O0 -Wall -std=c++14 -pedantic -I $(INCLUDEDIR)

# Arquivo principal 
BIN = ${BINDIR}/loja
APP = ${APPDIR}/main.cpp

# Gerar arquivos objetos
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
APPOBJ = $(patsubst $(APPDIR)/%.cpp,$(OBJDIR)/%.o,$(APP))

# Diretorio principal
$(BIN): $(OBJS) $(APPOBJ)
	$(CC) -o $(BIN) $(APPOBJ) $(OBJS) $(CFLAGS) $(LDFLAGS)

$(APPOBJ): $(APP)
	$(CC) -c -o $@ $< $(CFLAGS)
	
${OBJDIR}/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(BIN) $(OBJS) $(APPOBJ)
