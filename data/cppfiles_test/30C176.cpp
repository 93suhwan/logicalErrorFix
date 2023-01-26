#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
long long select(vector<long long>& a, long long k) {
  for (long long l = 0, r = a.size() - 1; l <= r;) {
    long long p = a[(l + r) / 2];
    long long i = l - 1, j = r + 1;
    while (1) {
      while (a[++i] < p)
        ;
      while (a[--j] > p)
        ;
      if (i >= j) break;
      swap(a[i], a[j]);
    }
    if (k == i - l)
      return a[i];
    else if (k < i - l) {
      r = i - 1;
    } else if (k > i - l) {
      k -= (i - l + 1);
      l = j + 1;
    }
  }
  return -99999999;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}
vector<pair<long long, long long>> prim;
void pf(long long n) {
  long long s = sqrt(n);
  long long r = 0;
  for (long long i = 2; i <= s; i++) {
    if ((n % i) == 0) {
      r = 0;
      do {
        r++;
        n = n / i;
      } while ((n % i) == 0);
      prim.push_back({i, r});
    }
  }
  if (n > s) {
    prim.push_back({n, 1});
  }
}
long long powmod(int a, int n) {
  long long x = 1;
  while (n > 0) {
    if (n & 1) {
      x = (x * a) % (long long)(1e9 + 7);
    }
    a = (a * a) % (long long)(1e9 + 7);
    n >>= 1;
  }
  return x;
}
void solve() {
  long long N;
  cin >> N;
  string s;
  cin >> s;
  vector<string> cs(30);
  vector<string> csr(30);
  long long ans = -1;
  for (long long j = 0; j < (26); j++) {
    char ch = j + 'a';
    for (long long i = 0; i < (N); i++) {
      if (s[i] != ch) {
        cs[j] += s[i];
      }
    }
    csr[j] = cs[j];
    reverse(csr[j].begin(), csr[j].end());
    if (csr[j] != cs[j]) continue;
    long long cnt = 0;
    long long x1 = 0;
    long long x2 = N - 1;
    while (x2 - x1 >= 1) {
      if (s[x1] == s[x2]) {
        x1++;
        x2--;
      } else if (s[x1] == ch) {
        x1++;
        cnt++;
      } else if (s[x2] == ch) {
        x2--;
        cnt++;
      }
    }
    if (ans < 0 || ans > cnt) ans = cnt;
  }
  cout << ans << endl;
}
int main(void) {
  long long t;
  cin >> t;
  for (long long i = 0; i < (t); i++) solve();
}
