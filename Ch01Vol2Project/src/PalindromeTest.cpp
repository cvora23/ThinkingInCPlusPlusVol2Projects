/*
 * PalindromeTest.cpp
 *
 *  Created on: Jul 14, 2014
 *      Author: cvora
 */

#include<iostream>
#include <string>

using namespace std;

bool checkPalindrome(string str){
	bool ans = true;
	string::reverse_iterator rev;
	string::iterator iter;
	for(rev = str.rbegin(),iter=str.begin();rev!=str.rend();rev++,iter++){
		if(*rev != *iter){
			ans = false;
			break;
		}
	}
	return ans;
}

int main(){
	cout<<checkPalindrome(string("madam"))<<endl;
	cout<<checkPalindrome(string("hello"))<<endl;
	cout<<checkPalindrome(string("wow"))<<endl;
	return 0;
}

