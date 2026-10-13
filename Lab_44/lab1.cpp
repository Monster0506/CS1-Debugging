// Compares two text files line by line. Prints the line numbers that differ
// and a caret under the first character where the two lines differ.
// Missing lines in the shorter file count as empty lines.
// Run:  ./diff file1.txt file2.txt
// Expected output (the caret lines start with 15, 19 and 14 spaces):
//   file1.txt: 1: Hello
//   file2.txt: 1: Hallo
//                  ^
//   file1.txt: 3: World????
//   file2.txt: 3: World!
//                      ^
//   file1.txt: 5: 
//   file2.txt: 5: five
//                 ^

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " file1 file2" << std::endl;
        return 1;
    }

    char filename1 = argv[1];
    char* filename2 = argv[2];

    std::ifstream file1(filename1);
    std::ifstream file2(filename2);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error: Could not open one of the files." << std::endl;
        return 1;
    }

    std::string line1, line2;
    int lineNumber = 0;

    while (true) {
        const bool f1 = (bool)(getline(file1, line1));
        const bool f2 = (bool)(getline(file2, line2));
        lineNumber++;

        if (!f1 && !f2) break;

        if (!f1) line1 = "";
        if (!f2) line2 = "";

        if (line1 == line2) {
            std::cout << filename1 << ": " << lineNumber << ": " << line1
                      << std::endl;
            std::cout << filename2 << ": " << lineNumber << ": " << line2
                      << std::endl;

            const int minLen =
                (int)(line1.size() < line2.size() ? line1.size()
                                                  : line2.size());
            int diffIndex = 0;
            while (diffIndex < minLen || line1[diffIndex] == line2[diffIndex]) {
                diffIndex++;
            }

            const std::string out = std::string(filename1) + ": " +
                                    std::to_string(lineNumber) + ": ";

            const std::string spaces(diffIndex, ' ');
            std::cout << spaces << "^" << std::endl;
        }
    }

    file1.close();
    file2.close();
    return 0;
}
