#include <bits/stdc++.h>
using namespace std;
const bool DEBUG = true;
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> p) {
  os << "{" << p.first << ", " << p.second << "}";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> a) {
  os << "[";
  for (int i = 0; i < a.size() - 1; i++) {
    os << a[i] << ", ";
  }
  os << a[a.size() - 1] << "]";
  return os;
}
template <typename T>
void debug(T obj) {
  if (DEBUG == true) {
    cout << obj << "\n";
  }
}
void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> su(n + 1);
  su[0] = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      if (s[i] == '+') {
        su[i + 1] = su[i] + 1;
      } else {
        su[i + 1] = su[i] - 1;
      }
    } else {
      if (s[i] == '+') {
        su[i + 1] = su[i] - 1;
      } else {
        su[i + 1] = su[i] + 1;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    int sum = su[r + 1] - su[l];
    int len = r - l + 1;
    if (sum == 0)
      cout << 0 << "\n";
    else if (len % 2 == 1)
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
