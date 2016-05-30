#include <iostream>
#include <string>
using namespace std;

class Base {
public:
	Base *createBase(int x);
	int add_value(int y){ value = y; return value; }
protected:
	int value;
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base* Base::createBase(int x){
		Base *base = NULL;
		switch (x){
		case 1: base = new A; break;
		case 2: base = new B; break;
		case 3: base = new C; break;
		}
		return base;
	}

int main(){
	int n; string s; Base BASE;
	cin >> n;
	int* mA = new int[n]; int kA = 0;
	int* mB = new int[n]; int kB = 0;
	int* mC = new int[n]; int kC = 0;
	while (n){
		getline(cin, s);
		if (!s.find("create")){
			n--;
			s.erase(0, 7);
			if (s.substr(0, 1) == "A"){
				s.erase(0, 2);
				int y = atoi(s.c_str());
				mA[kA]= BASE.createBase(1)->add_value(y);
				kA++;
			}
			if (s.substr(0, 1) == "B"){
				s.erase(0, 2);
				int y = atoi(s.c_str());
				mB[kB] = BASE.createBase(2)->add_value(y);
				kB++;
			}		
			if (s.substr(0, 1) == "C"){
				s.erase(0, 2);
				int y = atoi(s.c_str());
				mC[kC] = BASE.createBase(3)->add_value(y);
				kC++;
			}
		}
		if (s == "showall"){
			n--;
			for (int i = 0; i < kA; i++) cout << "class A: " << mA[i] << endl;
			for (int i = 0; i < kB; i++) cout << "class B: " << mB[i] << endl;
			for (int i = 0; i < kC; i++) cout << "class C: " << mC[i] << endl;
		}
	}
	system("pause");
}
