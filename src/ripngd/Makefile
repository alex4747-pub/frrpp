TOP ?=  ../..

include $(TOP)/src/Makefile.include

CXXFLAGS = $(BASE_CXXFLAGS)

SRCS = \
	RipngInfo.cpp

INCS = \
	RipngInfo.hpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(OBJS)

%.o: %.cc $(INCS)
	$(CXX) -c $(CXXFLAGS) $<

format:
	$(FORMAT) $(STYLE) -i $(SRCS) $(INCS)

tidy:
	$(TIDY) --fix -extra-arg-before=-xc++ $(SRCS) $(INCD) -- $(CXXFLAGS) $(STD)

cpplint:
	$(CPPLINT) $(SRCS) $(INCS)

clean:
	rm -rf *~ *.dSYM *.o

