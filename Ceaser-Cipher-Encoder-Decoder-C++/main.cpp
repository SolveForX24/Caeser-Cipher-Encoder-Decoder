/*
 * Caeser Cipher Encoder/Decoder
 * Uses C++ console error trapping code by mweir-mcst (https://github.com/mweir-mcst)
 */

// Includes, namespace, function defines
#include <iostream>
#include <string>
#include <algorithm>

#include "console.h"

using namespace std;

string encode(string, int);

int main() {

    bool running = true;
    string code;
    int shift, menuChoice;

    cout << "Caeser Cipher Encoder / Decoder\n\n";

    do {
        cout << "1) Encode\n2) Decode\n3) Exit\n";
        menuChoice = prompt_int_min_max("Please enter your choice: ", 1, 3);
        switch (menuChoice) {
            case 1:

                // Gets string to encode
                cout << "Please enter the string to be encoded: ";
                getline(cin, code);

                // Gets shift
                shift = prompt_int_min_max("Please enter the shift (1 to 26, inclusive): ", 1, 26);
                //cout << "Got shift: " << shift << endl;

                // Runs encoder
                cout <<  "\nEncoded: " << encode(code, shift) << "\n\n";
                break;
            case 2:

                // Gets string to decode
                cout << "Please enter the string to be decoded: ";
                getline(cin, code);

                cout << endl;

                // Loops through and shows the given string shifted from 1 to 25.
                for (int i = 1; i <= 25; i++) {
                    cout << "Decoded with a shift of " << i << ": " << encode(code, i) << "\n";
                }

                cout << endl << "Please look through the shifted versions of the code to find the one that works best.\n";
                break;
            case 3:
                running = false;
            default:
                break;
        }
    } while (running == true);
    cout << "Thank you!";

    return 0;
}

string encode(string start, int shift) {

    // Variable setup
    string encoded;
    char currentChar, shiftedChar;
    int charAscii;

    // Loop through the string supplied by user
    for (int i = 0; i < start.length(); i++) {

        // Get char's ASCII number
        //cout << "At char " << i << "; " << start[i] << endl;
        currentChar = start[i];
        //cout << "currentChar: " << currentChar << endl;
        charAscii = currentChar;

        //cout << "charAscii: " << charAscii << endl;

       // Checks if the character supplied was uppercase or not a letter, then shifts the ASCII or returns it's initial self. Else, it's lowercase.
        if (charAscii >= 65 && charAscii <= 90) {
            charAscii += shift;
            if (charAscii > 90) {
                charAscii -= 26;
            }
            //cout << "charAscii was capital: " << charAscii << endl;
        } else if (charAscii < 97 || charAscii > 122) {
            shiftedChar = currentChar;
            //cout << "Not a letter, shiftedChar: " << shiftedChar << endl;
            encoded.push_back(shiftedChar);
            //cout << "encoded Current: " << encoded << endl;
            continue;
        } else {
            // Shift the ASCII if lowercase
            charAscii += shift;
            if (charAscii > 122) {
                charAscii -= 26;
            }
        }

        //cout << "shifted charAscii: " << charAscii << endl;

        // Turn into char, append it to encoded string
        shiftedChar = char(charAscii);
        //cout << "shiftedChar: " << shiftedChar << endl;

        encoded.push_back(shiftedChar);
        //cout << "encoded Current: " << encoded << endl;

    }

    return encoded;

}