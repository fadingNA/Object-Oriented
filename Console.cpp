//
// Created by Nonthachai Plodthong on 31/10/2022 AD.
//

#include "Console.h"



Console::Console() = default;

Console::~Console() = default;

Console::Console(string n, string detail) : name(std::move(n)), detail(std::move(detail)) {
}

Console::Console(std::istream &is) {
	string tmp;
	size_t pos;


	{

	}


}

// Copy Move

Console::Console(const Console &tmp) {
  if(this != &tmp){

  }
}

Console::Console(const Console &&tmp) {

}

// Assignment

Console &Console::operator=(const Console &object) {

}

Console &Console::operator=(Console &&object) {

}

bool Console::isNameValid(const string &source) {

}

bool Console::changeName(const string &source) {
	//auto count = std::count(name.begin(), name.end(), source);
	int count;
	if (count) {
		return false;
	} else {
		//std::copy(source.begin(), source.end(), name.begin());
		for (auto i: name) {
			cout << "THIS IS NEW NAME[" << i << "]" << endl;
		}
	}
}

const string &Console::getName() const {
	return this->name;
}

const string &Console::getDetail() const {
	return this->detail;
}

void Console::display(std::ostream &os) {
	os << "NAME OF CONSOLE : [" << this->name << "]" << endl;
	os << "Deatail OF CONSOLE : [" << this->getDetail()
	   << "]" << endl;
}
