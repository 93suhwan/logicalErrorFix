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
long long int D, X, Y;
void extendedEuclid(long long int A, long long int B) {
  if (B == 0) {
    D = A;
    X = 1;
    Y = 0;
  } else {
    extendedEuclid(B, A % B);
    int temp = X;
    X = Y;
    Y = temp - (A / B) * Y;
  }
}
long long int modInverse(long long int A) {
  extendedEuclid(A, M);
  return (X % M + M) % M;
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
  long long int c;
  c = n - 1 - m[a[n - 2]];
  cnt = 0;
  for (long long int i = 0; i < c + 1; i++) {
    long long int pp = ((fact[i]) * (fact[n - i - 1]));
    long long int pp2 = (fact[c]);
    long long int pp3 = (fact[i] * fact[c - i]);
    pp2 %= M;
    pp3 %= M;
    pp %= M;
    pp3 = modInverse(pp3);
    pp2 *= pp3;
    pp2 %= M;
    cnt = (cnt + (pp * pp2) + M);
    ;
    cnt %= M;
  }
  cnt = (fact[n] - cnt + M);
  cnt %= M;
  cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  fac();
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
