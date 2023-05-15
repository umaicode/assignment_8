//8 컨테이너 클래스 - 객체들 집합 
// Bag의 특성
// 1) 순서가 없다.
// 2) 중복이 허용된다.
// 3) 꺼내는 것은 Delete() 함수를 만들어서 구현.
// 4) 넣는 것은 Add() 함수를 만들어서 구현.
// Set의 특성
// 1) 순서가 없다.
// 2) 중복이 없다.
// 3) 즉, bag에서 Add()는 무조건 삽입하지만 Set에서는 중복 체크 코드(if문 사용)를 넣어서 Add()를 사용해야 한다. -> Bag::Add(p); 사용
// 4) Delete()는 랜덤하게 꺼낸다. Set의 Delete()는 Bag의 Delete()를 그대로 써도 된다. -> Bag::Delete();
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string pid;
	string pname;
public:
	Person() {}
	Person(string pid, string pname) : pid(pid), pname(pname) { }
	virtual void Show() { cout << pid << ", " << pname << ", "; }
	virtual bool operator==(Person&);
	virtual void Print() {
		Show();
	}
	string getName() {
		return pname;
	}
};

bool Person::operator==(Person& other) {
	return (pid == other.pid && pname == other.pname);
}

class Employee : public Person {
private:
	string eno;
	string role;
public:
	Employee() :Person() {}
	//	int operator >(Employee&);
	Employee(string pid, string pname, string eno, string role) : Person(pid, pname), eno(eno), role(role) { }
	//	int operator < (Employee&);

	virtual void Show() {
		Person::Show();
		cout << eno << ", " << role << ", ";
	}

	virtual void Print() {
		Person::Print();
		Show();
	}
};

//int Employee::operator>(Employee& e) {
//	if (role == e.role) {
//		return eno > e.eno;
//	}
//	else {
//		return role > e.role;
//	}
//}
//
//int Employee::operator<(Employee& e) {
//	if (role == e.role) {
//		return eno < e.eno;
//	}
//	else {
//		return role < e.role;
//	}
//}

class Coder : public Employee {
private:
	string language;
public:
	Coder() :Employee() {}
	Coder(string pid, string pname, string eno, string role, string language) : Employee(pid, pname, eno, role), language(language) {}
	//	int operator > (Coder&);//
	void Print();
	void Show();
};

//int Coder::operator > (Coder& c) {
//	// 언어가 같으면 사번 기준으로 비교
//	if (language == c.language) {
//		return Employee::operator>(c);
//	}
//	// 언어가 다르면 언어 기준으로 비교
//	else {
//		return language > c.language;
//	}
//}

void Coder::Show() {
	Employee::Show();
	cout << language << endl;
}

// ---------------------------------- 교수님 코드 -------------------------------------
void Coder::Print() {
	Employee::Print();
	Show();
}
// ---------------------------------- 교수님 코드 -------------------------------------


class Student : public Person {//virtual은 Person() 생성자를 호출하지 않음
private:
	string sid;
	string major;
public:
	Student(string sid, string major, string pid, string pname) : Person(pid, pname), sid(sid), major(major) { }
	//	int operator < (Student&);
	string getMajor() {
		return major;
	}
	string getSid() {
		return sid;
	}
	void Show() {
		Person::Show();
		cout << sid << ", " << major << ", ";
	}
};

//int Student::operator<(Student& s) {
//	if (major == s.major) {
//		return sid < s.sid;
//	}
//	else {
//		return major < s.major;
//	}
//}

class PartTimeStudent : public Student {
private:
	string workType;
public:
	PartTimeStudent(string workType, string sid, string major, string pid, string pname) :
		Student(sid, major, pid, pname), workType(workType) {}
	//	int operator < (PartTimeStudent&);
	void Show() {
		Student::Show();
		cout << workType << endl;
	}
};

//int PartTimeStudent::operator<(PartTimeStudent& pts) {
//	if (getMajor() == pts.getMajor()) {
//		if (getSid() == pts.getSid()) {
//			return workType < pts.workType;
//		}
//		else {
//			return getSid() < pts.getSid();
//		}
//	}
//	else {
//		return getMajor() < pts.getMajor();
//	}
//}

