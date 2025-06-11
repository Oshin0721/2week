#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

template <typename T>
class SimpleVector {
private:
	T* data;				//data 포인터 선언
	int currentSize;		//현제 크기
	int currentCapacity;	//현제 용량

public:
	SimpleVector() {                     //기본 생성자
		currentCapacity = 10;			// 초기 용량을 10으로 설정
		data = new T[currentCapacity];  // T 타입의 배열을 동적 할당
		currentSize = 0;				// 초기 크기를 0으로 설정
	};
	SimpleVector(int capacity) {			//사용자 정의 생성자
		currentCapacity = capacity;		// 초기 용량을 사용자 정의 값으로 설정
		data = new T[currentCapacity];  // T 타입의 배열을 동적 할당
		currentSize = 0;                // 초기 크기를 0으로 설정
	};
	~SimpleVector() {					//소멸자
		delete[] data;                  // 동적 할당된 배열 메모리 해제
	};

	void push_back(const T& value) {            //벡터의 끝에 요소를 추가하는 함수
		if (currentSize >= currentCapacity) {   // 현재 크기가 용량을 초과하면
			return;                           // 용량을 두 배로 늘리는 resize 함수 호출
		}
		data[currentSize++] = value;             // 새 요소를 현재 크기 위치에 추가
	}

	void pop_back() {
		if (currentSize > 0) {                   // 현재 크기가 0보다 큰 경우에만
			currentSize--;                       // 현재 크기를 1 감소시켜 마지막 요소를 제거
		}
	}

	int size() const {								//현재 크기를 반환하는 함수
		return currentSize;                     // 현재 크기를 반환
	}

	int capacity() const {                            //현재 용량을 반환하는 함수
		return currentCapacity;                 // 현재 용량을 반환
	}

	void resize() {                                 //용량을 두 배로 늘리는 함수
		int newCapacity = currentCapacity * 2;      // 새로운 용량을 현재 용량의 두 배로 설정
		T* newData = new T[newCapacity];            // 새로운 용량으로 T 타입의 배열을 동적 할당

		for (int i = 0; i < currentSize; i++) {    // 현재 크기만큼 기존 데이터를 새 배열로 복사
			newData[i] = data[i];                  // 기존 데이터 복사
		}

		delete[] data;                             // 기존 데이터 배열 메모리 해제
		data = newData;                            // data 포인터를 새 배열로 업데이트
		currentCapacity = newCapacity;             // 현재 용량을 새 용량으로 업데이트
	}
};



#endif