//
// Created by Nonthachai Plodthong on 29/10/2022 AD.
//
#include "Entity.h"

using namespace std;

Entity::Entity() {
	//std::cout << "Call Con" << endl;
}

Entity::Entity(double object) {
	s = object;
}

Entity::Entity(std::istream& is) {
	std::string read;
	//intitial
	std::string::iterator c = remove(read.begin(),read.end(),' ');
	getline(is,read,',');
	{
		read.erase(c,read.end());
		inti = read.c_str();
	}
	getline(is,read,',');
	{
		read.erase(c,read.end());
		firstName = read;
	}
	getline(is,read,',');
	{
		read.erase(c,read.end());
		lastName = read;
	}
	getline(is,read,',');
	{
		read.erase(c,read.end());
		this->height = stoi(read);
	}
	getline(is,read,',');
	{
		read.erase(c,read.end());
		this->weight = stod(read);
	}
}

Entity::~Entity() {
	//std::cout << "Call Des" << endl;
}

void Entity::display(const char *str) const {
	cout << "Call display : R OR L VALUE[" << str << "]" << s << endl;
}
