CC=gcc

IDIR=include
SRCDIR=src
ODIR=obj
BINDIR=bin

DRAW=draw
DRAW_BIN=$(BINDIR)/$(DRAW)
DRAW_IDIR=$(IDIR)/$(DRAW)
DRAW_SRCDIR=$(SRCDIR)/$(DRAW)
DRAW_ODIR=$(ODIR)/$(DRAW)
DRAW_SRCS=$(wildcard $(DRAW_SRCDIR)/*.c)
DRAW_OBJS=$(patsubst $(DRAW_SRCDIR)/%.c,$(DRAW_ODIR)/%.o,$(DRAW_SRCS))
DRAW_CFLAGS=-I$(DRAW_IDIR)

LSYSTEM=lsystem
LSYSTEM_BIN=$(BINDIR)/$(LSYSTEM)
LSYSTEM_IDIR=$(IDIR)/$(LSYSTEM)
LSYSTEM_SRCDIR=$(SRCDIR)/$(LSYSTEM)
LSYSTEM_ODIR=$(ODIR)/$(LSYSTEM)
LSYSTEM_SRCS=$(wildcard $(LSYSTEM_SRCDIR)/*.c)
LSYSTEM_OBJS=$(patsubst $(LSYSTEM_SRCDIR)/%.c,$(LSYSTEM_ODIR)/%.o,$(LSYSTEM_SRCS))
LSYSTEM_CFLAGS=-I$(LSYSTEM_IDIR)

$(LSYSTEM_ODIR):
	mkdir -p $@

$(DRAW_ODIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

$(LSYSTEM_ODIR)/%.o: $(LSYSTEM_SRCDIR)/%.c $(LSYSTEM_ODIR)
	$(CC) -c -o $@ $(filter %.c,$<) $(LSYSTEM_CFLAGS)

$(DRAW_ODIR)/%.o: $(DRAW_SRCDIR)/%.c $(DRAW_ODIR)
	$(CC) -c -o $@ $(filter %.c,$<) $(DRAW_CFLAGS)

$(DRAW_BIN): $(DRAW_OBJS) $(BINDIR)
	$(CC) -o $@ $(filter %.o,$^) $(DRAW_CFLAGS)

$(LSYSTEM_BIN): $(LSYSTEM_OBJS) $(BINDIR)
	$(CC) -o $@ $(filter %.o,$^) $(LSYSTEM_CFLAGS)

draw: $(DRAW_BIN)
lsystem: $(LSYSTEM_BIN)

all: draw lsystem

.PHONY: clean

clean:
	rm -r $(ODIR)
	rm -r $(BINDIR)
