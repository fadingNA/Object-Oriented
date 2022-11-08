// Functional - function wrapper
// function_wrapper.cpp

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <array>
#include <list>
#include <memory>
#include <fstream>
#include "Entity.h"
#include <istream>
#include <numeric>
#include "Console.h"
#include "Console.h"
#include "Time.h"
#include "Time.h"
#include <thread>
#include <forward_list>
//#include "Foo.h"
//Wrapper Class Templates​
//The wrapper class templates are templates that manage access to some underlying object. These templates include:
//
//function - creates a function-object wrapper for a function, another function-object or a lambda expression
//reference_wrapper - creates a reference object
//std::function Wrapper Template
//The program below creates 3 function objects: one for the function multiply(),
// one for the functor Multiply, and one for a lambda expression that performs a multiply operation.

// a simple function
int &GetValue() {
	static int value = 20;
	return value;
}

void print(const Entity &a) { a.display("lvalue "); }

void print(Entity &&a) {
	a.display("rvalue ");
}

void prints(const char *&&k) {
	std::cout << k << "I am R value" << std::endl;

}

void task(const std::string &str) {
	std::cout << str + " says Hi\n" + " this L Value\n";
}

void task(const std::string &&str) {
	std::cout << str + " says Hi\n" + " This R Value\n";
}

void prints(const char *&k) {
	std::cout << k << "I am L value" << std::endl;
}

void printName(const std::string &&k) {
	std::string tmp;
	std::cout << k << "I am R value" << std::endl;
	throw "This is R Value";
}

void printName(const std::string &k) {
	std::cout << k << "I am L value" << std::endl;
}

long multiply(long x, long y) { return x * y; }

void increment(int &x, int &y) { ++x, ++y; }

double check(double check1, double check2) {
	if (check1 > check2) {
		std::cout << "AAA" << std::endl;
		throw check1;
	} else {
		std::cout << "BBB" << std::endl;
		throw check2 && "invaid";
	}
	return check1;
}


int add(int x, int y) {
	x += y;
	std::cout << "[" << x << "]" << std::endl;
	return x;
}

//bool all_of(InputIterator f, InputIterator l, Fn predicate) {
//
//}

// a functor
struct Multiply {
	long operator()(long x, long y) { return x * y; }
};

