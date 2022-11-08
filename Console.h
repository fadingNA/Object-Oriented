//
// Created by Nonthachai Plodthong on 31/10/2022 AD.
//

#ifndef PRACTICE_2_CONSOLE_H
#define PRACTICE_2_CONSOLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ostream>
#include <utility>

using namespace std;

class Console {
private:
	string name{};
	string detail{};
	size_t cnt{};
public:
	Console();

	~Console();

	Console(string n, string detail);

	Console(std::istream &is);

	// Copy Move

	Console(const Console &tmp);

	Console(const Console &&tmp);

	// Assignment

	Console &operator=(const Console &object);

	Console &operator=(Console &&object);

	bool isNameValid(const string &source);

	const string &getName() const;

	const string &getDetail() const;

	bool changeName(const string &source);

	void display(std::ostream &os);

	template<typename T, typename F>
	T *cal(T *array, size_t cnt, F predicate) {
		if (predicate(array)) {
			array->push_back(cnt);
			return true;
		}else{
			return false;
		}
	}
};

#endif //PRACTICE_2_CONSOLE_H
