/*
 * UrandTemplateTest.cpp
 *
 *  Created on: Jul 15, 2014
 *      Author: cvora
 */
#include<iostream>
#include"Urand.h"

using namespace std;

int main(){

	Urand<1000>myUrand;
	for(unsigned int i=0;i<50;i++){
		cout<<myUrand()<<endl;
	}
	return 0;
}



