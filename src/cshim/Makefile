TOP ?=  ../..

include $(TOP)/src/Makefile.include

CFLAGS = $(BASE_CFLAGS)

SRCS =

INCS =


OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(OBJS)

%.o: %.c $(INCS)
	$(CC) -c $(CFLAGS) $<

format:
	$(FORMAT) $(STYLE) -i $(SRCS) $(INCS)

tidy:
	$(TIDY) --fix $(SRCS) $(INCS) -- $(CFLAGS) $(STD)

# No cpplint for c-files
cpplint:


clean:
	rm -rf *~ *.dSYM *.o *.tmp res
	rm -rf include/*~ include/*.tmp include/res
