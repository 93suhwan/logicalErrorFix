#include <bits/stdc++.h>
using namespace std;
long long t, n, a, b, k, k1, k2;
string s, s1;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> s;
    k1 = -1;
    k2 = -1;
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        k1 = i;
        k2 = i + 1;
      }
    }
    cout << k1 << ' ' << k2 << endl;
  }
  return 0;
}
