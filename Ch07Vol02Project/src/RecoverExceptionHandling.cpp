/*
 * RecoverExceptionHandling.cpp
 *
 *  Created on: Jul 25, 2014
 *      Author: cvora
 */

#include <iostream>
#include <fstream>
#include <exception>
#include <cstring>
#include <cstdlib>
using namespace std;

class Noisy {
  static int i;
  int objnum;
  enum {sz = 40};
  char name[sz];

public:
  Noisy(const char* nm="array elem") throw(int){
    objnum = i++;
    memset(name, 0, sz);
    strncpy(name, nm, sz - 1);
    cout << "constructing Noisy " << objnum
      << " name [" << name << "]" << endl;
    if(objnum == 11) throw int(objnum);

  }
  ~Noisy() {
	  cout << "destructing Noisy " << objnum
      << " name [" << name << "]" << endl;
  }
  void* operator new[](size_t sz) {
	  cout << "Noisy::new[]" << endl;
    return ::new char[sz];
  }

  static void restoreMemory(void* p){
	  cout << "Restore memory" << endl;
	  ::delete []p;
	  i = 0;
  }
};

int Noisy::i = 0;

int main() {
	while(1){
		Noisy* array = NULL;
		try{
			array = new Noisy[12];
		}catch(int i){
			Noisy::restoreMemory(array);
			array = NULL;
			cout << "caught " << i << endl;
		}
	}

} ///:~




