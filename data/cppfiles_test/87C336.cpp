#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using ld = long double;
using pii = pair<int, int>;
ll t, n, v, d, a, x;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    v = 1;
    a = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      if (x > v) {
        a += x - v;
        v = x;
      }
      v++;
    }
    cout << a << '\n';
  }
}
