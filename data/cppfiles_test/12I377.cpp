#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
const long double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX;
const long long SIZE = 100000;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 1) {
    long long some = m / 2;
    if (k < some) {
      cout << "NO" << endl;
      return;
    }
    k -= some;
    if (k % 2 == 0) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
    return;
  }
  long long some = m / 2;
  if (k % 2 == 0) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
