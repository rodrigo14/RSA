#include "read.h"

using namespace std;

const string directory_files = "files/";

string readText(string file) {
	file = directory_files + file;
	ifstream fin(file.c_str());
	if (not fin.is_open()) {
		return "";
	}

	string line, text;
	getline(fin, line);
	text += line;

    return text;
}

void writeTextOnFile(string text, string file, bool append) {
	file = directory_files + file;
	if (append) {
		ofstream fout(file.c_str(), ios::app);
		fout << text << endl;
	} else {
		ofstream fout(file.c_str());
		fout << text << endl;
	}
}

void writeTextOnFile(ZZ &text, string file, bool append) {
	file = directory_files + file;
	if (append) {
		ofstream fout(file.c_str(), ios::app);
		fout << text << endl;
	} else {
		ofstream fout(file.c_str());
		fout << text << endl;
	}

}

void clear_files() {
	system("rm -f cipher.txt");
	system("rm -f decipher.txt");
}
