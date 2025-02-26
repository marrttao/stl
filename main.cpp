#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

void FindWord(map<string, string>& dictionary, string key) {
    // Function implementation
    cout << "The word is: " << dictionary.at(key) << endl;
}

void AddWord(map<string, string>& dictionary, string key, string value) {
    // EMPLACE
    dictionary.emplace(key, value);
}

void RemoveWord(map<string, string>& dictionary, string key) {
    // ERASE
    dictionary.erase(key);
}

void ReplacePair(map<string, string>& dictionary, string oldKey, string newKey, string newValue) {
    auto it = dictionary.find(oldKey);
    if (it != dictionary.end()) {
        dictionary.erase(it);
        dictionary.emplace(newKey, newValue);
    }
}



void PrintDictionary(map<string, string>& dictionary) {
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
}

void RewriteInFile(map<string, string>& dictionary) {
	ofstream file("dictionary.txt");
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it) {
		file << it->first << " : " << it->second << endl;
	}
	file.close();
}
void ReadFromFile(map<string, string>& dictionary) {
	ifstream file("dictionary.txt");
	string line;
	while (getline(file, line)) {
		string key = line.substr(0, line.find(" : "));
		string value = line.substr(line.find(" : ") + 3);
		dictionary.emplace(key, value);
	}
	file.close();
}

int main() {
    std::map<string, string> dictionary;

    // Read from file
    ReadFromFile(dictionary);
    cout << "Dictionary after reading from file:" << endl;
    PrintDictionary(dictionary);

    // Adding some words to the dictionary
    AddWord(dictionary, "apple", "A fruit");
    AddWord(dictionary, "banana", "Another fruit");
    AddWord(dictionary, "car", "A vehicle");

    // Printing the dictionary
    cout << "\nDictionary after adding words:" << endl;
    PrintDictionary(dictionary);

    // Finding a word in the dictionary
    cout << "\nFinding 'apple' in the dictionary:" << endl;
    FindWord(dictionary, "apple");

    // Replacing a word in the dictionary
    ReplacePair(dictionary, "banana", "yellow_banana", "A yellow fruit");
    cout << "\nDictionary after replacing 'banana':" << endl;
    PrintDictionary(dictionary);

    // Removing a word from the dictionary
    RemoveWord(dictionary, "car");
    cout << "\nDictionary after removing 'car':" << endl;
    PrintDictionary(dictionary);

    // Write to file
    RewriteInFile(dictionary);
    cout << "\nDictionary written to file." << endl;

	ReadFromFile(dictionary);

    return 0;
}

