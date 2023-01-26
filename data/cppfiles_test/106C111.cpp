#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e3;
const long long MOD = 123456789;
const long long INF = 1e9;
long long n, k, m;
long long a[MAX][MAX];
long long dp[MAX];
void solve() {
  cin >> n;
  if (n == 1)
    cout << 1;
  else
    for (long long i = 2; i <= n + 1; i++) {
      cout << i << " ";
    }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int test = 1;
  cin >> test;
  while (test--) solve();
  return 0;
}
