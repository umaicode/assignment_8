//8 �����̳� Ŭ���� - ��ü�� ���� 
// Bag�� Ư��
// 1) ������ ����.
// 2) �ߺ��� ���ȴ�.
// 3) ������ ���� Delete() �Լ��� ���� ����.
// 4) �ִ� ���� Add() �Լ��� ���� ����.
// Set�� Ư��
// 1) ������ ����.
// 2) �ߺ��� ����.
// 3) ��, bag���� Add()�� ������ ���������� Set������ �ߺ� üũ �ڵ�(if�� ���)�� �־ Add()�� ����ؾ� �Ѵ�. -> Bag::Add(p); ���
// 4) Delete()�� �����ϰ� ������. Set�� Delete()�� Bag�� Delete()�� �״�� �ᵵ �ȴ�. -> Bag::Delete();
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
//	// �� ������ ��� �������� ��
//	if (language == c.language) {
//		return Employee::operator>(c);
//	}
//	// �� �ٸ��� ��� �������� ��
//	else {
//		return language > c.language;
//	}
//}

void Coder::Show() {
	Employee::Show();
	cout << language << endl;
}

// ---------------------------------- ������ �ڵ� -------------------------------------
void Coder::Print() {
	Employee::Print();
	Show();
}
// ---------------------------------- ������ �ڵ� -------------------------------------


class Student : public Person {//virtual�� Person() �����ڸ� ȣ������ ����
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
	Bag(int MaxSize = DefaultSize); //������
	~Bag(); // �Ҹ���
	virtual void Add(Person*); // ���� �ϳ��� bag�� ����
	virtual Person* Delete(); //bag���� ���� �ϳ��� ����
	bool IsFull();
	// bag�� ��ȭ�����̸� true, �׷��� ������ false�� ��ȯ
	bool IsEmpty();
	// bag�� ���� �����̸� true, �׷��� ������ false�� ��ȯ
	int Top();
	Person& Find(string);
	virtual void Print();

protected:
	void Full(); // bag�� ��ȭ������ ���� ��ġ
	void Empty(); // bag�� ���� ������ ���� ��ġ
	Person* arr[DefaultSize];
	int MaxSize; // �迭�� ũ��
	int top; // �迭���� ���Ұ� ��� �ִ� ���� ���� ��ġ
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
	cout << "�̸��� ã�� �� �����ϴ�." << endl;
	throw exception();
}

void Bag::Full() {
	cout << "Data Structure is FULL!!!" << endl;
}

void Bag::Empty() {
	cout << "Data Structure is EMPTY!!!" << endl;
}

// ---------------------------------- ������ �ڵ� -------------------------------------
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
// ---------------------------------- ������ �ڵ� -------------------------------------

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
	// Set(int MaxSize = DefaultSize);      //������
	~Set();      // �Ҹ���
	//Set �ڷᱸ���� �°� Add(), Delete() �Լ� ������
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
//        // �ߺ� �˻� �ڵ� �ۼ��ؾ� �Ѵ�.
//        if (*arr[i] == *p) {
//            cout << "�ߺ� �ִ�.";
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
				cout << "�ߺ��� ���Դϴ�." << endl;
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
		arr[i]->Show();   // �������ε��� ������
	}
}

// show�Լ��� Ŭ������ ����Լ��� �ƴϴ�. polymorphism�� ���ؼ� �������ε����� ó���ȴ�.
void Show(Person* p[]) {
	for (int i = 0; i < 30; i++) {
		// p[i].Print();   // �� �ڵ�� �������ε� �Ѵ�.
		p[i]->Show();
	}
}
int main() {
	Person* members[30];//Person �������� �����ϴ� ���� �ذ� �ʿ� 
	Set s;
	int select;
	Person* p;
	Coder cx;
	string name;
	while (1)
	{

		cout << "\n���� 1: member  ��ü 30�� �Է�, 2. set ���, 3: set���� ��ü ã��,4. set���� ���� ��ü ����, 5. members[] �迭�� show �Լ�, 6. ����" << endl;
		cin >> select;

		switch (select) {
		case 1://1: Coder ��ü 10�� �Է°� ���
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
			members[13] = new PartTimeStudent("manager", "s004", "���", "23001", "hong");
			members[14] = new PartTimeStudent("accountant", "s005", "����", "23001", "hong");
			members[15] = new PartTimeStudent("salesman", "s006", "�Ƿ�", "23001", "hong");
			members[16] = new PartTimeStudent("planner", "s007", "����", "23001", "hong");
			members[17] = new PartTimeStudent("audit", "s008", "ȭ��", "23001", "hong");
			members[18] = new PartTimeStudent("DBA", "s009", "ȭ��", "23001", "hong");
			members[19] = new PartTimeStudent("DBA", "s010", "���", "23001", "hong");
			members[20] = new PartTimeStudent("coder", "s001", "computer", "23001", "hong");
			members[21] = new PartTimeStudent("coder", "s002", "DB", "23001", "hong");
			members[22] = new PartTimeStudent("tester", "s003", "Java", "23001", "hong");
			members[23] = new PartTimeStudent("designer", "s004", "���", "23001", "hong");
			members[24] = new PartTimeStudent("designer", "s005", "����", "23001", "hong");
			members[25] = new PartTimeStudent("AS", "s006", "�Ƿ�", "23001", "hong");
			members[26] = new PartTimeStudent("coder", "s007", "����", "23001", "hong");
			members[27] = new PartTimeStudent("audit", "s008", "ȭ��", "23001", "hong");
			members[28] = new PartTimeStudent("engineer", "s009", "ȭ��", "23001", "hong");
			members[29] = new PartTimeStudent("designer", "s010", "���", "23001", "hong");

			for (int i = 0; i < 30; i++)
			{
				s.Add(members[i]);
			}
			break;
		}
		case 2:
		{
			// set�� ��� ��ü ����ϱ�
			// cout�� ������� �ʰ�, Set�� Print()�� ���� ���.
			s.Print();
			break;
		}
		case 3:
		{
			// set���� ��ü ã��
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
				continue; // switch������ ���ư��� ���� continue ���
			}
			break;
		}
		case 4:
		{
			//set���� ���� ��ü �����ϱ�
			Person* p = s.Delete();
			p->Show();
			break;
		}
		case 5:
			//members[]��  ��� ��ü�鿡 ���� show() ����: polymorphic function �����ϱ�
			Show(members);
			break;

		default:
			exit(0);

		}
	}
	system("pause");
	return 1;
}