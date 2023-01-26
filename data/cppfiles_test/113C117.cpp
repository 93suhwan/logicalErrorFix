#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _print(vector<T> &v) {
  for (auto i : v) cout << i << " ";
  cout << endl;
}
template <typename T>
void _print(vector<vector<T>> &v) {
  for (auto i : v) {
    for (auto j : i) cout << j << " ";
    cout << endl;
  }
}
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
  cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl;
  return 0;
}
void solve() {
  int x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  string s1 = to_string(x1);
  string s2 = to_string(x2);
  int l1 = s1.size(), l2 = s2.size();
  if (l1 + p1 > l2 + p2) {
    cout << ">" << endl;
  } else if (l1 + p1 < l2 + p2) {
    cout << "<" << endl;
  } else {
    if (l1 < l2) {
      x1 *= pow(10, l2 - l1);
    } else if (l1 > l2)
      x2 *= pow(10, l1 - l2);
    if (x1 > x2)
      cout << ">" << endl;
    else if (x1 < x2)
      cout << "<" << endl;
    else
      cout << "=" << endl;
  }
}
