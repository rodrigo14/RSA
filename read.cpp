#include <fstream>

using namespace std;

string readText(string file) {
	file = "io/" + file;
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
	file = "io/" + file;
	ofstream fout(file.c_str(), ios::app);
	fout << text << endl;
}

void writeTextOnFile(ZZ &text, string file) {
	file = "io/" + file;
	ofstream fout(file.c_str(), ios::app);
	fout << text << endl;
}