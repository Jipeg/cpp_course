#include <iostream>
#include <tchar.h>
#include <string>

using namespace std;
int main(int argc, _TCHAR* argv[])
{
	string s = "12345678";
	string p = "qwe";

	cout << "s.size(): " << s.size() << endl;
	cout << "s.length(): " << s.length() << endl;
	cout << "s.max_size(): " << s.max_size() << endl;

	cout << "s.substr(1): " << s.substr(1) << endl;
	cout << "s.substr(1,5): " << s.substr(1,5) << endl;
	cout << "s.max_size(): " << s.max_size() << endl;

	s.resize(6);
	cout << "s.resize(6): " << s << endl;
	s.resize(10,'+');
	cout << "s.resize(10,'+'): " << s << endl;

	s += '5';
    s[1] = 'r';
	for(int i=0; i <= s.length(); i++)
		cout << s[i];

	cout << endl << s+p+s << endl;

	cout << "good str=" << p << endl;
	p[p.length()+1] = 'q';
	cout << "bad str=" << p << endl;

	s = "hello\n";
	cout << s;

    system("pause");
}
