#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <string>
#include <vector>
using namespace std;

class Steganography {
private:
    string magicNumber;  // e.g., "P3"
    int width;                // Image width
    int height;               // Image height
    int maxColor;             // Max color value
    vector<int> colorData;  // Flattened RGB 
    string cipherText;      // Text to encode or decode

    // Helper method to get the nth bit from a character
    int getNthBit(char cipherChar, int n) const;

public:
    // Constructor
    Steganography();

    // File operations
    void readImage(const string &fileName);
    void printImage(const string &fileName);
    void readCipherText(const string &fileName);
    void printCipherText(const string &fileName);

    // Image modifications
    void cleanImage(); // Zero out LSBs of all color data
    void encipher();   // Encode text into the image
    void decipher();   // Decode text from the image
};

#endif // STEGANOGRAPHY_H
