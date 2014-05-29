#include <fstream>

using namespace std;

const string directory_files = "files/";

string readText(string file) {
	file = directory_files + file;
	ifstream fin(file.c_str());
	if (!fin.is_open()) {
		return "";
	}

	string line, text;
	getline(fin, line);
	text += line;

    return text;
}

void writeTextOnFile(string text, string file) {
	file = directory_files + file;
	ofstream fout(file.c_str(), ios::app);
	fout << text << endl;
}

void writeTextOnFile(ZZ &text, string file) {
	file = directory_files + file;
	ofstream fout(file.c_str(), ios::app);
	fout << text << endl;
}