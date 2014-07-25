/*
 * SimpleExceptionsExample.cpp
 *
 *  Created on: Jul 25, 2014
 *      Author: cvora
 */
#include <iostream>
#include <string>

class Class1{
public:
	Class1(){

	}

	class Exception1{
	private:
		std::string description;
	public:
		Exception1(const std::string& description){
			this->description = description;
		}
		std::string getDescription(){
			return description;
		}
	};

	void f()throw (Exception1) {
		throw Exception1(std::string("Hello world"));
	}

};


int main(){

	Class1 class1;
	try{
		class1.f();
	}catch(Class1::Exception1 &e){
		std::cout<<e.getDescription()<<std::endl;
	}

}


