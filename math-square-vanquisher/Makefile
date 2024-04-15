VANQUISHER_MAIN = vanquisher

CXX = g++
LD = g++
CXXFLAGS = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -pthread -lm

all: $(VANQUISHER_MAIN)

$(VANQUISHER_MAIN) : main.cpp
	$(LD) $^ $(LDFLAGS) -o $@

# Pattern rules for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(VANQUISHER_MAIN) $(OBJS_DIR) *.o
