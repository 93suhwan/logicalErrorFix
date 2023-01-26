#include <bits/stdc++.h>
using namespace std;
long long int fastpow(long long int a, long long int p) {
  long long int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % 1000000007;
      p /= 2;
    } else {
      res = res * 1ll * a % 1000000007;
      p--;
    }
  }
  return res;
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 1; i <= n; i++) {
    res = res * 1ll * i % 1000000007;
  }
  return res;
}
long long int comb(long long int n, long long int k) {
  return fact(n) * 1ll * fastpow(fact(k), 1000000007 - 2) % 1000000007 * 1ll *
         fastpow(fact(n - k), 1000000007 - 2) % 1000000007;
}
long long int to_integer(string &aa) {
  long long int res = 0;
  for (auto x : aa) res = (res * 10) + (x - '0');
  return res;
}
bool prime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void sieve(long long int n, vector<long long int> prime) {
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int l, br;
    cin >> l >> br;
    vector<pair<long long int, long long int>> v;
    v.push_back({w, b});
    v.push_back({w - c, h});
    v.push_back({w, h - d});
    v.push_back({a, h});
    long double ans = 1e18;
    long long int f = 0;
    long long int i = 0;
    for (auto x : v) {
      if (i == 0) {
        if (d - b + br > h) {
          i++;
          continue;
        }
      } else if (i == 1) {
        if (c - a + l > w) {
          i++;
          continue;
        }
      } else if (i == 2) {
        if (d - b + br > h) {
          i++;
          continue;
        }
      } else if (i == 3) {
        if (c - a + l > w) {
          i++;
          continue;
        }
      }
      i++;
      long long int ff = x.first, ss = x.second;
      long double base = 0, perp = 0;
      if (l > ff) {
        base = l - ff;
      }
      if (br > ss) {
        perp = br - ss;
      }
      if (base > w || perp > h) {
      }
      f = 1;
      long double tmp = sqrt(base * base + perp * perp);
      ans = min(ans, tmp);
    }
    if (f == 0)
      cout << "-1\n";
    else
      cout << fixed << setprecision(10) << ans << "\n";
  }
}
