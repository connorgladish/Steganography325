#include "Steganography.h"
#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

Steganography::Steganography()
    : magicNumber(""), width(0), height(0), maxColor(255) {}

// Helper method to get the nth bit from a character. 
int Steganography::getNthBit(char cipherChar, int n) const {
    return (cipherChar >> n) & 1;
}

// Read a PPM image file
void Steganography::readImage(const string &fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Error opening file: " << fileName << "\n";
        return;
    }

    inFile >> magicNumber >> width >> height >> maxColor;
    colorData.resize(width * height * 3);

    for (int &color : colorData) {
        inFile >> color;
    }

    inFile.close();
}

// Write a PPM image file
void Steganography::printImage(const string &fileName) {
    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Error opening file: " << fileName << "\n";
        return;
    }

    outFile << magicNumber << "\n" << width << " " << height << "\n" << maxColor << "\n";
    for (size_t i = 0; i < colorData.size(); ++i) {
        outFile << colorData[i] << " ";
        if ((i + 1) % (width * 3) == 0) outFile << "\n";
    }

    outFile.close();
}

// Read plain text file
void Steganography::readCipherText(const string &fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Error opening file: " << fileName << "\n";
        return;
    }

    getline(inFile, cipherText, '\0'); // Read entire file
    inFile.close();
}

// Write plain text file
void Steganography::printCipherText(const string &fileName) {
    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Error opening file: " << fileName << "\n";
        return;
    }

    outFile << cipherText;
    outFile.close();
}

// Zero out the LSB of each color value
void Steganography::cleanImage() {
    for (int &color : colorData) {
        color &= ~1; // Clear the least significant bit
    }
}

// Encode text into image data
void Steganography::encipher() {
    cleanImage(); // Ensure all LSBs are zero
    size_t bitIndex = 0;

    for (char ch : cipherText) {
        for (int i = 0; i < 8 && bitIndex < colorData.size(); ++i) {
            colorData[bitIndex] |= getNthBit(ch, i); // Set LSB to the nth bit of the character
            ++bitIndex;
        }
    }
}

// Decode text from image data
void Steganography::decipher() {
    cipherText.clear();
    char currentChar = 0;
    int bitCounter = 0;

    for (size_t i = 0; i < colorData.size(); ++i) {
        currentChar |= (colorData[i] & 1) << bitCounter; // Set bit in currentChar
        ++bitCounter;

        if (bitCounter == 8) { // 8 bits = 1 char
            cipherText += currentChar;
            currentChar = 0;
            bitCounter = 0;
        }
    }
}
