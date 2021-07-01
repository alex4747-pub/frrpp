TOP ?=  ../..

include $(TOP)/src/Makefile.include

CXXFLAGS = $(BASE_CXXFLAGS)

SRCS = \
	DaemonInfo.cpp \
	Yang.cpp

INCS = \
	include/Capability.hpp \
	include/Daemon.hpp \
	include/DaemonInfo.hpp \
	include/PpTypes.hpp  \
	include/Vrf.hpp  \
	include/Yang.hpp \
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
	rm -rf *~ *.dSYM *.o

