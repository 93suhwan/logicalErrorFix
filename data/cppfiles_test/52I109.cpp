#include <bits/stdc++.h>
using namespace std;
int n, k, t;
map<int, int> m;
long long s, ss;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i >= 0; i++) {
      if (k == 1) {
        m[i] = 1;
        ss = pow(n, i);
        ss %= 1000000007;
        s += ss;
        ss = 0;
        break;
      }
      if (k % 2 == 1) {
        m[i] = 1;
        ss = pow(n, i);
        ss %= 1000000007;
        s += ss;
        ss = 0;
      }
      k /= 2;
    }
    s %= 1000000007;
    cout << s << '\n';
    s = 0;
  }
}
