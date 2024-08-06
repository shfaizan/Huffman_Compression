# Huffman Encoding and Compression

This project implements Huffman Tree encoding and decoding for text compression in C++. The project includes the ability to build a Huffman Tree from a given text, encode the text into a compressed format, decode the compressed text back to the original text, and save/load the Huffman Tree structure and codes to/from a file.

## Features

- **Build Huffman Tree**: Construct a Huffman Tree based on the frequency of characters in the input text.
- **Encode Text**: Compress text using the Huffman codes.
- **Decode Text**: Decompress encoded text back to the original text.
- **Save to File**: Save the Huffman Tree structure and codes to a file for later use.
- **Load from File**: Load the Huffman Tree structure and codes from a file.

## Project Structure

- `HuffmanTree.h`: Header file for the Huffman Tree class.
- `HuffmanTree.cpp`: Implementation of the Huffman Tree class.
- `main.cpp`: Main driver code for the project.
- `Makefile`: Makefile to compile the project.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++)
- Make utility

### Building the Project

1. Clone the repository or download the project files.
2. Navigate to the project directory.
3. Run the following command to compile the project:

    ```sh
    make
    ```

### Running the Project

1. After building the project, run the executable:

    ```sh
    ./HuffmanCoding
    ```

2. Follow the on-screen instructions to encode/decode text and save/load Huffman Tree data.

### Example

```sh
$ ./HuffmanCoding
Encoded Text: 110011011011101110001110110011111010010110000110100110111011101011110011011011
Decoded Text: this is an example for huffman encoding
Decoded Text after loading from file: this is an example for huffman encoding
