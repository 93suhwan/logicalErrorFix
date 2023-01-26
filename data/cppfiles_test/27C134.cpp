#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
long long power(long long a, long long b) {
  long long result = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      result *= a;
    }
    a *= a;
    b /= 2;
  }
  return result;
}
long long gcd(long long x, long long y) {
  long long r;
  while (y != 0 && (r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y == 0 ? x : y;
}
long long countSetBits(long long x) {
  long long Count = 0;
  while (x > 0) {
    if (x & 1) Count++;
    x = x >> 1;
  }
  return Count;
}
bool isPerfectSquare(long long n) {
  long long sr = sqrt(n);
  if (sr * sr == n)
    return true;
  else
    return false;
}
long long mod(long long x, long long M) { return ((x % M + M) % M); }
long long add(long long a, long long b, long long M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long mul(long long a, long long b, long long M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long powerM(long long a, long long b, long long M) {
  long long res = 1ll;
  while (b) {
    if (b % 2ll == 1ll) {
      res = mul(a, res, M);
    }
    a = mul(a, a, M);
    b /= 2ll;
  }
  return res;
}
long long mod_inv(long long a, long long m) {
  long long g = m, r = a, x = 0, y = 1;
  while (r != 0) {
    long long q = g / r;
    g %= r;
    swap(g, r);
    x -= q * y;
    swap(x, y);
  }
  return mod(x, m);
}
long long nCr(long long n, long long k) {
  if (n < k) return 0;
  if (k == 0) return 1;
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
long long modInverse(long long n, long long M) { return powerM(n, M - 2, M); }
vector<long long> factu;
void factcalc(long long n, long long M) {
  factu.resize(n + 1);
  factu[0] = 1;
  for (long long i = 1; i <= n; i++) {
    factu[i] = mul(factu[i - 1], i, M);
  }
}
long long nCrM(long long n, long long r, long long M) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return mul(mul(factu[n], modInverse(factu[r], M), M),
             modInverse(factu[n - r], M), M);
}
long long rand_int(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
void solve() {
  string s, t;
  cin >> s >> t;
  long long n = s.length();
  long long m = t.length();
  long long x0 = -1, x1 = -1;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0 && x0 == -1 && s[i] == t[0]) {
      x0 = i;
    }
    if (i % 2 == 1 && x1 == -1 && s[i] == t[0]) {
      x1 = i;
    }
  }
  vector<vector<long long> > v0(26), v1(26);
  for (long long i = x0 + 1; i < n; i++) {
    v0[s[i] - 'a'].push_back(i);
  }
  for (long long i = 0; i < 26; i++) {
    reverse(v0[i].begin(), v0[i].end());
  }
  for (long long i = x1 + 1; i < n; i++) {
    v1[s[i] - 'a'].push_back(i);
  }
  for (long long i = 0; i < 26; i++) {
    reverse(v1[i].begin(), v1[i].end());
  }
  if (x0 != -1) {
    long long f = 0;
    for (long long i = 1; i < m; i++) {
      long long op = 1;
      while (v0[t[i] - 'a'].size() > 0) {
        if (v0[t[i] - 'a'].back() > x0 && v0[t[i] - 'a'].back() % 2 != x0 % 2) {
          op = 0;
          x0 = v0[t[i] - 'a'].back();
          v0[t[i] - 'a'].pop_back();
          break;
        } else {
          v0[t[i] - 'a'].pop_back();
        }
      }
      if (op) {
        f = 1;
      }
    }
    if (f == 0) {
      if (x0 % 2 != n % 2) {
        cout << "YES\n";
        return;
      }
    }
  }
  if (x1 != -1) {
    long long f = 0;
    for (long long i = 1; i < m; i++) {
      long long op = 1;
      while (v1[t[i] - 'a'].size() > 0) {
        if (v1[t[i] - 'a'].back() > x1 && v1[t[i] - 'a'].back() % 2 != x1 % 2) {
          op = 0;
          x1 = v1[t[i] - 'a'].back();
          v1[t[i] - 'a'].pop_back();
          break;
        } else {
          v1[t[i] - 'a'].pop_back();
        }
      }
      if (op) {
        f = 1;
      }
    }
    if (f == 0) {
      if (x1 % 2 != n % 2) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(20);
  long long t = 0;
  cin >> t;
  while (t--) solve();
  return 0;
}
