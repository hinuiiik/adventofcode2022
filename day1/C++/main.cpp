#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream input;
    input.open("../input");
    if(!input.is_open()) {
        cout << "nope" << endl;
        return 0;
    }

    int largest = 0;
    int current = 0;
    int second = 0;
    int third = 0;
    string line;

    while(getline(input,line)) {
        if (!line.empty()) {
            current+=stoi(line);
        }
        else {
            current = 0;
        }
        // imagine good code...
        if (current>second && current<largest) {
            third = second;
            second = current;
        }
        if (current>third && current<second) {
            third = current;
        }
        if (current>largest) {
            third = second;
            second = largest;
            largest = current;
        }
    }
    cout << "Largest: " << largest << endl << "2nd Place: " << second << endl << "3rd Place: " << third << endl;
    cout << "Combined: " << largest + second + third << endl;
    input.close();
    return 0;
}