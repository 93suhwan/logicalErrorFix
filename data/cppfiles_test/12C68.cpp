#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
vector<int> soe;
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) soe.push_back(p);
}
int cal_n(int n) {
  int temp = 1;
  for (int i = 2; i <= n; i++) temp = temp * i;
  return temp;
}
int nCr(int n, int r) { return cal_n(n) / (cal_n(r) * cal_n(n - r)); }
void primefactors(int n) {
  while (n % 2 == 0) {
    n /= 2;
    cout << 2 << "\n";
  }
  for (int i = 3; i <= sqrt(n); i++) {
    while (n % i == 0) {
      cout << i << "\n";
      n /= i;
    }
  }
  if (n > 2) cout << n << "\n";
}
bool checkperfectsquare(long long n) {
  if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
    return true;
  } else {
    return false;
  }
}
long long bin_exp(long long n, long long p) {
  long long m = 1;
  while (p > 0) {
    if (p % 2 != 0) {
      m = (m * n) % mod;
      p--;
    } else {
      n = (n * n) % mod;
      p /= 2;
    }
  }
  return m;
}
int compare(char a, char b) {
  int d = abs(a - b);
  return min(d, 26 - d);
}
bool cmp(const pair<long double, long double> &a,
         const pair<long double, long double> &b) {
  return a.second < b.second;
}
int dp[100][100];
void solve() {
  int r, c, k;
  cin >> r >> c >> k;
  if (c & 1) c--;
  if (r & 1) r--, k -= c / 2;
  if (k >= 0 && k % 2 == 0 && k <= (r * c) / 2)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
