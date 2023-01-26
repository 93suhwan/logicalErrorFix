#include <bits/stdc++.h>
using namespace std;
long long i, j, w = 0, o = 1, b = 0, c = 0, r = 0, s, k = 1, h[1000], t;
vector<string> q;
string p;
char a[3], f[3];
map<long long, long long> d, l;
int main() {
  cin >> o;
  for (i = 1; i <= o; i++) {
    cin >> b;
    r = 0;
    t = 0;
    for (j = 1; j <= b; j++) {
      cin >> h[j];
      r = r + h[j];
    }
    for (k = 2; k <= sqrt(r); k++) {
      if (r % k == 0) {
        t = 1;
        break;
      }
    }
    if (t == 0) {
      cout << b - 1 << endl;
    }
    if (t == 1) {
      cout << b << endl;
    }
    for (s = 1; s < b; s++) {
      cout << s << ' ';
    }
    if (t == 1) {
      cout << b;
    }
    cout << endl;
  }
}
