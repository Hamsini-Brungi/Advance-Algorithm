#include <iostream>
#include <vector>
#include <cctype>


void transformToUpper(std::string& str) {
    for (char& ch : str) {
        ch = std::toupper(ch);
    }
}


bool checkAlphabetic(const std::string& input) {
    for (const auto& ch : input) {
        if (!std::isalpha(ch)) {
            return false;
        }
    }
    return true;
}


std::string computeLCS(const std::string& str1, const std::string& str2, int& lcsLength) {
    int n1 = str1.size();
    int n2 = str2.size();
    

    std::vector<std::vector<int>> table(n1 + 1, std::vector<int>(n2 + 1, 0));
    lcsLength = 0;
    int endPos = 0;


    for (int col = 1; col <= n2; ++col) {
        for (int row = 1; row <= n1; ++row) {
            if (str1[row - 1] == str2[col - 1]) {
                table[row][col] = table[row - 1][col - 1] + 1;
                if (table[row][col] > lcsLength) {
                    lcsLength = table[row][col];
                    endPos = row;
                }
            }
        }
    }


    std::cout << "Table of Common Lengths:" << std::endl;
    for (const auto& row : table) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return str1.substr(endPos - lcsLength, lcsLength);
}

int main() {
    std::string strOne, strTwo;
    
    while (true) {
        std::cout << "Enter first string (type 'quit' to exit): ";
        std::cin >> strOne;
        if (strOne == "quit") break;

        std::cout << "Enter second string (type 'quit' to exit): ";
        std::cin >> strTwo;
        if (strTwo == "quit") break;

        if (!checkAlphabetic(strOne) || !checkAlphabetic(strTwo)) {
            std::cout << "Error: Both inputs must be alphabetic only." << std::endl;
            continue;
        }


        transformToUpper(strOne);
        transformToUpper(strTwo);

        int maxLCSLength;
        std::string lcs = computeLCS(strOne, strTwo, maxLCSLength);

        std::cout << "Longest Common Substring: " << lcs << std::endl;
        std::cout << "Length of LCS: " << maxLCSLength << std::endl;
    }

    return 0;
}
