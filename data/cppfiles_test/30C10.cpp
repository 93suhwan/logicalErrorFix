#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
long long gcd(long long a, long long b) {
  if (!a) return b;
  return gcd(b % a, a);
}
long long power(long long a, long long b) {
  long long flip = 1;
  while (b > 0) {
    if (b & 1) {
      flip = (flip * a);
    }
    a = (a * a);
    b >>= 1;
  }
  return flip;
}
vector<long long> spf, prime;
void primes(long long n) {
  spf.assign(n + 1, 0);
  spf[1] = 1;
  for (long long i = 2; i <= n; i++) {
    if (!spf[i]) {
      spf[i] = i;
      prime.push_back(i);
      for (long long j = i * i; j <= n; j += i)
        if (!spf[j]) spf[j] = i;
    }
  }
}
priority_queue<long long, vector<long long>, greater<long long> > qqqqq;
void solve() {
  long long n, i;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 1e8;
  for (i = 0; i < 26; i++) {
    long long var = 0, j = 0, k = n - 1;
    int fl = 0;
    while (j < k) {
      if ((s[j] - 'a') != i) {
        while (j < k) {
          if (s[k] != s[j] && (s[k] - 'a') != i) {
            fl = 1;
            break;
          }
          if (s[k] == s[j]) {
            break;
          }
          k--;
          var++;
        }
      } else if ((s[k] - 'a') != i) {
        while (j < k) {
          if (s[k] != s[j] && (s[j] - 'a') != i) {
            fl = 1;
            break;
          }
          if (s[k] == s[j]) {
            break;
          }
          j++;
          var++;
        }
      }
      if (fl) break;
      j++;
      k--;
    }
    if (fl == 0) ans = min(ans, var);
  }
  if (ans == 1e8)
    cout << "-1\n";
  else
    cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
