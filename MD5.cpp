//
// Created by steve on 18-9-25.
//

#include <iostream>

int f(int b, int c, int d);
int g(int b, int c, int d);

using namespace std;

void FF(int &a, int b, int c, int d, int mk, int s, int ti) {
    int temp = b + ((a + f(b, c, d) + mk + ti));
    a = (temp << s) + (temp & (1 << (s - 1)));
    cout << a << endl;
}

void GG(int &a, int b, int c, int d, int mk, int s, int ti) {
    int temp = b + ((a + g(b, c, d) + mk + ti));
    a = (temp << s) + (temp & (1 << (s - 1)));
    printf("%x\n",a);
}

int f(int x, int y, int z) {
    return (x & y) | (~x & z);
}

int g(int x, int y, int z) {
    printf("%x\n",(x & z) | (y & ~z));
    return (x & z) | (y & ~z);
}


int main() {
    int A = 0x2B480E7C, B = 0xDAEAB5EF, C = 0x2E87BDD9, D = 0x91D9BEE8;
    GG(A,B,C,D,0x31323334,5,0xF61E2562);
    return 0;
}