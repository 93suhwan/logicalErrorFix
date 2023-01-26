#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5, inf = 1e18, mod = 1e9 + 7;
const long double pi = 3.141592653589793238;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long testcases;
  cin >> testcases;
  while (testcases--) {
    long long a, b, m1, m2, ma, k, i;
    cin >> a >> b;
    k = a + b - 2 * min(a, b);
    if (k % 2 == 0) {
      m1 = (k / 2);
      m2 = (k / 2);
    } else {
      m1 = (k / 2);
      m2 = m1 + 1;
    }
    ma = 2 * min(a, b) + m2;
    set<long long> s;
    for (i = m1; i <= ma; i += 2) {
      s.insert(i);
    }
    for (i = m2; i <= ma; i += 2) {
      s.insert(i);
    }
    cout << s.size() << "\n";
    for (auto x : s) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}
