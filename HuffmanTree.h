#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <bitset>

class HuffmanTree {
private:
    struct Node {
        char ch;
        int freq;
        Node* left;
        Node* right;
        Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    };

    struct Compare {
        bool operator()(Node* l, Node* r) {
            return l->freq > r->freq;
        }
    };

    Node* root;
    std::unordered_map<char, std::string> huffmanCode;

    void buildHuffmanTree(const std::unordered_map<char, int>& freq);
    void encode(Node* root, const std::string& str);
    void decode(Node* root, int& index, const std::string& str, std::string& result);

public:
    HuffmanTree();
    ~HuffmanTree();
    void build(const std::string& text);
    std::string encode(const std::string& text);
    std::string decode(const std::string& encodedText);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    void clear();
};

#endif // HUFFMANTREE_H
