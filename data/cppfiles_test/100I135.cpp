#include <bits/stdc++.h>
using namespace std;
long long int fact[200009];
long long int M = 998244353;
void fac() {
  fact[0] = 1;
  for (long long int i = 1; i < 200003; i++) {
    fact[i] = fact[i - 1] * (i);
    fact[i] %= M;
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  long long int cnt = 0;
  if ((a[n - 1] - a[n - 2]) >= 2) {
    cout << "0\n";
    return;
  }
  map<long long int, long long int> m;
  cnt = 1;
  set<long long int> ss;
  for (long long int i = 0; i < n; i++) {
    m[a[i]]++;
    ss.insert(a[i]);
  }
  cnt = fact[n];
  if (m[a[n - 1]] > 1) {
    cout << cnt << "\n";
    return;
  }
  auto it = ss.end();
  it--;
  auto it2 = it;
  it2--;
  long long int c = n - (m[*it] + m[*it2]);
  for (long long int i = n - 1; i >= 0; i--) {
    if (c < n - i - 1) continue;
    long long int pp = ((fact[i]) * (fact[n - i - 1]));
    long long int pp2 = (fact[c]);
    long long int pp3 = (fact[n - i - 1] * fact[c - n + i + 1]);
    pp2 %= M;
    pp3 %= M;
    pp %= M;
    pp2 = pp2 / pp3;
    pp2 %= M;
    cnt -= (pp * pp2);
    cnt %= M;
  }
  cout << cnt << "\n";
}
int main() {
  fac();
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
