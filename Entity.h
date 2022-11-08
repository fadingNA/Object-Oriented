//
// Created by Nonthachai Plodthong on 29/10/2022 AD.
//

#ifndef PRACTICE_2_ENTITY_H
#define PRACTICE_2_ENTITY_H

#include <iostream>
#include <string>

using namespace std;

class Entity {
	//TODO
	std::string firstName;
	std::string lastName;
	const char *inti;
	size_t height;
	double weight;
	double s{};
	size_t cnt{};
public:

	Entity();

	~Entity();

	Entity(double object);

	void display(const char *str) const;

	Entity(std::istream& is);
};




#endif //PRACTICE_2_ENTITY_H
