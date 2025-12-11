#include "RLE.h"

std::vector<std::pair<char, int>> RLE::compress(const std::string &text)
{
    std::vector<std::pair<char, int>> compressedText;
    int count = 1;

    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == text[i + 1])
            count++;
        else
        {
            compressedText.push_back(std::make_pair(text[i], count));
            count = 1;
        }
    }

    return compressedText;
}

std::string RLE::decompress(const std::vector<std::pair<char, int>> &text)
{
    std::string decompressedText;
    for (const auto &pair : text)
        decompressedText.append(pair.second, pair.first);

    return decompressedText;
}

void RLE::saveFile(const std::string &filename, const std::vector<std::pair<char, int>> &text)
{
    std::ofstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        exit(1);
    }

    for (const auto &pair : text)
    {
        file.write(&pair.first, sizeof(pair.first));
        file.write(reinterpret_cast<const char *>(&pair.second), sizeof(pair.second));
    }

    file.close();
}

std::vector<std::pair<char, int>> RLE::loadFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        exit(1);
    }

    std::vector<std::pair<char, int>> compressedText;
    char ch;
    int count;

    while (file.read(&ch, sizeof(ch)))
    {
        file.read(reinterpret_cast<char *>(&count), sizeof(count));
        compressedText.push_back(std::make_pair(ch, count));
    }

    file.close();
    return compressedText;
}

std::string RLE::readFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        exit(1);
    }

    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return text;
}

void RLE::writeFile(const std::string &filename, const std::string &text)
{
    std::ofstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        exit(1);
    }

    file.write(text.c_str(), text.size());
    file.close();
}

void RLE::compressFile(const std::string &inputFilename, const std::string &outputFilename)
{
    std::string text = readFile(inputFilename);
    std::vector<std::pair<char, int>> compressed = compress(text);
    saveFile(outputFilename, compressed);
    std::cout << "Arquivo compactado com sucesso: " << outputFilename << std::endl;
}

void RLE::decompressFile(const std::string &inputFilename, const std::string &outputFilename)
{
    std::vector<std::pair<char, int>> compressed = loadFile(inputFilename);
    std::string decompressed = decompress(compressed);
    writeFile(outputFilename, decompressed);
    std::cout << "Arquivo descompactado com sucesso: " << outputFilename << std::endl;
}

// Implementação utilizando string

std::string RLE::compressString(const std::string &text)
{
    std::string compressedText;
    int count = 1;

    for (size_t i = 0; i < text.size(); i++)
    {
        if (text[i] == text[i + 1] && count < 9)
            count++;

        else
        {
            compressedText += text[i];
            compressedText += std::to_string(count);
            count = 1;
        }
    }

    return compressedText;
}

std::string RLE::decompressString(const std::string &text)
{
    std::string decompressedText;

    for (size_t i = 0; i < text.size();)
    {
        char ch = text[i++];
        std::string countStr;
        countStr += text[i++];

        int count = std::stoi(countStr);
        decompressedText.append(count, ch);
    }

    return decompressedText;
}

std::string RLE::readFileString(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        exit(1);
    }

    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return text;
}

void RLE::writeFileString(const std::string &filename, const std::string &text)
{
    std::ofstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        exit(1);
    }

    file.write(text.c_str(), text.size());
    file.close();
}

void RLE::compressFileString(const std::string &inputFilename, const std::string &outputFilename)
{
    std::string text = readFileString(inputFilename);
    std::string compressedText = compressString(text);
    writeFileString(outputFilename, compressedText);
    std::cout << "Arquivo compactado com sucesso: " << outputFilename << std::endl;
}

void RLE::decompressFileString(const std::string &inputFilename, const std::string &outputFilename)
{
    std::string compressedText = readFileString(inputFilename);
    std::string text = decompressString(compressedText);
    writeFileString(outputFilename, text);
    std::cout << "Arquivo descompactado com sucesso: " << outputFilename << std::endl;
}