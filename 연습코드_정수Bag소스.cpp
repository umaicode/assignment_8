//�������� Bag Ŭ���� ������ ���
#include <iostream>
#include <string>
#include "time.h"
using namespace std;

#define DefaultSize 10
class Bag {
public:
    Bag(int MaxSize = DefaultSize); //������
    ~Bag(); // �Ҹ���
    virtual void Add(int); // ���� �ϳ��� bag�� ����
    virtual int Delete(); //bag���� ���� �ϳ��� ����
    bool IsFull();
    // bag�� ��ȭ�����̸� true, �׷��� ������ false�� ��ȯ
    bool IsEmpty();
    // bag�� ���� �����̸� true, �׷��� ������ false�� ��ȯ
    int Top();
    int Find();
    friend ostream& operator<< (ostream& stream, Bag b);
protected:
    void Full(); // bag�� ��ȭ������ ���� ��ġ
    void Empty(); // bag�� ���� ������ ���� ��ġ
    int arr[DefaultSize];
    int MaxSize; // �迭�� ũ��
    int top; // �迭���� ���Ұ� ��� �ִ� ���� ���� ��ġ
};

class Set : public Bag {
public:
    Set(int MaxSize = DefaultSize);      //������
    ~Set();      // �Ҹ���
                 //Set �ڷᱸ���� �°� Add(), Delete() �Լ� ������
    void Add(int);
    int Delete();
    friend ostream& operator<< (ostream& stream, Set s);
};


int main() {
    Set s;
    int select;
    int num;
    srand(time(NULL));
    while (1)
    {

        cout << "\n���� 1: ���� �����Ͽ� �Է�, 2.set ��� ����, 3.set���� ���� ����, 4. Set���� find, 5. ����" << endl;
        cin >> select;

        switch (select) {
        case 1://1: ���� ����

            for (int i = 0; i < 10; i++) {
                s.Add(rand() % 100);
            }

            break;
        case 2:
            cout << "Set:: ��ü ���" << s << endl;
            break;

        case 3://

            for (int i = 0; i < 10; i++)
            {
                cout << "Set:: ������ �� = " << s.Delete() << endl;
            }
            break;
        case 4://

            for (int i = 0; i < 10; i++)
            {
                cin >> num;
                s.Find(num);
                //
            }
            break;
        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}