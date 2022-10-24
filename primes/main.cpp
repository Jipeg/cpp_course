#include <iostream>
#include <fstream>
#include <chrono>
#include <time.h>
#include <math.h>

bool isPrime (int num)
{
    if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);

        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}

static int * prime2(int m,int n){
int k=0;
int *p = new int[n];
for(int i = m; i <= n; i++)
    {
        if( isPrime(i) )
        {
            p[k++]=i;
        }
    }
if(k==n/log(n))
        std::cout << "OK\n";
return p;
}

static int * prime3(int m,int n){
int k=0;
int *p = new int[n];
for(int i = 3; i <= n; i+=2)
    {
        bool prime = true;
        int s = sqrt(i);
        for(int j=0; j<k && p[j]<=s; j++)
                if(i % p[j]==0){
                        prime = false;
                        break;
                }
        if(prime)
                p[k++]=i;
    }
return p;
}

void sw(int *p, int *p1=0){
        for (int i=0; p[i]!=0; i++)
                std::cout << p[i] << " " << (p1 ? (char)p1[i]: '0') << std::endl;
}
template<typename T>
int *check(int *(*fun)(int,int),int m,int n){
        if(fun==prime2) std::cout << "Checking function prime2" << std::endl;
        if(fun==prime3) std::cout << "Checking function prime3" << std::endl;
        using namespace std::chrono;
        auto start = std::chrono::high_resolution_clock::now();
        int * rez = fun(m,n);
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long nano = std::chrono::duration_cast<T>(elapsed).count();
        std::cout <<"It took me " << nano << " microsec (10^(-6) sec)" << std::endl;
        return rez;
}

int main()
{
        using namespace std;
        int n,m;
		cout << "The program computes prime numbers in closed [M; N]\n";
        cout << "Input M & N: ";
        cin >> m>>n;
        using namespace std::chrono;
        int * r = check<microseconds>(prime3,m,n);
        free(check<microseconds>(prime2,m,n));
        std::ofstream ofs("primes.txt");
        for(int i=0; r[i]!=0; i++)
                if(r[i]>=m)
                        ofs << r[i] << std::endl;
        free(r);
        return 0;
}
