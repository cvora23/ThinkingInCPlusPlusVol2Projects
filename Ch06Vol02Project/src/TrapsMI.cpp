/*
 * TrapsMI.cpp
 *
 *  Created on: Jul 25, 2014
 *      Author: cvora
 */
#include<iostream>

using namespace std;

class X{
public:
	X(){

	}
	X(int){

	}
	void f(){
		cout<<__PRETTY_FUNCTION__<<endl;
	}
};


class Y: virtual public X{
public:
	Y(int):X(0){

	}

};

class Z: virtual public X{
public:
	Z(int):X(0){
	}

};

class A:public Y,Z{
public:
	A():Y(0),Z(0){
	}
};

int main(){
	A a;
	//a.f();
	X* px = &a;
	px->f();
}


