CXX = g++

src = $(wildcard src/*.cpp) \
			$(wildcard src/gamelogic/*.cpp) \
			$(wildcard src/gui/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -lncurses

mastermind: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) mastermind
