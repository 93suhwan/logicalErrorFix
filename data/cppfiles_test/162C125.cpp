#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (T& i : a) {
    in >> i;
  }
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (T& i : a) {
    out << i << " ";
  }
  return out;
}
const long long INF = 1e18 + 7;
const int MOD = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  ;
  cin >> a;
  long long mn = INF, sm = 0;
  for (int i = 0; i < (int)(n); i++) {
    if (a[i] < mn) mn = a[i];
    sm += a[i];
  }
  auto foo = [&](long long k) {
    vector<long long> b(n);
    vector<long long> d(n);
    for (int i = 0; i < (int)(n); i++) {
      b[i] = a[i];
      d[i] = 0;
    }
    for (int i = n - 1; i >= 2; i--) {
      long long c = min(((b[i] + d[i] - k) / 3), b[i] / 3);
      if (c < 0) continue;
      d[i - 1] += c;
      d[i - 2] += c * 2;
      b[i] -= c * 3;
    }
    for (int i = 0; i < (int)(n); i++) {
      if (b[i] + d[i] < k) return false;
    }
    return true;
  };
  long long l = mn, r = (sm / n) + 1;
  while (l + 1 != r) {
    long long m = (l + r) / 2;
    if (foo(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
    cout << "\n";
  }
}
