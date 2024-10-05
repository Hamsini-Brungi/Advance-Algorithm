#include <bits/stdc++.h>
using namespace std;


struct HuffmanNode {
    char symbol;
    int frequency;
    HuffmanNode *leftChild, *rightChild;

    HuffmanNode(char symbol, int frequency) : symbol(symbol), frequency(frequency), leftChild(nullptr), rightChild(nullptr) {}
};


struct FrequencyComparator {
    bool operator()(HuffmanNode* node1, HuffmanNode* node2) {
        return node1->frequency > node2->frequency;  // Min-heap based on frequency
    }
};

void generateHuffmanCodes(HuffmanNode* root, string currentCode, unordered_map<char, string>& codeTable) {
    if (!root) return;

    if (root->symbol != '#')  // Non-internal node
        codeTable[root->symbol] = currentCode;

    generateHuffmanCodes(root->leftChild, currentCode + "0", codeTable);
    generateHuffmanCodes(root->rightChild, currentCode + "1", codeTable);
}


unordered_map<char, string> createHuffmanTree(const string& symbols, const vector<int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, FrequencyComparator> minHeap;

    
    for (size_t i = 0; i < symbols.size(); ++i) {
        minHeap.push(new HuffmanNode(symbols[i], frequencies[i]));
    }

   
    while (minHeap.size() > 1) {
        HuffmanNode *leftNode = minHeap.top(); minHeap.pop();
        HuffmanNode *rightNode = minHeap.top(); minHeap.pop();

        HuffmanNode *parentNode = new HuffmanNode('#', leftNode->frequency + rightNode->frequency);
        parentNode->leftChild = leftNode;
        parentNode->rightChild = rightNode;
        minHeap.push(parentNode);
    }

    
    unordered_map<char, string> codeTable;
    generateHuffmanCodes(minHeap.top(), "", codeTable);

    return codeTable;
}


bool isValidCharSet(const string& input) {
    return all_of(input.begin(), input.end(), [](char ch) { return isalpha(ch); });
}

bool isValidFrequencyInput(const string& input, vector<int>& frequencyList, size_t expectedSize) {
    frequencyList.clear();
    stringstream freqStream(input);
    int freq;
    while (freqStream >> freq) {
        frequencyList.push_back(freq);
    }
    return frequencyList.size() == expectedSize;
}

int main() {
    string characterSet;
    vector<int> frequencies;
    size_t numSymbols;

    
    while (true) {
        cout << "Enter characters (distinct letters): ";
        cin >> characterSet;
        if (isValidCharSet(characterSet)) {
            break;
        } else {
            cout << "Invalid input. Please enter only alphabetic characters (e.g., 'abc')." << endl;
        }
    }

    numSymbols = characterSet.size();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

    
    while (true) {
        string freqInput;
        cout << "Enter frequencies (space-separated integers): ";
        getline(cin, freqInput);
        if (isValidFrequencyInput(freqInput, frequencies, numSymbols)) {
            break;
        } else {
            cout << "Invalid input. Please re-enter frequencies (e.g., '5 9 12 13 16 45')." << endl;
        }
    }

    
    unordered_map<char, string> huffmanCodes = createHuffmanTree(characterSet, frequencies);

   
    cout << "Huffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << "  " << pair.first << " : " << pair.second << endl;
    }

    
    vector<string> sortedCodes;
    for (char symbol : characterSet) {
        sortedCodes.push_back(huffmanCodes[symbol]);
    }
    sort(sortedCodes.begin(), sortedCodes.end());

    cout << "Sorted Huffman Codes: ";
    for (const string& code : sortedCodes) {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}
