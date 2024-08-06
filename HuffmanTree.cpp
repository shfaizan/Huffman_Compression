#include "HuffmanTree.h"
#include <sstream>

HuffmanTree::HuffmanTree() : root(nullptr) {}

HuffmanTree::~HuffmanTree() {
    clear();
}

void HuffmanTree::clear() {
    // Implement a function to clear the tree memory
    // This is left as an exercise for the reader
}

void HuffmanTree::buildHuffmanTree(const std::unordered_map<char, int>& freq) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

    for (const auto& pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        int sum = left->freq + right->freq;
        Node* node = new Node('\0', sum);
        node->left = left;
        node->right = right;
        pq.push(node);
    }

    root = pq.top();
    encode(root, "");
}

void HuffmanTree::encode(Node* root, const std::string& str) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    encode(root->left, str + "0");
    encode(root->right, str + "1");
}

std::string HuffmanTree::encode(const std::string& text) {
    std::string encodedText;
    for (char ch : text) {
        encodedText += huffmanCode[ch];
    }
    return encodedText;
}

void HuffmanTree::decode(Node* root, int& index, const std::string& str, std::string& result) {
    if (!root) return;
    if (!root->left && !root->right) {
        result += root->ch;
        return;
    }
    index++;
    if (str[index] == '0') decode(root->left, index, str, result);
    else decode(root->right, index, str, result);
}

std::string HuffmanTree::decode(const std::string& encodedText) {
    std::string decodedText;
    int index = -1;
    while (index < (int)encodedText.size() - 1) {
        decode(root, index, encodedText, decodedText);
    }
    return decodedText;
}

void HuffmanTree::build(const std::string& text) {
    std::unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }
    buildHuffmanTree(freq);
}

void HuffmanTree::saveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
        return;
    }

    // Save the Huffman Tree structure
    std::ostringstream treeStream;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (!current) {
            treeStream << "# ";
        } else {
            treeStream << current->ch << " " << current->freq << " ";
            q.push(current->left);
            q.push(current->right);
        }
    }
    std::string treeStr = treeStream.str();
    size_t treeSize = treeStr.size();
    file.write(reinterpret_cast<const char*>(&treeSize), sizeof(treeSize));
    file.write(treeStr.c_str(), treeSize);

    // Save the Huffman codes
    size_t mapSize = huffmanCode.size();
    file.write(reinterpret_cast<const char*>(&mapSize), sizeof(mapSize));
    for (const auto& pair : huffmanCode) {
        file.put(pair.first);
        size_t codeSize = pair.second.size();
        file.write(reinterpret_cast<const char*>(&codeSize), sizeof(codeSize));
        file.write(pair.second.c_str(), codeSize);
    }

    file.close();
}

void HuffmanTree::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
        return;
    }

    clear();

    // Load the Huffman Tree structure
    size_t treeSize;
    file.read(reinterpret_cast<char*>(&treeSize), sizeof(treeSize));
    std::string treeStr(treeSize, ' ');
    file.read(&treeStr[0], treeSize);

    std::istringstream treeStream(treeStr);
    std::queue<Node**> q;
    q.push(&root);
    while (!q.empty()) {
        Node** current = q.front();
        q.pop();
        std::string token;
        treeStream >> token;
        if (token == "#") {
            *current = nullptr;
        } else {
            char ch = token[0];
            int freq;
            treeStream >> freq;
            *current = new Node(ch, freq);
            q.push(&(*current)->left);
            q.push(&(*current)->right);
        }
    }

    // Load the Huffman codes
    size_t mapSize;
    file.read(reinterpret_cast<char*>(&mapSize), sizeof(mapSize));
    for (size_t i = 0; i < mapSize; ++i) {
        char ch = file.get();
        size_t codeSize;
        file.read(reinterpret_cast<char*>(&codeSize), sizeof(codeSize));
        std::string code(codeSize, ' ');
        file.read(&code[0], codeSize);
        huffmanCode[ch] = code;
    }

    file.close();
}

