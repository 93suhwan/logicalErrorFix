#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
const long long MaxM = 9 * 1e15;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
long long SieveOfEratosthenes(vector<long long> &v, long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p] && n % p != 0) {
      return p;
    }
  return -1;
}
long long proo(long long a, long long b, long long c) {
  return ((a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a));
}
void solve() {
  long long n;
  cin >> n;
  long long x;
  long long ans = 0;
  vector<vector<long long>> v(n, vector<long long>(5));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    bool ok = true;
    int c = 0;
    for (int k = 0; k < 5; k++) {
      if (v[ans][k] < v[i][k]) {
        c++;
      }
    }
    if (c < 3) {
      ans = i;
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (i == ans) {
      continue;
    }
    int c = 0;
    for (int k = 0; k < 5; k++) {
      if (v[ans][k] < v[i][k]) {
        c++;
      }
    }
    if (c < 3) {
      ok = false;
      break;
    }
  }
  ans++;
  if (ok) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
  }
}
int main() {
  fast();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
