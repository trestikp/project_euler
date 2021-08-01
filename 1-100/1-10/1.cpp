/*
	Sum of all natural numbers dividable by 3 or 5 and smaller than 1000.

	2 approcheas. Number 2 sucks by about 50% of number 1;
*/

#include <stdio.h>
#include <inttypes.h>

#include <chrono>

int main() {
	int i = 1;
	uint64_t sum = 0;

	auto start = std::chrono::high_resolution_clock::now();

	for(i = 1; i < 1000; i++) {
		if(!(i % 3) || !(i % 5)) {
			sum += i;
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	printf("1: %ld in %ldns\n", sum, time);


	// different approach

	sum = 0;
	int num = 3;

	start = std::chrono::high_resolution_clock::now();

	while(num < 1000) {
		sum += num;

		//well "register" is depraceted apperently, so i will hope cpu puts it there?
		int add3 = 3 - (num % 3);
		int add5 = 5 - (num % 5);

		if(add3 < add5)
			num += add3;
		else
			num += add5;
	}

	end = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

	printf("2: %ld in %ldns\n", sum, time);

	return 0;
}
