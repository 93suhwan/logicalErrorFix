#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 5LL;
const long long inf32 = INT_MAX;
const long long mod = 998244353;
const long double eps = 1e-9;
const long long N = (1e6 + 10);
void solve(long long t);
void solve();
void ITO();
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ITO();
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) solve(i + 1);
  return 0;
}
void solve(long long TcNumber) {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  while (!a.empty()) {
    long long i = n - 1;
    for (; i >= 0; i--) {
      if (a[i] % (i + 2) != 0) break;
    }
    if (i == -1) {
      break;
    }
    a.erase(a.begin() + i);
    n--;
  }
  if (a.empty())
    cout << "YES";
  else
    cout << "NO";
  cout << "\n";
  return;
}
void solve() {}
void ITO() {}
