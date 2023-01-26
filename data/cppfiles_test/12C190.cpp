#include <bits/stdc++.h>
using namespace std;
long long solve();
vector<long long> a;
string s;
long long n;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
long long in(vector<long long> &a, long long n) {
  long long i = 0, x, sum = 0;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back({x});
  }
  return sum;
}
long long solve() {
  a.clear();
  s.clear();
  long long i = 0, j = 0, k = 0;
  long long flag = 0;
  long long x = 0, y = 0, z = 0;
  cin >> n;
  long long m;
  cin >> m;
  cin >> k;
  long long hor = k;
  long long ver = n * m;
  ver /= 2;
  ver -= k;
  if (n & 1) {
    x = m / 2;
    if (hor < x) {
      cout << "NO" << endl;
      return 0;
    }
    hor -= x;
    n--;
  }
  if (m & 1) {
    x = n / 2;
    if (ver < x) {
      cout << "NO" << endl;
      return 0;
    }
    ver -= x;
    m--;
  }
  if (ver & 1) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
