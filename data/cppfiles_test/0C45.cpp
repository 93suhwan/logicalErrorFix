#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long expo(long long x, long long y, long long m) {
  long long r = 1;
  while (y) {
    if (y % 2) r = (r * x) % m;
    y /= 2;
    x = (x * x) % m;
  }
  return r;
}
void extendgcd(long long a, long long b, long long* v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mminv(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
void precision(int a) { cout << setprecision(a) << fixed; }
long long i, j;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<string, long long>> s;
  for (i = 0; i < n; i++) {
    string t;
    cin >> t;
    s.push_back({t, i});
  }
  for (i = 1; i < m; i += 2) {
    for (j = 0; j < n; j++) {
      s[j].first[i] = 'A' + ('Z' - s[j].first[i]);
    }
  }
  sort(s.begin(), s.end());
  for (i = 0; i < n; i++) cout << s[i].second + 1 << " ";
  cout << endl;
}
int main() {
  solve();
  return 0;
}