#define DefaultSize 10
class Bag {
public:
	Bag(int MaxSize = DefaultSize); //생성자
	~Bag(); // 소멸자
	virtual void Add(Person*); // 정수 하나를 bag에 삽입
	virtual Person* Delete(); //bag에서 정수 하나를 삭제
	bool IsFull();
	// bag이 포화상태이면 true, 그렇지 않으면 false를 반환
	bool IsEmpty();
	// bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
	int Top();
	Person& Find(string);
	virtual void Print();

protected:
	void Full(); // bag이 포화상태일 때의 조치
	void Empty(); // bag이 공백 상태일 때의 조치
	Person* arr[DefaultSize];
	int MaxSize; // 배열의 크기
	int top; // 배열에서 원소가 들어 있는 가장 높은 위치
};

Bag::Bag(int MaxSize) {
	this->MaxSize = MaxSize;
	top = 0;
}

Bag::~Bag() {
	for (int i = 0; i < top; i++) {
		delete arr[i];
	}
}

bool Bag::IsFull() {
	if (top == MaxSize) {
		return true;
	}
	else {
		return false;
	}
}

bool Bag::IsEmpty() {
	if (top == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Bag::Top() {
	return top;
}

Person& Bag::Find(string name) {
	for (int i = 0; i < top; i++) {
		if (arr[i]->getName() == name) {
			return *arr[i];
		}
	}
	cout << "이름을 찾을 수 없습니다." << endl;
	throw exception();
}

void Bag::Full() {
	cout << "Data Structure is FULL!!!" << endl;
}

void Bag::Empty() {
	cout << "Data Structure is EMPTY!!!" << endl;
}

// ---------------------------------- 교수님 코드 -------------------------------------
void Bag::Print() {
	Person* p;
	for (int i = 0; i < top; i++) {
		p = arr[i];
		p->Show();
	}
}

void Bag::Add(Person* p) {
	if (IsFull()) {
		Full();
	}

	if (top < MaxSize) {
		arr[top++] = p;
	}
}
// ---------------------------------- 교수님 코드 -------------------------------------

Person* Bag::Delete() {
	if (IsEmpty()) {
		Empty();
		return nullptr;
	}

	int index = rand() % top;
	Person* temp = arr[index];
	arr[index] = arr[top - 1];
	arr[top - 1] = nullptr;
	top--;
	return temp;
}

class Set : public Bag {
public:
	Set();
	// Set(int MaxSize = DefaultSize);      //생성자
	~Set();      // 소멸자
	//Set 자료구조에 맞게 Add(), Delete() 함수 재정의
	// void Add(Person*);
	// Person* Delete();
	virtual void Add(Person*);
	virtual Person* Delete();
	void Print();
};

Set::Set() {}

Set::~Set() {

}

//void Set::Add(Person* p) {
//    for (int i = 0; i < top; i++) {
//        // 중복 검사 코드 작성해야 한다.
//        if (*arr[i] == *p) {
//            cout << "중복 있다.";
//            return;
//        }
//        if (top < MaxSize) {
//            arr[top++] = p;
//        }
//    }
//    Bag::Add(p);
//}

void Set::Add(Person* p) {
	if (IsFull()) {
		Full();
		return;
	}
	else {
		for (int i = 0; i < top; i++) {
			if (*arr[i] == *p) {
				cout << "중복된 값입니다." << endl;
				return;
			}
		}
		Bag::Add(p);
	}
	return;
}

Person* Set::Delete() {
	return Bag::Delete();
}

void Set::Print() {
	// Bag::Print();
	for (int i = 0; i < top; i++) {
		arr[i]->Show();   // 동적바인딩을 수행함
	}
}

// show함수는 클래스의 멤버함수가 아니다. polymorphism에 의해서 동적바인딩으로 처리된다.
void Show(Person* p[]) {
	for (int i = 0; i < 30; i++) {
		// p[i].Print();   // 이 코드는 동적바인딩 한다.
		p[i]->Show();
	}
}
int main() {
	Person* members[30];//Person 선언으로 변경하는 문제 해결 필요 
	Set s;
	int select;
	Person* p;
	Coder cx;
	string name;
	while (1)
	{

		cout << "\n선택 1: member  객체 30개 입력, 2. set 출력, 3: set에서 객체 찾기,4. set에서 임의 객체 삭제, 5. members[] 배열의 show 함수, 6. 종료" << endl;
		cin >> select;

		switch (select) {
		case 1://1: Coder 객체 10개 입력과 출력
		{
			members[0] = new Coder("p1", "hong", "E1", "Coding", "C++");
			members[1] = new Coder("p2", "hee", "E2", "Coding", "C++");
			members[2] = new Coder("p3", "kim", "E3", "Test", "JAVA");
			members[3] = new Coder("p1", "hong", "E1", "Coding", "C++");
			// members[3] = new Coder("p4", "lee", "E4", "Test", "C#");
			members[4] = new Coder("p5", "ko", "E5", "Design", "GO");
			members[5] = new Coder("p6", "choi", "E6", "Design", "GO");
			members[6] = new Coder("p7", "han", "E7", "Sales", "PYTHON");
			members[7] = new Coder("p8", "na", "E8", "Sales", "C");
			members[8] = new Coder("p9", "you", "E9", "Account", "C++");
			members[9] = new Coder("p10", "song", "E10", "Production", "C#");
			members[10] = new PartTimeStudent("coding", "s001", "computer", "23001", "hong");
			members[11] = new PartTimeStudent("designer", "s002", "DB", "23001", "hong");
			members[12] = new PartTimeStudent("tester", "s003", "Java", "23001", "hong");
			members[13] = new PartTimeStudent("manager", "s004", "기계", "23001", "hong");
			members[14] = new PartTimeStudent("accountant", "s005", "전기", "23001", "hong");
			members[15] = new PartTimeStudent("salesman", "s006", "의류", "23001", "hong");
			members[16] = new PartTimeStudent("planner", "s007", "전자", "23001", "hong");
			members[17] = new PartTimeStudent("audit", "s008", "화공", "23001", "hong");
			members[18] = new PartTimeStudent("DBA", "s009", "화학", "23001", "hong");
			members[19] = new PartTimeStudent("DBA", "s010", "산업", "23001", "hong");
			members[20] = new PartTimeStudent("coder", "s001", "computer", "23001", "hong");
			members[21] = new PartTimeStudent("coder", "s002", "DB", "23001", "hong");
			members[22] = new PartTimeStudent("tester", "s003", "Java", "23001", "hong");
			members[23] = new PartTimeStudent("designer", "s004", "기계", "23001", "hong");
			members[24] = new PartTimeStudent("designer", "s005", "전기", "23001", "hong");
			members[25] = new PartTimeStudent("AS", "s006", "의류", "23001", "hong");
			members[26] = new PartTimeStudent("coder", "s007", "전자", "23001", "hong");
			members[27] = new PartTimeStudent("audit", "s008", "화공", "23001", "hong");
			members[28] = new PartTimeStudent("engineer", "s009", "화학", "23001", "hong");
			members[29] = new PartTimeStudent("designer", "s010", "산업", "23001", "hong");

			for (int i = 0; i < 30; i++)
			{
				s.Add(members[i]);
			}
			break;
		}
		case 2:
		{
			// set의 모든 객체 출력하기
			// cout을 사용하지 않고, Set에 Print()를 만들어서 사용.
			s.Print();
			break;
		}
		case 3:
		{
			// set에서 객체 찾기
			//cin >> name;
			//Person& p = s.Find(name);
			//p.Show();
			//break;
			cin >> name;
			try {
				Person& p = s.Find(name);
				p.Show();
			}
			catch (exception e) {
				continue; // switch문으로 돌아가기 위해 continue 사용
			}
			break;
		}
		case 4:
		{
			//set에서 임의 객체 삭제하기
			Person* p = s.Delete();
			p->Show();
			break;
		}
		case 5:
			//members[]의  모든 객체들에 대한 show() 동작: polymorphic function 구현하기
			Show(members);
			break;

		default:
			exit(0);

		}
	}
	system("pause");
	return 1;
}