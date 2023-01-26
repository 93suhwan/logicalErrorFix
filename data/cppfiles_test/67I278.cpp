#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using str = string;
template <class T>
using V = vector<T>;
template <class T1, class T2>
using umap = unordered_map<T1, T2>;
using pi = pair<int, int>;
using vi = V<int>;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a < b) swap(a, b);
    ll fin = -1;
    bool ans = true;
    if (a - b == b - 1 || a - b == 1) ans = false;
    ll x = a - b + 1;
    ll tot = 2 * (x - 1);
    if (c <= tot) {
      ll ans = a - b + c;
      ll ans2 = c - (a - b);
      if (ans <= tot && ans != a && ans != b && ans > 0) fin = ans;
      if (ans2 <= tot && ans2 != a && ans2 != b && ans2 > 0) fin = ans2;
    }
    cout << (ans ? fin : -1) << "\n";
  }
  return 0;
}
