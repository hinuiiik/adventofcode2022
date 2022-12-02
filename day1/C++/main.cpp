#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream input;
    input.open("../../input");
    if(!input.is_open()) {
        cout << "nope" << endl;
        return 0;
    }

    int largest = 0;
    int current = 0;
    string line;

    while(getline(input,line)) {
        if (!line.empty()) {
            current+=stoi(line);
        }
        else {
            current = 0;
        }
        if (current>largest) {
            largest = current;
        }
    }
    cout << "Largest: " << largest << endl;
    input.close();
    return 0;
}