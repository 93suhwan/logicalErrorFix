#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 11;
const long long M = 1e6 + 21;
const long long big = 1e17;
const long long hsh2 = 1964325029;
const long long mod = 1e9 + 7;
const double EPS = 1e-9;
const long long block = 400;
const long long shift = 2e3;
const double pi = acos(-1.0);
mt19937_64 bruh(chrono::steady_clock::now().time_since_epoch().count());
long long n;
long long a[N];
long long dp[512];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i <= 511; i++) dp[i] = 501;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j < 512; j++) {
      if (a[i] > dp[j]) dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
    }
  }
  long long cnt = 0;
  for (int i = 0; i <= 511; i++) cnt += (dp[i] != 501);
  cout << cnt << '\n';
  for (int i = 0; i <= 511; i++)
    if (dp[i] != 501) cout << i << " ";
  cout << '\n';
}
