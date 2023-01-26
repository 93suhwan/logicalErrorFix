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
  int c = 0;
  long long ans = 1;
  vector<long long> p(n);
  long long pref = 0;
  for (int i = 0; i < n; ++i) {
    p[i] = pref;
    if (s[i] == '1') {
      ++p[i];
    }
    pref = p[i];
  }
  int l, r;
  for (int(i) = 0; (i) < (n); ++(i)) {
    if (p[i] == k) {
      r = i;
      l = 0;
      break;
    }
  }
  ans += cnk[r - l + 1][k];
  int pr = r, pl = l;
  ++r;
  vector<long long> a;
  a.push_back(1);
  while (r < n) {
    if (s[r] == '1') {
      while (s[l] != '1') {
        ++l;
      }
      ++l;
    }
    if (l > pr) {
      ans = (ans + cnk[r - l + 1][k]) % mod;
      ++r;
      a.push_back(ans);
      continue;
    }
    c = 0;
    char q = s[r];
    for (int j = l; j < r; ++j) {
      if (s[j] == q) {
        ++c;
      }
    }
    ans = (ans + cnk[r - l][c + 1]) % mod;
    a.push_back(ans);
    ++r;
  }
  cout << ans << endl;
}
