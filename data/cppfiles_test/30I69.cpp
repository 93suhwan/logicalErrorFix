#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 200005;
int prime[1100000], primesize;
bool isprime[11000000];
long long f[N], invf[N];
long long inv[N];
void getlist(int listsize) {
  memset(isprime, 1, sizeof(isprime));
  isprime[1] = false;
  for (int i = 2; i <= listsize; i++) {
    if (isprime[i]) prime[++primesize] = i;
    for (int j = 1; j <= primesize && i * prime[j] <= listsize; j++) {
      isprime[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
}
void extend_gcd(long long a, long long b, long long& d, long long& x,
                long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    extend_gcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
void ni(int n) {
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = (mod - (mod / i)) * inv[mod % i] % mod;
  }
}
long long fpow(long long a, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (res * a) % mod;
    k >>= 1;
    a = a * a % mod;
  }
  return res;
}
long long mm(long long a, long long b) {
  long long ret = 0;
  for (a %= mod; b; b >>= 1) {
    if (b & 1) {
      ret += a;
      if (ret >= mod) ret -= mod;
    }
    a <<= 1;
    if (a >= mod) a -= mod;
  }
  return ret;
}
void init(int n) {
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = f[i - 1] * i % mod;
  }
  invf[n] = fpow(f[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) {
    invf[i] = invf[i + 1] * (i + 1) % mod;
  }
}
long long C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return f[n] * invf[k] % mod * invf[n - k] % mod;
}
char x[100005];
void solve() {
  long long n;
  cin >> n;
  cin >> x + 1;
  long long ans = 0x3f3f3f3f3f3f;
  for (int i = 0; i < 26; i++) {
    long long cnt = 0;
    int l = 1;
    int r = n;
    while (r > l) {
      if (x[l] == char(i + 'a') && x[l] != x[r]) {
        cnt++;
        l++;
      } else if (x[r] == char(i + 'a') && x[l] != x[r]) {
        cnt++;
        r--;
      } else if (x[l] != x[r]) {
        cnt = -1;
        break;
      }
      l++;
      r--;
    }
    if (cnt != -1) {
      ans = min(ans, cnt);
    }
  }
  if (ans > 1e9) {
    cout << -1 << endl;
    return;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
