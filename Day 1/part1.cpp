#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*     SOLVED     */

void solve (string filename) {
    string line;
    ifstream file (filename);

    if (file.is_open()) {
        int lastLineDepth = 0;
        int largerThanPrevCounter = 0;

        while (getline(file, line)) {
            if (lastLineDepth != 0 && stoi(line) > lastLineDepth) {
                largerThanPrevCounter += 1;
            }
            lastLineDepth = stoi(line);
        }

        file.close();
        cout << "largerThanPrevCounter = " << largerThanPrevCounter << endl;
    }
    else cout << "Failed to open file \'" << filename << "\'..."; 
}

int main(void) {
    solve("day1.txt");
    return 0;
}
