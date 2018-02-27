#include <iostream>
using namespace std;

/*const int m = 100000;
const int n = 1000000;
const int y = 10;*/

/*const int m = 9;
const int n = 10;
const int y = 4;*/

const int m = 20;
const int n = 6;
const int y = 16;

/*(x^n)%m*/
//A^B mod C = ( (A mod C)^B ) mod C
int modPower(long long x, unsigned int n, int m)
{
    x = x % m;
    int res = 1;

    //cout << x << "%" << m << "=" << x%m << endl;
    /*for (int i = 0; i < sizeof(int) * 8; i++) {
        int least_sig_bit = 0x00000001 & (n >> i);
        if (least_sig_bit){
            res = (res * x) % m;
        }
        x = (x * x) % m;
        cout << "x = " << x << endl;
    }*/

    while (n > 0){
        if (n%2==1){
            res *= x;
            res = res%m;
        }
        n /= 2;
        x = x * x;
    }

    return res;
}

int main() {

    for (int x = 1; x < m; x++){
        // Still overflows with big numbers :(
        int res = modPower(x, n, m);
        if (res == y){
            cout << x << "^" << n << "%" << m << "=" << y << endl;
        }
    }

    return 0;
}