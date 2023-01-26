#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
bool notPrime[N];
vector<int> primes;
void calc_prime() {
  notPrime[1] = true;
  notPrime[2] = false;
  for (int i = 2; i * i < N; ++i) {
    if (!notPrime[i]) {
      primes.push_back(i);
      int j = i * i;
      while (j < N) {
        notPrime[j] = true;
        j += i;
      }
    }
  }
}
long long mod = 998244353;
long long cnk[5001][5001];
void prep(int k) {
  cnk[0][0] = 1;
  for (int j = 1; j <= k; ++j) {
    cnk[j][0] = 1;
    for (int i = 1; i <= j; ++i) {
      cnk[j][i] = (cnk[j - 1][i - 1] + cnk[j - 1][i]) % mod;
    }
  }
}
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 1 << endl;
    return 0;
  }
  prep(n);
  string s;
  cin >> s;
  long long ans = 0;
  vector<long long> p(n);
  long long pref = 0;
  for (int i = 0; i < n; ++i) {
    p[i] = pref;
    if (s[i] == '1') {
      ++p[i];
    }
    pref = p[i];
  }
  int l = -1, r = -1;
  for (int(i) = 0; (i) < (n); ++(i)) {
    if (p[i] == k) {
      r = i;
      l = 0;
    }
  }
  if (l == -1) {
    cout << 1 << endl;
    return 0;
  }
  ans += cnk[r - l + 1][k];
  int pr = r, pl = l;
  vector<long long> a;
  a.push_back(ans);
  while (r < n - 1) {
    ++r;
    while (r < n - 1 && s[r + 1] == '0') {
      ++r;
    }
    while (s[l] != '1') {
      ++l;
    }
    ++l;
    if (l > pr) {
      ans = (ans + cnk[r - l + 1][k]) % mod;
      ans = (ans + mod - 1) % mod;
      a.push_back(ans);
      pr = r;
      pl = l;
      continue;
    }
    long long cur = cnk[pr - l + 1][k - 1];
    long long nw = cnk[r - l + 1][k];
    ans += (nw - cur + mod) % mod;
    ans %= mod;
    pr = r;
    pl = l;
  }
  cout << ans << endl;
}
