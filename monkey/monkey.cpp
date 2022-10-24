#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	//s:string;
	//randomize;
	srand(time(nullptr)); // use current time as seed for random generator

	int random_variable = rand();
	cout << random_variable << endl;
	cout << "Input latin small letter and number of it's repetitions:\n";
	char b; int c;
	cin >> b >> c;
	int k = 0;
	int i = 0;
	while (i < c) {
		k++;
		char a = char(rand() % ('z'-'a') + 'a');
		cout << a;
		//s:=s+a;
		if (a == b) i++;
		else i = 0;
	}
	cout << endl << "Required: " << k << endl;
	int k1 = 1;
	for (int i = 1; i <= c; i++)
		k1 = k1*26;
	cout << "Theoreticaly it requires: " << k1 << endl;
	system("pause");
}
