// Арифметические алгоритмы: возведение целого числа в натуральную степень 
// POW(a, b) = EXP(LOG(a) * b) !!!
#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

template <typename T>
T slowDegree(T a, int b);
template <typename T>
T fastDegree(T a, int b);
inline double fastPow(double a, double b);

void check(long long (*fun)(int, int), const char* fun_name, int a, int b, int n);
template<typename T>
void check(T (*fun)(T, int), const char* fun_name, int a, int b, int n);
template<typename T, typename T1, typename T2>
void check(T (*fun)(T1, T2), const char* fun_name, int a, int b, int n);

int main(){
    cout << "Сomparison of different power functions\n";
    const int n = 1e8; // number of times

    check<long>(&slowDegree,"slowDegree", 34, 7, n);
    check<long long>(&slowDegree,"slowDegree", 34, 7, n);
    check<double>(&slowDegree,"slowDegree", 34, 7, n);

    check<long>(&fastDegree,"fastDegree", 34, 7, n);
    check<long long>(&fastDegree,"fastDegree", 34, 7, n);
    check<double>(&fastDegree,"fastDegree", 34, 7, n);

    check<double, double, double>(&pow,"pow", 34, 7, n);
    check<float, float, float>(&powf,"powf", 34, 7, n);
    //check<long double, long double, long double>(&powl,"powl", 34, 7, n);

    check<double, double, double>(&fastPow,"fastPow", 34, 7, n);
}
template <typename T>
T slowDegree(T a,int b){
    T r = 1;
    while (b > 0) {
            r = r*a;
            b--;
        }
    return r;
}

template <typename T>
T fastDegree(T a,int b){
    T r = 1;
    T c = a;
    while (b > 0) {
        if (b % 2) {
            r = r*c;
            b--;
        } else {
            c = c * c;
            b = b / 2;
        }
    }
    return r;
}

inline double fastPow(double a, double b) {
  union {
    double d;
    int x[2];
  } u = { a };
  u.x[1] = (int)(b * (u.x[1] - 1072632447) + 1072632447);
  u.x[0] = 0;
  return u.d;
}

template<typename T>
void check(T (*fun)(T, int), const char* fun_name, int a, int b, int n){
    cout << fun_name <<"(" << a <<"," << b << ")\t=" << (*fun)(a,b) << endl;
    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 1; i <=n; i++)
        (*fun)(a,b);  //{ print x^y }
    auto t2 = chrono::high_resolution_clock::now();
    cout << fun_name << "\t took " << chrono::duration_cast<chrono::nanoseconds>(t2-t1).count()*1e-9 << "sec" << endl << endl;
}

template<typename T, typename T1, typename T2>
void check(T (*fun)(T1, T2), const char* fun_name, int a, int b, int n){
    cout << fun_name <<"(" << a <<"," << b << ")\t=" << (*fun)(a,b) << endl;
    auto t1 = chrono::high_resolution_clock::now();
    for (int i = 1; i <=n; i++)
        (*fun)(a,b);  //{ print x^y }
    auto t2 = chrono::high_resolution_clock::now();
    cout << fun_name << "\t took " << chrono::duration_cast<chrono::nanoseconds>(t2-t1).count()*1e-9 << "sec" << endl << endl;
}
