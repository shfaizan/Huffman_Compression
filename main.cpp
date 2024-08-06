#include "HuffmanTree.h"

int main() {
    HuffmanTree huffmanTree;

    std::string text = "this is an example for huffman encoding";
    huffmanTree.build(text);

    std::string encodedText = huffmanTree.encode(text);
    std::cout << "Encoded Text: " << encodedText << std::endl;

    std::string decodedText = huffmanTree.decode(encodedText);
    std::cout << "Decoded Text: " << decodedText << std::endl;

    huffmanTree.saveToFile("huffman_tree.dat");
    huffmanTree.clear();

    huffmanTree.loadFromFile("huffman_tree.dat");
    decodedText = huffmanTree.decode(encodedText);
    std::cout << "Decoded Text after loading from file: " << decodedText << std::endl;

    return 0;
}
