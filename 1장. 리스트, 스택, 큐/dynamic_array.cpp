#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template <typename T>
class dynamic_array
{
private:
	T* data;
	size_t n;
public:
	dynamic_array(size_t n) : data(new T[n]), n(n) {}

	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; ++i)
			data[i] = other[i];
	}

	friend dynamic_array<T> operator+(const dynamic_array<T>& da1, const dynamic_array<T>& da2)
	{
		dynamic_array<T> da(da1.size() + da2.size());

		copy(da1.begin(), da1.end(), da.begin());
		copy(da2.begin(), da2.end(), da.begin() + da1.size());

		return da;
	}

	T& operator[](int index)
	{
		return data[index];
	}

	const T& operator[](int index) const
	{
		return data[index];
	}

	T& at(int index)
	{
		if (n <= index)
			throw out_of_range("배열 범위 초과");

		return data[index];
	}

	size_t size() const
	{
		return n;
	}

	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	string to_string(const string& sep = ", ")
	{
		ostringstream oss;

		if (n == 0)
			return "";

		oss << data[0];

		for (int i = 1; i < n; ++i)
			oss << sep << data[i];

		return oss.str();
	}

	virtual ~dynamic_array()
	{
		delete[] data;
		data = nullptr;
	}
};

struct student
{
	string name;
	int standard;
};

ostream& operator<<(ostream& os, const student& st)
{
	return (os <<"[" << st.name << ", " << st.standard << "]");
}

int main(int argc, char* argv[])
{
	int nStudents;
	cout << "1반 학생 수를 입력하세요: ";
	cin >> nStudents;

	dynamic_array<student> class1(nStudents);

	for (int i = 0; i < nStudents; ++i)
	{
		string name;
		int standard;

		cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
		cin >> name >> standard;

		class1[i] = student{name, standard};
	}

	try
	{
		// 예상할 수 없는 동작
		// class1[nStudents] = student {"John", 8};

		// 예외 발생
		class1.at(nStudents) = student{"John", 8};
	}
	catch (exception& ex)
	{
		cout << "예외 발생: " << ex.what() << endl;
	}

	// 깊은 복사
	decltype(class1) class2 = class1;
	cout << "1반을 복사하여 2반 생성: " << class2.to_string() << endl;

	// 두 학급을 합쳐서 새로운 학급을 생성
	auto class3 = class1 + class2;
	cout << "1반과 2반을 합쳐 3반 생성 : " << class3.to_string() << endl;

	return 0;
}
