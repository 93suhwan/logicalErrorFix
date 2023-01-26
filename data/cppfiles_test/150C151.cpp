#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& p) {
  return out << "(" << p.x << ", " << p.y << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  for (int i = int(0); i < int(int((v).size())); i++) {
    if (i) out << " ";
    out << v[i];
  }
  return out;
}
int n;
vector<int> a;
inline bool read() {
  if (!(cin >> n)) return false;
  a.resize(n);
  for (int i = int(0); i < int(n); i++) cin >> a[i];
  return true;
}
bool p(int val, int c1, int c2, int c3) {
  for (int cur1 = int(0); cur1 < int(c1 + 1); cur1++)
    for (int cur2 = int(0); cur2 < int(c2 + 1); cur2++) {
      if (cur1 + 2 * cur2 > val) continue;
      if ((val - cur1 - 2 * cur2) % 3 != 0) continue;
      if ((val - cur1 - 2 * cur2) / 3 <= c3) return true;
    }
  return false;
}
bool possible(int c1, int c2, int c3) {
  for (int v : a) {
    if (!p(v, c1, c2, c3)) return false;
  }
  return true;
}
inline void solve() {
  int m = *max_element(a.begin(), a.end());
  int ans = int(1e9);
  const int MAG = 3;
  for (int c1 = int(0); c1 < int(MAG); c1++)
    for (int c2 = int(0); c2 < int(MAG); c2++) {
      int c3 = max(0, (m - c1 - 2 * c2 + 2) / 3);
      assert(c1 + 2 * c2 + 3 * c3 >= m);
      if (possible(c1, c2, c3)) ans = min(ans, c1 + c2 + c3);
    }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    read();
    solve();
  }
  return 0;
}
