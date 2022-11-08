//
// Created by Nonthachai Plodthong on 31/10/2022 AD.
//


#include "Time.h"

namespace sdds {
	void Timer::start() {
		startClock = steady_clock::now();

	}

	long long Timer::stop() {

		endClock = steady_clock::now();
		auto timeInt = duration_cast<nanoseconds>(endClock - startClock);
		duration<long, std::nano> timeUse = timeInt;
		return timeUse.count();
	}


}