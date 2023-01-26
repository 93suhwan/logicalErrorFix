/*made by VladimirZwezdin*/

#include <bits\stdc++.h>

#define FOR(x, y) for(ll i = x; i < y; i++)
#define F0R(x) FOR(0,x)
#define vt vector
#define pr pair<int,int>
typedef long long ll;
using namespace std;
//____________________________________________________________________________________________________________________________________________________________________________________________________________________________________

void solve() {
    int n;
    cin >> n;
    int c0 = 0;
    int c1 = 0;
    F0R(n) {
        ll tmp;
        cin >> tmp;
        if (tmp == 0) c0++;
        if (tmp == 1) c1++;
    }
    cout << pow(2, c0) * c1 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
