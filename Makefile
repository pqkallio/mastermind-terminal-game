CXX = g++

src = $(wildcard src/*.cpp) \
			$(wildcard src/gamelogic/*.cpp) \
			$(wildcard src/gui/*.cpp)
obj = $(src:.cpp=.o)

CXXFLAGS = -Wall -g
LDFLAGS = -lncurses

mastermind: $(obj)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) mastermind
