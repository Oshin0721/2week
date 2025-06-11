#include "simplevector.h"
#include <iostream>


int main() {
	SimpleVector<int> vec(2);                      // 백터 크기를 2로 설정

	vec.push_back(1);                              // 백터에 요소 추가
	vec.push_back(2);                              // 백터에 요소 추가
	vec.push_back(3);                              // 백터에 요소 추가, 크기가 자동으로 증가

	std::cout << "Size: " << vec.size() << "\n";                 // 현재 크기 출력
	std::cout << "Capacity: " << vec.capacity() << "\n";         // 현재 용량 출력

	vec.pop_back();                                // 마지막 요소 제거

	std::cout << "Size after pop: " << vec.size() << "\n"; // 제거 후 크기 출력

    return 0;
}