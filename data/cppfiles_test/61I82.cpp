#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  bool HAST = true;
  if (HAST) {
    int t;
    cin >> t;
    for (int tt = 0, _tt = (t); tt < _tt; ++tt) {
      solve();
      cout << '\n';
      cout.flush();
    }
  } else {
    solve();
  }
}
long long sumpow(vector<long long> &a, int pow) {
  long long sum = 0;
  for (int i = 0, _i = (int((a).size())); i < _i; ++i) {
    long long t = a[i];
    if (pow > 1) t *= a[i];
    if (pow > 2) t *= a[i];
    sum += t;
  }
  return sum;
}
long long sum3(vector<long long> &a) {
  long long s1 = sumpow(a, 1);
  long long s2 = sumpow(a, 2);
  long long s3 = sumpow(a, 3);
  long long sol = (s1 * s1 * s1 - 3 * s1 * s2 + 2 * s3) / 6;
  return sol;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0, _i = (n); i < _i; ++i) cin >> a[i] >> b[i];
  vector<long long> top(n + 1), dif(n + 1);
  for (int i = 0, _i = (n); i < _i; ++i) {
    top[a[i]]++;
    dif[b[i]]++;
  }
  long long nonvalid = 0;
  for (int i = 0, _i = (n); i < _i; ++i) {
    nonvalid += (top[a[i]] - 1) * (dif[b[i]] - 1);
  }
  long long sol = n * (n - 1) * (n - 2) / 6;
  sol -= nonvalid;
  cout << sol;
  cout.flush();
}
