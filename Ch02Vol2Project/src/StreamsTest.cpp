/*
 * StreamsTest.cpp
 *
 *  Created on: Jul 15, 2014
 *      Author: cvora
 */

#include <iostream>
#include <fstream>      // std::ifstream
#include <strstream>
#include "require.h"

using namespace std;

// Make an uppercase copy of s:
string upperCase(string& s) {
  char* buf = new char[s.length()];
  s.copy(buf, s.length());
  for(unsigned int i = 0; i < s.length(); i++)
    buf[i] = toupper(buf[i]);
  string r(buf, s.length());
  delete buf;
  return r;
}


int main(){
	ifstream in("IostreamsNotes.txt",std::ifstream::in);
	assure(in,"IostreamsNotes.txt");
//	cout << in.rdbuf(); // Print whole file
	ostrstream os;
	os<<in.rdbuf();
	//cout <<os.rdbuf();
	char* old = os.str(); // Freezes s
	string newStr(old);
	newStr = upperCase(newStr);
	cout<<newStr<<endl;
	ofstream out("IostreamsNotesCaps.txt",std::ifstream::out);
	out<<newStr;
	delete os.str(); // Release storage
	return 0;
}


