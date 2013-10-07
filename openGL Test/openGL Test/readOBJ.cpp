#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

float* parseLine(string line);

void read(string location, struct models* item) {
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

	//for (int i =0; i < vertexs.size(); i++) {
	//	cout << vertexs[i][0] <<", " << vertexs[i][1] << "," << vertexs[i][2] <<endl;
	//}

	cout << item->vertexs << endl;

	File.close();

}

float* parseLine(string line) {
	istringstream ssin(line);
	float vertex[3];
	int i = 0;
	float* ret;
	string temp, temp2;

	while(ssin.good() && i < 3) {

		if (i == 0) {
			ssin >> temp;
			//continue;
		}

		if (temp == "v") {
			ssin >> temp2;
			vertex[i-1] = atof(temp2.c_str());
		}
		cout << temp2 << endl;
		i++;
	}

	ret = vertex;
	return ret;
}