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
DRAW_CFLAGS=-I$(DRAW_IDIR) -lm

LSYSTEM=lsystem
LSYSTEM_BIN=$(BINDIR)/$(LSYSTEM)
LSYSTEM_IDIR=$(IDIR)/$(LSYSTEM)
LSYSTEM_SRCDIR=$(SRCDIR)/$(LSYSTEM)
LSYSTEM_ODIR=$(ODIR)/$(LSYSTEM)
LSYSTEM_SRCS=$(wildcard $(LSYSTEM_SRCDIR)/*.c)
LSYSTEM_OBJS=$(patsubst $(LSYSTEM_SRCDIR)/%.c,$(LSYSTEM_ODIR)/%.o,$(LSYSTEM_SRCS))
LSYSTEM_CFLAGS=-I$(LSYSTEM_IDIR) -lm

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

draw_links: $(DRAW_BIN)
	[[ -L $(DRAW) ]] || ln -s $(DRAW_BIN) $(DRAW)

lsystem_links: $(LSYSTEM_BIN)
	[[ -L $(LSYSTEM) ]] || ln -s $(LSYSTEM_BIN) $(LSYSTEM)

debug_draw: DRAW_CFLAGS += -g -O0
debug_draw: draw
debug_lsystem: LSYSTEM_CFLAGS += -g -O0
debug_lsystem: lsystem

all: draw lsystem
debug: debug_draw debug_lsystem


clean:
	rm -r $(ODIR)
	rm -r $(BINDIR)
	rm $(DRAW)
	rm $(LSYSTEM)
	rm -r tests/out

test_draw: draw
	bash tests/bin/draw_tests.sh

test_lsystems: lsystem
	bash tests/bin/lsystems_tests.sh

test: test_draw test_lsystems

.PHONY: clean all test_draw test_lsystems test

