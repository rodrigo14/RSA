#ifndef READ_H
#define READ_H

#include <NTL/ZZ.h>
#include <fstream>

using std::string;
using namespace NTL;

extern string readText(string file);
extern void writeTextOnFile(string text, string file, bool append=1);
extern void writeTextOnFile(ZZ &text, string file, bool append=1);
extern void clear_files();

#endif
