#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
const long double pi = acos(-1);
int xc[] = {0, -1, 0, 1, -1, -1, 1, 1};
int yc[] = {1, 0, -1, 0, -1, 1, -1, 1};
string Q;
long long bpow(long long n, long long x) {
  return x <= 0 ? 1 : bpow(n * n % mod, x / 2) % mod * (x % 2 ? n : 1) % mod;
}
long long modinverse(long long b) { return bpow(b, mod - 2); }
long long factN = 1e4 + 1;
vector<long long> fact(factN, 1);
void factinit() {
  for (int i = 1; i < factN; ++i) {
    fact[i] = i * fact[i - 1];
    fact[i] %= mod;
  }
}
void solve(long long tc) {
  factinit();
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<long long> v(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == '1') v[i] = 1;
    v[i] += v[i - 1];
  }
  if (!k || k > v[n]) {
    cout << "1\n";
    return;
  }
  long long sum = 0, oldj = 0;
  for (int i = 0, j = 1; i <= n;) {
    while (j <= n && v[j] - v[i] <= k) j++;
    j--;
    if (v[j] - v[i] < k) break;
    sum += fact[j - i] * modinverse(fact[k]) % mod *
           modinverse(fact[j - i - k]) % mod;
    if (oldj != 0)
      sum -= fact[oldj - i] * modinverse(fact[k - 1]) % mod *
             modinverse(fact[oldj - i - (k - 1)]) % mod;
    oldj = j;
    while (i <= n && v[j] - v[i] == k) i++;
  }
  cout << (sum % mod + mod) % mod << "\n";
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  ;
  long long t = 1, tc = 1;
  while (t--) solve(tc++);
  return 0;
}
