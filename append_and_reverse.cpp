#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to reverse the contents of a file
void reverseFileContents(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return;
    }

    if (!outFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return;
    }

    string fileContent((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());

    // Reverse the content of the file
    reverse(fileContent.begin(), fileContent.end());

    // Write the reversed content to the new file
    outFile << fileContent;

    inFile.close();
    outFile.close();
}

int main() {
    string userInput;
    string inputFileName = "CSC450_CT5_mod5.txt";
    string reversedFileName = "CSC450-mod5-reverse.txt";

    // Open the file in append mode
    ofstream outFile(inputFileName, ios::app);
    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Get user input
    cout << "Enter the text to append to the file: ";
    getline(cin, userInput);

    // Append the user input to the file
    outFile << userInput << endl;

    // Close the file
    outFile.close();

    // Call function to reverse file contents and save to a new file
    reverseFileContents(inputFileName, reversedFileName);

    cout << "User input appended and file reversed successfully." << endl;

    return 0;
}