int main() {

	// spawn child thread t1

	// continue executing main thread

	// synchronize - IMPORTANT!

	//TODO thread - lasts the lifetime of the thread - use keyword thread_local
	sdds::Timer test;

	thread_local Console value1;

	thread_local Console value2;

	thread_local Console value3;

	//เรียกฟังชั่นปกติ

	std::function<double(double, double)> f1 = multiply;
	//เรียก Functor
	std::function<char(long, long)> f2 = Multiply();
	// เรียน แรมด้า function;
	std::function<int(long, long)> f3 = [](long x, long y) {
		return x * y;
	};
	std::function<int(int, int)> add1 = add;
	std::function<int(int, int)> add12 = [](int x, int y) {
		return x + y;
	};
	// หลังจากเรียกต้องใส่ตัวแปร ในวงเลบด้วย
	std::cout << "f1(10, 2) = " << f1(10.2992, 2) << std::endl;
	std::cout << "f2(10, 2) = " << f2(10, 2) << std::endl;
	std::cout << "f3(10, 2) = " << f3(static_cast<long>(10.575), 2) << std::endl;
	std::cout << "add1 = " << add1(20, 30) << std::endl;
	std::cout << "add12 = " << add12(20, 'k') << std::endl;
	// block scope for reference

	std::deque<int> kko({30, 30, 30, 30, 20, 20});
	int cc = count(kko.begin(), kko.end(), 30);
	cout << " " << cc << " " << endl;
	std::vector<int> kko2(cc);

	copy(kko.begin(), kko.end(), kko2.begin());

	for (auto y: kko2) {
		cout << " Vector Copy[ " << y << " ]" << endl;
	}

	string str("Nonthachai");
	str += '\0';
	str += "Plodthong";
	int i = 0;
	for (const auto &c: str) {
		if (str[i++] == '\0') {
			cout << "Null byte at str[" << i - 1 << "]\n";
		}
	}
	cout << "[" << str << "]\n";

//	{
//		test.start();
//		using namespace std;
//		vector<double> original({5, 6, 8, 9, 7, 9, 7});
//		// vector<ref_wrapper<variable>> name(being , end);
//		vector<reference_wrapper<double>> ref(original.begin(), original.end());
//		for (auto i: original) {
//			// R Value
//			// or can use i *= 3;
//			cout << "Original value : [ " << (i = i * 3) << "]" << endl;
//			print(i);
//		}
//		//std::reference_wrapper can be used anywhere a regular reference can be used.
//		for (auto e: ref) {
//			// R value
//			e *= 3;
//			cout << "Ref value : [ " << e << " ]" << endl;
//
//		}
//		test.stop();
//		cout << "TIME : " << test.stop() << endl;
//	}
//	{
//		//TODO Test Reference Wrapper
//		long v1 = 1l, v2 = 2l, v3 = 3l;
//
//		vector<double> test(5, 100.5);
//		test.push_back(300);
//		test.insert(test.begin(), 2, 500);
//		// เพิ่มจำนวนไซส์ด้วย จาก 5 เป็น 7
//		test.pop_back();
//		// parameter insert , ตัวเริ่ม , กี่ครั้ง , จำนวนอะไร
//		std::reference_wrapper<long> r1 = v1;
//		// reference wrapper จะอยุ่ตรงไหนก็เปลี่ยค่าได้
//		std::reference_wrapper<long> r2 = v2;
//
//		std::reference_wrapper<long> r3 = v3;
//
//		v1 = 30, v2 = 30, v3 = 44;
//
//		for (auto i: test) {
//			cout << "test vector insert[" << i << endl;
//		}
//
//		std::cout << "r1 = " << r1 << std::endl;
//		std::cout << "r2 = " << r2 << std::endl;
//		std::cout << "r3 = " << r3 << std::endl;
//
//		v1 = 22, v2 = 23, v3 = 24;
//		std::cout << "AFTER :" << endl;
//		std::cout << "r1 = " << r1 << std::endl;
//		std::cout << "r2 = " << r2 << std::endl;
//		std::cout << "r3 = " << r3 << std::endl;
//
//
//	}
//	{
//		using namespace std;
//		long v1 = 1L, v2 = 2L, v3 = 3L;
//		std::reference_wrapper<long> r1 = v1;
//		std::reference_wrapper<long> r2 = v2;
//		std::reference_wrapper<long> r3 = v3;
//		string hi = "Hello World";
//		try {
//			cout << "String before manipulate : [ " << hi << "]" << endl;
//			string::iterator it = remove(hi.begin(), hi.end(), 'l');
//			hi.erase(it, hi.end());
//			char hi2 = 'l';
//			if (hi.at(hi.find_first_of('r'))) {
//				hi.push_back('l');
//			}
//			cout << "String after manipulate : [ " << hi << "]" << endl;
//			int a = 20, b = 50;
//			auto inc = bind(increment, ref(a), ref(b));
//			inc();
//			cout << "Increment wrapper = " << a << endl;
//			cout << "Increment wrapper = " << b << endl;
//			std::function<double(double, double)> checkFunctionWrapper = check;
//			std::cout << "Function Wrapper = " << checkFunctionWrapper(31, 36.6) << std::endl;
//
//		} catch (const char *msg) {
//			cout << msg << endl;
//		} catch (...) {
//			cout << "Invalid" << endl;
//		}
//
//		cout << "This is ref wrapper ; [ " << r1 << "]" << endl;
//		cout << "This is ref wrapper ; [ " << r2 << "}" << endl;
//		cout << "This is ref wrapper ; [ " << r3 << "}" << endl;
////block scope ARRAY#
//		{
//			std::array<std::string, 5> a = {"Nonthachai", "Honda", "Aom", "canada", " "};
//
//			//string kk = reinterpret_cast<const char *>(std::count(a.begin(), a.end(), "aa"));
//
//			std::array<int, 11> aa = {1, 12, 4, 5, 8, 9, 12, 13, 16, 18, 12};
//
//			int n = std::count(aa.begin(), aa.end(), 12);
//			int n1 = std::count(a.begin(), a.end(), "Nonthachai");
//
//			std::cout << "12 occurs " << n << " times.\n";
//			std::cout << "'aa' occurs " << n1 << " times.\n";
//
//			// COUNT IF
//			std::list<std::string> str = {"Non", "Aom", "Magnum", "Mom", "Dad", "OOP", "PASS", "Non", "NON"};
//			int count1 = std::count(str.begin(), str.end(), "Non");
//
//			std::vector<double> d1(4, 202.2);
//			std::vector<double> d2(4, 3.2);
//
//			std::copy(d1.begin(), d1.begin() + 4, d2.begin() + 2);
//			// ตัวเริ่ม , จำนวนที่จะ copy , จำนวนที่จะใส่ลงไป d2.begin +2 หมายถึง สอง ตำแหน่ง
//
//			for (auto &x: d2) {
//				cout << "Copy Value : {" << x << "}\n";
//			}
//
//			//std::cout << "Non occurs" << &str << " times\n";
//			cout << count1 << "\n";
//			for (auto &i: str) {
//				cout << "value of str :[" << i << "]\n";
//
//			}
//			str.pop_back();
//			cout << "[DELETE PASS] is Last value\n";
//			for (auto &i: str) {
//				cout << "value of str :[" << i << "]\n";
//			}
//		}
//
//	}//block scope # 2
//
//	// ถ้าเกิดใส่ & ไว้ข้างหน้า r1 - r3 จะปริ้น memory address ออกมาแทน
//
////bit_and - result of x & y
//// bit_and = ตัวแปร & ตัวแปร
////bit_or - result of x | y
////bit_xor - result of x ^ y
////divides - result of x / y
////equal_to - result of x == y
////greater - result of x > y
////greater_equal - result of x >= y
////less - result of x < y
////less_equal - result of x <= y
////logical_and - result of x && y
////logical_or - result of x || y
////minus - result of x - y
////multiplies - result of x * y
////negate - result of -x
////not_equal - result of x != y
////plus - result of x + y
//
//	{
//		using namespace std;
//		double i = 202.2;
//		Entity lvalue(30.2);
//		std::unique_ptr<Entity> en(new Entity); // smart_pointer // cannot copy
//
//		print(lvalue); // L value ออฟเจค จะเป็น L Value
//		//normal object = L value
//		print(*en); // L value สมาทพ้อยเตอร์ จะเปน L Value
//		//pointer = L value
//		std::shared_ptr<Entity> shareEn(new Entity);
//		print(*shareEn);
//		//pointer = L value
//		cout << "[Test Move with Share Pointer]" << endl;
//		cout << "[";
//
//		lvalue = *shareEn;
//		print(lvalue);
//		// spawn child thread t1
//		std::thread t1;
//		std::thread t2;
//		// spawn child thread t2
//
//
//
//		double x = i;
//		double &k = i;
//		std::vector<double> itr(3, 4040);
//		print(k);
//		print(x);
//		print(i);
//		int ii = 10;
//		int a = ii;
//		const int kk = 02;
//		int xds = GetValue();
//		Entity lvalus(00.2);
//		print(kk);
//		print(a);
//		print(lvalus);
//		print(ii);
//		static int value = 10;
//		std::cout << "===============" << std::endl;
//		const char *ss = {"hello world"};
//		char xx[] = {'2', '3', '\0'};
//
//
//		prints(ss);
//		prints(xx);
//		const int &dsko = 50;
//		print(6);
//		cout << "Value [ :";
//		print(dsko);
//		cout << "]" << endl;
//		cout << "Value [ :";
//		print(value);
//		value = std::move(dsko);
//		print(value);
//		cout << "]" << endl;
//		for (char &i: xx) {
//			prints(&i);
//		}
//		std::cout << "===============" << std::endl;
//		string firstName = "Non ";
//		string lastName = "Plodthong ";
//		string fullname = firstName + lastName;
//		int kkk = GetValue();
//		try {
//			string input;
//			std::cin >> input;
//			printName(input);
//			GetValue() = 20;
//			print(kkk);
//			printName(fullname);
//			printName(firstName);
//			printName(lastName);
//			printName(lastName + firstName);
//
//		} catch (const char *msg) {
//			cout << msg << endl;
//		} catch (...) {
//			cout << "Invalid Type" << endl;
//		}
//
//		std::cout << "===============" << std::endl;
//	}
//	// 30/OCT/2022 FLIE
//	{
//		std::ifstream is("test.txt");
//		std::fstream f("test.txt", std::ios::in | std::ios::out | std::ios::trunc);
//		if (f.is_open()) {
//			f << "Nonthachai Plodthong\n";
//			f << "Porrutai Ridtinontachai\n";
//			f << "152487211,##221\n";
//			f.seekg(0, std::ios_base::beg); //  เริ่มจากตัวแรก N < Onthachai Plodthong
//			f << "P";
//			f.seekg(-8, std::ios_base::end);
//			f << "Urai";
//			f.seekp(0); // save current which is i
//			char c;
//			std::cout << "File Data >";
//			while (f.get(c)) {
//				std::cout << "[" << c << "]";
//			}
//		}
//	}
//	Entity as;
//	{
//		int i = 10;
//		//TODO ios::in | ios::out open for reading and writing (default)
//		//TODO ios::in | ios::out | ios::trunc open for reading and overwriting
//		//TODO ios::in | ios::out | ios::app open for reading and appending
//		//TODO ios::out | ios::trunc open for overwriting
//		//TODO output stream Themember function for accessing a byte within an output stream are
//		//TODO streampos tellp = return to current position in the output stream
//		//TODO ostream& seekp = sets the current position in the output stream to pos เซตตำแหน่งที่อยู่ปัจจุบัน
//		//TODO streampos tellg = แตกต่างจาก tellp เพราะย้อนกลับไปตำแห่นงที่ถุกป้อนข้อมูลไว้ไม่ใช่ แสดงข้อมูลออกมา เหมือน tellp
//		//TODO ตัวอย่างของ wios ของ template basic_ios กำหนดคลาสมาตราฐานสำหรับ  INPUT & OUTPUT ในตระกูล char
//
//		std::ifstream op("practiceToken.txt", std::ios::in | std::ios::out);
//
//		std::ifstream for_read_for_write("....text", wios::in | wios::out);// open for reading and writing  = default
//
//		std::ifstream for_read_for_overwriting("....text", wios::in | wios::trunc);// open for reading and overwriting
//
//		//TODO APPEND = เพิ่มเติม // TODO TRUNC (truncate) = แปลว่า ตัดเพิ่มเติม
//
//		std::ifstream for_read_for_append("....text",
//		                                  wios::in | wios::out | wios::app);// open for reading and overwriting
//
//		std::ifstream OVERWRITING("....text", wios::out | wios::trunc);//wios::out | wios::trunc open for overwriting
//
//
//		//while( i < getline(op,as))
//
//		//an *lvalue reference* - denoted by &
//		/*An lvalue reference requires an initializer unless it
//
//		has external linkage
//		is a class member within a class definition
//		is a function parameter or a function return type*/
//
//		//an *rvalue reference* - denoted by &&
//		/* -an object near the end of its lifetime
//		a temporary object or subobject
//		a value not associated with an object*/
//
//
//	}
//	// TODO READ WIOS;
//	{
//		/*  wios::in | wios::out open for reading and writing (default)
//		 *
//			wios::in | wios::out | wios::trunc open for reading and overwriting
//			wios::in | wios::out | wios::app open for reading and appending
//			wios::out | wios::trunc open for overwriting*/
//
//	}
//	//TODO QUERIES / Modifiers / Mnipulator
//	{
//		//int arr[] = { 10, 20, 30 };
//		//    int n = sizeof(arr) / sizeof(arr[0]);
//		std::cout << endl;
//		std::cout << "==================== ALGORITHM SECTION ======================" << endl << endl;
//		{
//			std::cout << "==================== #COUNT ======================" << endl;
//			//TODO note The program below counts the number of occurrences of the value 1 in array a:
//			std::array<int, 11> a = {1, 2, 3, 1, 1, 1, 1, 2, 2, 3, 4};
//			// syntax  std::+array+<variable, size> name = {value go here} ;
//			// สร้างตัวแปร integer เพื่อมาเกบค่า count
//			int count_store = std::count(a.begin(), a.end(), 1);
//			// syntax = std::Count( จุดเริ่ม , จุดสุดท้าย , ค่าที่ต้องการจะหา);
//			std::cout << "[" << count_store << "]" << endl;
//		}
//		{
//			std::cout << "==================== #COUNT_IF ======================" << endl;
//			//TODO note The program below counts how many เลขคู่ numbers exist in the array a:
//			int a[] = {2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 10, 12, 13, 14};
//
//			int count_store_if = std::count_if(a, a + 14, [](int i) {
//				// syntax (ตัวเริ่ม , ค่า array + จำนวน size , lambda เพื่อจับค่า)
//				return !(i & 1); // หาเลขคู่
//			});
//			cout << "[" << count_store_if << "]" << endl;
//			for (auto &i: a) {
//				cout << "[" << i << "]";
//			}
//			cout << endl;
//		}
//		{
//			std::cout << "==================== #COPY ======================" << endl;
//			//TODO โค้ดข้างล่างนี้เปนการ กอปปี้ สองค่าแรก ของ vector y เข้าไปใน vector c เริ่มจาก ค่าที่สองของ vector c
//			//TODO และโชว์การแสดงผลของการกอปปี้ค่า y ไป c
//			std::vector<double> c({10, 20203, 203, 999.223, 38, 23});
//			// การสร้างค่าให้ vector ได้สองแบบคือ ใส่ {} ปีกกาอาเรย์ แล้วใส่ค่าลงไป
//			std::vector<double> y(5, 102);
//			// แบบที่สอง ใช้วงเลบ parameter ตัวแรกเป็น จำนวน size ต่อไปเป็นค่า value
//
//			std::copy(c.begin(), c.begin() + 2, y.begin() + 1);
//			// ค่าแรกตัวเริ่มที่จะกอปปี้ , จนถึงเมื่อไหร่ , ค่าแรกที่จะใส่ลงไปตำแหน่งไหน
//			for (auto e: y) {
//				cout << "This is Copy Algorithm [" << e << "]" << endl;
//			}
//		}
//		{
//			std::cout << "==================== #COPY_IF ======================" << endl;
//			std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 2, 3, 4, 5, 10, 21, 45, 43};
//			std::vector<int> c(15); // จำนวน size 15
//
//			std::copy_if(v.begin(), v.begin() + 14, c.begin(), [](int i) {
//				return i + 2;
//			});
//
//			for (auto i: c) {
//				cout << "This is Copy Algorithm [" << i << "]" << endl;
//			}
//		}
//		{
//			std::cout << "==================== #Transform ======================" << endl;
//			//TODO The transform function templates perform programmer-specified transformations on the elements of a sequence.
//			//TODO A function object defines the transformation.
//			//TODO The program below multiplies each element in vector v by 3, stores the result in vector c and displays the contents of vector c:
//
//			std::vector<int> x = {1, 2, 4, 5, 7, 8, 10, 13, 17, 21, 43};
//			std::vector<int> y(11); // size 11
//
//			std::transform(x.begin(), x.end(), y.begin(), [](int i) {
//				return 3 * i;
//			});
//
//			for (auto &o: y) {
//				cout << "This is Transform Vector [" << o << "]" << endl;
//			}
//			cout << "[OPTIONAL TRANSFORM]" << endl;
//			//TODO : The program below adds each element in vector a to the corresponding element in vector b,
//			//TODO : stores the results in vector c and displays the contents of vector c:
//			std::vector<int> a = {1, 2, 4, 5, 7, 8, 10, 13, 17, 21, 43};
//			std::vector<int> b = {2, 1, 0, 1, 2, 3, 16, 23, 2, 17, 32};
//			std::vector<int> c(11); // size 11
//
//			std::transform(a.begin(), a.end(), b.begin(), c.begin(), std::multiplies<double>());
//			// parameter ตัวที่ 5 คือ optional operator ที่อยากจะ + -  * / ได้หมดเลย
//
//			// Concept คือ เอาค่าตำแหน่งมา บวกกัน หรือคูณ กัน
//			// เช่น a[0] = 1 , b[0] = 2   == 3;
//
//			for (auto &o: c) {
//				cout << "This is Transform Vector_binary [" << o << "]" << endl;
//			}
//
//
//		}
//		{
//			std::cout << "==================== #Manipulator #sort ======================" << endl;
//
//			int a[] = {3, 2, 4, 1};
//			std::sort(a, &a[4], greater());
//			// greater คือมากกว่า
//			for (int e: a)
//				std::cout << e << std::endl;
//
//		}
//		cout << endl;
//		{
//			std::cout << "==================== #ACCUMULATE ======================" << endl;
//			//TODO: The program below sums the elements in array a, displays the result,
//			//TODO: then sums twice their values and displays that result:
//			int a[] = {3, 2, 4, 1}, s;
//
//			s = std::accumulate(a, &a[4], 5);
//			cout << "sum = " << s << endl;
//			s = std::accumulate(a, &a[4], 0, [](int i, int y) {
//				return i + 2 * y;
//			});
//			cout << "2 * sum = " << s << endl;
//			// ตำแหน่งแรก , ตัวสุดท้าย , ค่า บวก;
//		}
//		{
//			std::cout << "==================== #INNER_PRODUCT ======================" << endl;
//			int a[] = {3, 2, 4, 1},
//					b[] = {1, 2, 3, 4},
//					s;
//
//			// int a[] = {3, 2, 4, 1},
//			//        TODO จับมา * กัน แล้ว + กันตอนสุดท้าย  คือ INNER_PRODUCT
//			//     b[] = {1, 2, 3, 4},
//
//
//			cout << "value of a = ";
//			for (int i = 0; i < 4; ++i) {
//				cout << a[i];
//
//			}
//			cout << endl;
//			cout << "value of b = ";
//			for (int j = 0; j < 4; ++j) {
//				cout << b[j];
//			}
//			cout << endl;
//			s = std::inner_product(a, &a[4], b, 0);
//			std::cout << "dot product = [" << s << "]" << endl;
//			s = std::inner_product(a, &a[4], b, 0, std::plus<int>(), [](int x, int y) {
//				return (x - y) * (x - y);
//			});
//			std::cout << "sum of (a[i] - b[i]) ยกกำลัง 2 =" << s << endl;
//		}
//		{
//			cout << " PARTIAL SUM " << endl;
//			std::vector<int> k{1, 2, 3, 4, 5}, p(5);
//			k.pop_back();
//			k.push_back(20);
//			std::partial_sum(k.begin(), k.end(), p.begin());
//			for (auto i: p) {
//				cout << "[" << i << "]" << endl;
//			}
//			std::partial_sum(k.begin(), k.end(), p.begin(),
//			                 std::multiplies());
//			for (auto ks: p) {
//				cout << "[" << ks << "]" << endl;
//			}
//		}
//		std::cout << "==================== ALGORITHM SECTION ======================" << endl;
//		{
//			int col[]{12, 65, 3, 65, 72, 8, 56};
//			std::list<int> cols{12, 65, 3, 65, 72, 8, 56};
//			for (auto its = cols.begin(); its != cols.end(); ++its) {
//				cout << " " << *its;
//			}
//			auto print = [](const int &n) {
//				std::cout << " " << n << endl;
//			};
//			// for_each not support + 1 or any. use increment instead
//			auto prins = std::for_each(cols.begin()++, cols.end(), [](const int &i) {
//				cout << " " << i << endl;
//			});
//
//			auto res = std::find_if(cols.begin(), cols.end(), [](const int &i) {
//				return i % 5 == 0;
//			});
//
//			cout << " " << *res << endl;
//			// *res deferences;
//			if (res != cols.end()) {
//				cout << "\n Value found [" << *res << "]\n";
//			} else {
//				cout << "\n Not found [" << *res << "]\n";
//			}
//
//			{
//				auto divBy5 = [](const int &i) {
//					return i % 5 == 0;
//				};
//				auto cnt = std::count_if(cols.begin(), cols.end(), divBy5);
//
//				std::vector<int> vct(cnt);
//				std::copy_if(cols.begin(), cols.end(), vct.begin(), divBy5);
//				cout << endl;
//
//				auto sum = accumulate(vct.begin(), vct.end(), 0.0);
//				cout << endl;
//
//				cout << "The sum is : " << sum << endl;
//				if (cnt != 0) {
//					cout << "The average is: " << sum / (double) cnt << endl;
//				}
//
//
//			}
//
//			//TODO only LIST have member function call sort(); col.sort();
//			std::list<int> test = {10, 77, 20, 66, 30, 54, 40, 6, 59, 10, 50, 60};
//			auto countList = count(test.begin(), test.end(), 10);
//			std::vector<int> test1(countList);
//			std::copy(test.begin(), test.end(), test1.begin());
//			cout << endl;
//			cout << "[";
//			for (auto i: test1) {
//				cout << " " << i;
//			}
//			cout << "]";
//			cout << endl;
//			{
//				using namespace std;
//				//TODO BINARY Access
//
//				double val = 1.0 / 3;
//				fstream out("file.txt", ios::out | ios::trunc | ios::binary);
//				out.write("Hello World", 8);
//				// TODO note IOS::BINARY cannot use << to get data need to use write();
//				out.write(reinterpret_cast<char *>(&val), sizeof(val));
//				// TODO 1 reference of value cast into char , 2 how many byte
//			}
//
//			{
//				Console test("Non", "Practice Programming");
//				test.display(cout);
//				vector<Console> Non(14);
//				Non.push_back(test);
//				for_each(Non.begin(), Non.end(), [](const Console &c) {
//					c.getName();
//				});
//
//			}
	//Pointer
	const char s[] = "a C string";
	std::cout << std::hex;
	for (int i = 0; i < strlen(s); ++i) {
		std::cout << "Check Hex string " << &s[i] << " "
		          << s[i] << endl;
	}
	std::cout << std::hex;
	for (int i = 0; s[i]; ++i) {
		std::cout << "Check Hex string " << &s[i] << " "
		          << s[i] << endl;
	}
	const char *p = "May be overitten";
	char sk[19];
	strcpy(sk, p);

	sk[0] = 'm'; // OK
	std::cout << hex;
	std::cout << s << endl;

	cout << "s = " << sk << std::endl;
	cout << "p = " << p + 1 << endl;


	char cff[5][5];    /* array of arrays of chars */
	char *cfp[5];      /* array of pointers to chars */
	char **cpp;         /* pointer to pointer to char ("double pointer") */
	char (*cpf)[5];    /* pointer to array(s) of chars */
	char *cpF();        /* function which returns a pointer to char(s) */
	char (*CFp)();      /* pointer to a function which returns a char */
	char (*cfpF())[5];  /* function which returns pointer to an array of chars */
	char (*cpFf[5])();
	/* an array of pointers to functions which return a char */

	vector<double> fl1(10, 20);
	fl1.pop_front();
	fl1.push_front(50.5);
	fl1.push_front(25.5);
	vector<double> fl2(10, 40);
	fl2.push_back(25.5);
	fl2.push_back(50.5);

	for (auto i: fl2) {
		cout << "[" << i << "]";
	}
	for (auto it = fl2.begin(); fl2.end() != it; ++it) {
		if(fl2 == fl1){

		}
	}
	cout << "\n";

	{
		//TODO
		// vector is contiguous storage of variable size - NOTE vector only can push_back cannot use push_front!

		//TODO
		// deque is non-contiguous storage of variable size, double-ended queue - NOTE can use everything because double-ended
		// can add either front or back.

		//TODO
		// forward_list non-contiguous like deuqe storage of variable size, singly linkedlist
		// only can use push front and pop only cannot remove from the back
	}
}


//	}
//}
//C++11
template<typename T, typename U>
auto myFunc(T &&t, U &&u) -> decltype(forward<T>(t) + forward<U>(u)) { return forward<T>(t) + forward<U>(u); };

//C++14
template<typename T, typename U>
decltype(auto) myFunc(T &&t, U &&u) { return forward<T>(t) + forward<U>(u); };