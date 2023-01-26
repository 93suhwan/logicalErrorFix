#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  long long k = a + b;
  long long x = (k + 1) / 2, y = (k / 2);
  long long l = k - min(x, a) - min(b, y);
  long long r = min(x, b) + min(a, y);
  set<long long> s;
  for (long long i = l; i <= r; i += 2) {
    s.insert(i);
  }
  x = k / 2;
  y = (k + 1) / 2;
  l = k - min(x, a) - min(b, y);
  r = min(x, b) + min(a, y);
  for (long long i = l; i <= r; i += 2) {
    s.insert(i);
  }
  cout << (long long)s.size() << '\n';
  for (auto p : s) {
    cout << p << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
