#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void read(string location) {
	string fileName;
	ifstream File;
	string line;

	cout << location << endl;

	File.open(location);
	if (File.is_open()) {
		while (File.good()) {
			getline(File,line);
			cout << line << endl;
		}
	} else {
		cout << "unable to read file" << endl;
	}

	File.close();

}