//
// Created by Nonthachai Plodthong on 31/10/2022 AD.
//

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <chrono>


using namespace std::chrono;
namespace sdds {

	class Timer {
	private:
		steady_clock::time_point startClock;
		steady_clock::time_point endClock;

	public:
		void start();

		long long stop();
	};

}
#endif //SDDS_TIMER_H
