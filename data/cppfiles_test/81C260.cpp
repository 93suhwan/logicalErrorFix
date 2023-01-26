#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < (int)v.size(); ++i) {
    os << v[i];
    if (i != (int)v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "[";
  os << p.first;
  os << ", ";
  os << p.second;
  os << "]";
  return os;
}
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
long long binpow(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long t = binpow(a, b / 2, p);
  if (b % 2)
    return (((a * t) % p) * t) % p;
  else
    return ((t * t) % p);
}
void solve() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> od(n + 1, 0), ev(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if ((i + 1) % 2) {
      od[i + 1] = od[i] + (s[i] == '+' ? 1 : -1);
      ev[i + 1] = ev[i];
    } else {
      ev[i + 1] = ev[i] + (s[i] == '+' ? 1 : -1);
      od[i + 1] = od[i];
    }
  }
  42;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "1\n";
      continue;
    }
    long long x, y;
    if (l % 2) {
      x = od[r] - od[l - 1], y = ev[r] - ev[l - 1];
    } else {
      y = od[r] - od[l - 1], x = ev[r] - ev[l - 1];
    }
    if (x - y == 0)
      cout << "0\n";
    else if (abs(x - y) % 2 == 1)
      cout << "1\n";
    else
      cout << "2\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
