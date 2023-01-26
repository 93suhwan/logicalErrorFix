#include <bits/stdc++.h>
using namespace std;
const long long int MOD = (long long int)1e9 + 7;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b = b >> 1;
  }
  return res % MOD;
}
void solve(long long int testnum) {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> a(n), b(n, 0);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (long long int i = 0; i < n; i++) {
    long long int tmp = (n + i - a[i]) % n;
    b[tmp]++;
  }
  long long int cnt = 0;
  for (long long int i = 0; i < n; i++) {
    if (b[i] >= n - 2 * m) {
      cnt++;
    }
  }
  cout << cnt << " ";
  for (long long int i = 0; i < n; i++) {
    if (b[i] >= n - 2 * m) {
      cout << i << " ";
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve(i);
  }
}
