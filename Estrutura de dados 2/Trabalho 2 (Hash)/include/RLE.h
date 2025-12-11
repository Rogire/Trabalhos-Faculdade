#ifndef RLE_H
#define RLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class RLE
{
private:
    std::vector<std::pair<char, int>> compress(const std::string &text);
    std::string decompress(const std::vector<std::pair<char, int>> &text);
    void saveFile(const std::string &filename, const std::vector<std::pair<char, int>> &text);
    std::vector<std::pair<char, int>> loadFile(const std::string &filename);

    std::string compressString(const std::string &text);
    std::string decompressString(const std::string &text);
    std::string readFileString(const std::string &filename);
    void writeFileString(const std::string &filename, const std::string &text);

public:
    void compressFile(const std::string &inputFilename, const std::string &outputFilename);
    void decompressFile(const std::string &inputFilename, const std::string &outputFilename);
    std::string readFile(const std::string &filename);
    void writeFile(const std::string &filename, const std::string &text);

    void compressFileString(const std::string &inputFilename, const std::string &outputFilename);
    void decompressFileString(const std::string &inputFilename, const std::string &outputFilename);
};

#endif