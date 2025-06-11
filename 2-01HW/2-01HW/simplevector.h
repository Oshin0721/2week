#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

template <typename T>
class SimpleVector {
private:
	T* data;				//data ������ ����
	int currentSize;		//���� ũ��
	int currentCapacity;	//���� �뷮

public:
	SimpleVector() {                     //�⺻ ������
		currentCapacity = 10;			// �ʱ� �뷮�� 10���� ����
		data = new T[currentCapacity];  // T Ÿ���� �迭�� ���� �Ҵ�
		currentSize = 0;				// �ʱ� ũ�⸦ 0���� ����
	};
	SimpleVector(int capacity) {			//����� ���� ������
		currentCapacity = capacity;		// �ʱ� �뷮�� ����� ���� ������ ����
		data = new T[currentCapacity];  // T Ÿ���� �迭�� ���� �Ҵ�
		currentSize = 0;                // �ʱ� ũ�⸦ 0���� ����
	};
	~SimpleVector() {					//�Ҹ���
		delete[] data;                  // ���� �Ҵ�� �迭 �޸� ����
	};

	void push_back(const T& value) {            //������ ���� ��Ҹ� �߰��ϴ� �Լ�
		if (currentSize >= currentCapacity) {   // ���� ũ�Ⱑ �뷮�� �ʰ��ϸ�
			return;                           // �뷮�� �� ��� �ø��� resize �Լ� ȣ��
		}
		data[currentSize++] = value;             // �� ��Ҹ� ���� ũ�� ��ġ�� �߰�
	}

	void pop_back() {
		if (currentSize > 0) {                   // ���� ũ�Ⱑ 0���� ū ��쿡��
			currentSize--;                       // ���� ũ�⸦ 1 ���ҽ��� ������ ��Ҹ� ����
		}
	}

	int size() const {								//���� ũ�⸦ ��ȯ�ϴ� �Լ�
		return currentSize;                     // ���� ũ�⸦ ��ȯ
	}

	int capacity() const {                            //���� �뷮�� ��ȯ�ϴ� �Լ�
		return currentCapacity;                 // ���� �뷮�� ��ȯ
	}

	void resize() {                                 //�뷮�� �� ��� �ø��� �Լ�
		int newCapacity = currentCapacity * 2;      // ���ο� �뷮�� ���� �뷮�� �� ��� ����
		T* newData = new T[newCapacity];            // ���ο� �뷮���� T Ÿ���� �迭�� ���� �Ҵ�

		for (int i = 0; i < currentSize; i++) {    // ���� ũ�⸸ŭ ���� �����͸� �� �迭�� ����
			newData[i] = data[i];                  // ���� ������ ����
		}

		delete[] data;                             // ���� ������ �迭 �޸� ����
		data = newData;                            // data �����͸� �� �迭�� ������Ʈ
		currentCapacity = newCapacity;             // ���� �뷮�� �� �뷮���� ������Ʈ
	}
};



#endif