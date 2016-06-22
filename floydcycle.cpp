#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define f(x, p, q) ((x*p) + q)

using namespace std;
typedef unsigned long long ULONG;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, s, p, q;
    cin >> n >> s >> p >> q;
    ULONG p_231 = static_cast<ULONG>(pow(2,31));
    ULONG x0 = s % p_231;
    ULONG vals = 1;
    ULONG tor = f(x0, p, q) % p_231;
    ULONG hare = f(tor, p, q) % p_231;
    
    while(tor != hare) {
        if(vals >= n) {
            cout << n << endl;
            return 0;
        } else vals++;
        tor = f(tor, p, q) % p_231;
        hare = f(hare, p, q) % p_231;
        hare = f(hare, p, q) % p_231;
    }
    
    ULONG mu = 0;
    tor = x0;
    while(tor != hare) {
        tor = f(tor, p, q) % p_231;
        hare = f(hare, p, q) % p_231;
        mu += 1;
    }
    
    ULONG lam = 1;
    hare = f(hare, p, q) % p_231;
    while(hare != tor){ 
        hare = f(hare, p, q) % p_231;
        lam += 1;
    }
    
    cout << lam + mu << endl;
    
    return 0;
}
