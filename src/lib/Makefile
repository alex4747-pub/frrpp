TOP ?=  ../..

include $(TOP)/src/Makefile.include

CXXFLAGS = $(BASE_CXXFLAGS)

SRCS = \
	DaemonInfo.cpp \
	Northbound.cpp

INCS = \
	include/Capability.hpp \
	include/Daemon.hpp \
	include/DaemonInfo.hpp \
	include/Northbound.hpp \
	include/PpTypes.hpp  \
	include/Vrf.hpp  \
	include/Zlog.hpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(OBJS)

%.o: %.cc $(INCS)
	$(CXX) -c $(CXXFLAGS) $<

format:
	$(FORMAT) $(STYLE) -i $(SRCS) $(INCS)

tidy:
	$(TIDY) --fix -extra-arg-before=-xc++ $(SRCS) $(INCS) -- $(CXXFLAGS) $(STD)

cpplint:
	$(CPPLINT) $(SRCS) $(INCS)

clean:
	rm -f *~ *.dSYM *.o
	rm -f include/*~


