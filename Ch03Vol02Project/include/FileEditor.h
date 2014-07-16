/*
 * FileEditor.h
 *
 *  Created on: Jul 16, 2014
 *      Author: cvora
 */
// A file editor tool.

#ifndef FILEEDITOR_H
#define FILEEDITOR_H
#include <iostream>
#include <string>
#include <vector>

template<typename T>
class FileEditor : public std::vector<T> {
	public:
	void write(std::ostream& out = std::cout) ;
	FileEditor() {};
	private:
	typedef std::vector< T > VectorType;
	typedef typename VectorType::iterator VectorIterator;
};
#endif // FILEEDITOR_H ///:~

template<typename T>
void FileEditor<T>::write(std::ostream& out) {
	 for(VectorIterator w = this->begin(); w != this->end(); w++)
		 out << *w;
}
