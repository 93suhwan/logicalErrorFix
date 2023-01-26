#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 2e5 + 10;
bool isPrime[MAXN + 10];
vector<long long int> primes;
void seive() {
  for (long long int i = 0; i <= MAXN; ++i) isPrime[i] = true;
  for (long long int i = 2; i * i <= MAXN; ++i) {
    for (long long int j = i * i; j <= MAXN; j += i) {
      isPrime[j] = false;
    }
  }
  for (long long int i = 2; i <= MAXN; ++i) {
    if (isPrime[i]) primes.push_back(i);
  }
}
long long int modular_expo(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int result = modular_expo(a, b / 2);
  result = (result * result);
  if (b % 2 == 1) result = (result * a);
  return result;
}
void solve() {
  long long int n, m, k;
  string ans;
  cin >> n >> m >> k;
  if (n * (n - 1) / 2 < m || n - 1 > m)
    ans = "NO";
  else if ((k <= 1 && n == 1))
    ans = "NO";
  else if ((k <= 2 && n == 2))
    ans = "NO";
  else if ((n >= 3 && (m < n * (n - 1) / 2 && k <= 3) ||
            (m >= n * (n - 1) / 2 && k <= 2)) ||
           (n - 1 > m))
    ans = "NO";
  else
    ans = "YES";
  cout << ans << endl;
}
int32_t main() {
  long long int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
