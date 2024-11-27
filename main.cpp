#include "Steganography.h"
#include <iostream>
using namespace std;

int main() {
    Steganography stego;
    int choice;
    string inputImage, textFile, outputImage;

    cout << "Choose an option:\n1. Encode\n2. Decode\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter input PPM file: ";
        cin >> inputImage;
        cout << "Enter text file to encode: ";
        cin >> textFile;
        cout << "Enter output encoded PPM file: ";
        cin >> outputImage;

        stego.readImage(inputImage);
        stego.readCipherText(textFile);
        stego.encipher();
        stego.printImage(outputImage);

        cout << "Image encoded successfully.\n";
    } else if (choice == 2) {
        cout << "Enter encoded PPM file: ";
        cin >> inputImage;
        cout << "Enter output text file: ";
        cin >> textFile;

        stego.readImage(inputImage);
        stego.decipher();
        stego.printCipherText(textFile);

        cout << "Message decoded successfully.\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
