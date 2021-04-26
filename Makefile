CFLAGS  = -Wall -Werror -Iinclude/
NOWARN  =  -Wno-unused-function -Wno-unused-variable
LDFLAGS =

LIBSRC  = $(wildcard src/ompt-*.c)
LIBHEAD = $(wildcard include/*.h)

OMPSRC  = $(wildcard src/omp-*.c)
OMPEXE  = $(patsubst src/omp-%.c,omp-%,$(OMPSRC))

OMPTLIB = lib/libompt-core.so

BINS    = $(OMPTLIB) $(OMPEXE)
DEBUG   = -g -DDEBUG_LEVEL=3

.PHONY: all clean run

all: $(BINS)

$(OMPEXE): $(OMPSRC)
	@$(CC) $(CFLAGS) $(NOWARN) $(DEBUG) $(CPP_OMP_FLAGS) $(LD_OMP_FLAGS) -fopenmp src/$@.c -o $@
	@echo COMPILING: $@
	@echo
	@echo $@ links to OMP at: `ldd $@ | grep "[lib|libi|libg]omp"`
	@echo

$(OMPTLIB): $(LIBSRC) $(LIBHEAD)
	@echo LINKING: $@
	@$(CC) $(CFLAGS) $(NOWARN) $(DEBUG) $(LDFLAGS) -shared -fPIC $(LIBSRC) -o $@

run: $(BINS)
	OMP_TOOL_LIBRARIES=`pwd`/$(OMPTLIB) ./$(EXE)

clean:
	@-rm -f lib/* obj/* $(BINS)
