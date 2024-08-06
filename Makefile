CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = HuffmanCoding

all: $(TARGET)

$(TARGET): main.o HuffmanTree.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o HuffmanTree.o

main.o: main.cpp HuffmanTree.h
	$(CXX) $(CXXFLAGS) -c main.cpp

HuffmanTree.o: HuffmanTree.cpp HuffmanTree.h
	$(CXX) $(CXXFLAGS) -c HuffmanTree.cpp

clean:
	rm -f $(TARGET) *.o
