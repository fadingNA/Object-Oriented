//
// Created by Nonthachai Plodthong on 4/11/2022 AD.
//

#ifndef PRACTICE_2_FOO_H
#define PRACTICE_2_FOO_H

#include <iostream>
#include <iomanip>

using namespace std;

struct Storage {
	string game;
	string cd;
};

class Foo {
private:

	float num1{};
	float num2{};
	std::string array;

	// Static Variable
	static size_t m_intcnt;
public:
	static decltype(auto) checkRange(float num1 = 10, float num2 = 20) {
		return num1 + num2;
	}

	Foo();

	bool operator()(float first, float second) {
		float sum = checkRange(first, second);
		if (sum >= 10 && sum <= 20) {
			std::cout << std::setprecision(1) << std::fixed << sum;
			return true;
		}
		std::cout << "Your summary not in range" << std::endl;
		std::cout << std::setprecision(1) << std::fixed << sum;
		return false;
	}

//	template<typename T>
//	bool operator==(const T val1, T &val2) {
//		if (val1 == val2) {
//			return true;
//		}
//		return false;
//	}

	template<typename T>
	bool exist(const T array[], size_t cnt, T &val) {
		for (size_t i = 0; i < cnt; ++i) {
			if (array[i] == val) {
				return true;
			}
		}
		return false;
	}

//	template<>
//	bool exist(const string array, string &val) {
//		for (int i = 0; i < array.length(); ++i) {
//			if (array == val) {
//				return true;
//			}
//		}
//		return false;
//	}
};

#endif //PRACTICE_2_FOO_H
