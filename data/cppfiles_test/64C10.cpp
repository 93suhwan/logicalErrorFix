#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 5e5 + 50;
const long long base = 10;
long long f[maxn][2][2];
long long mod[2];
long long mu[maxn][2];
pair<long long, long long> get(long long l, long long r, long long id) {
  return make_pair(
      ((f[r][0][id] - f[l - 1][0][id] * mu[r - l + 1][0]) % mod[0] + mod[0]) %
          mod[0],
      ((f[r][1][id] - f[l - 1][1][id] * mu[r - l + 1][1]) % mod[1] + mod[1]) %
          mod[1]);
}
void add(string s, long long n, long long id) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      f[i][j][id] = (f[i - 1][j][id] * base + s[i] - '0') % mod[j];
    }
  }
}
pair<long long, long long> mer(pair<long long, long long> a,
                               pair<long long, long long> b) {
  return make_pair((a.first + b.first) % mod[0],
                   (a.second + b.second) % mod[1]);
}
long long gen() {
  while (1) {
    long long h = (int)1e8 + rnd() % (int)9e8;
    bool chk = true;
    for (long long i = 2; i * i <= h; i++) {
      if (h % i == 0) {
        chk = false;
        break;
      }
    }
    if (chk) return h;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (fopen("rbw.inp", "r")) {
    freopen("rbw.inp", "r", stdin);
    freopen("rbw.out", "w", stdout);
  }
  mod[0] = gen();
  mod[1] = gen();
  mu[0][0] = 1;
  mu[0][1] = 1;
  for (int i = 1; i < maxn; i++) {
    for (int j = 0; j <= 1; j++) {
      mu[i][j] = (mu[i - 1][j] * base) % mod[j];
    }
  }
  string s;
  cin >> s;
  string x;
  cin >> x;
  long long n = s.length();
  long long m = x.length();
  s = " " + s;
  x = " " + x;
  add(s, n, 0);
  add(x, m, 1);
  pair<long long, long long> nxt = get(1, m, 1);
  for (int i = 1; i < n; i++) {
    if (i >= m) {
      long long st = i - m + 1;
      if (get(st, i, 0) != nxt) {
        long long l = 1, h = m;
        while (l <= h) {
          long long mid = (l + h) / 2;
          if (get(st, st + mid - 1, 0) == get(1, mid, 1))
            l = mid + 1;
          else
            h = mid - 1;
        }
        long long len = h;
        if (m - len > 0 && i + 1 + m - len - 1 <= n) {
          if (mer(get(st, i, 0), get(i + 1, i + 1 + m - len - 1, 0)) == nxt) {
            cout << st << " " << i << "\n";
            cout << i + 1 << " " << i + 1 + m - len - 1;
            return 0;
          }
        }
        if (m - len - 1 > 0 && i + 1 + m - len - 1 - 1 <= n) {
          if (mer(get(st, i, 0), get(i + 1, i + 1 + m - len - 1 - 1, 0)) ==
              nxt) {
            cout << st << " " << i << "\n";
            cout << i + 1 << " " << i + 1 + m - len - 1 - 1;
            return 0;
          }
        }
      }
    }
    if (i + 1 + m - 1 <= n) {
      long long st = i + 1;
      if (get(st, i + 1 + m - 1, 0) != nxt) {
        long long l = 1, h = m;
        while (l <= h) {
          long long mid = (l + h) / 2;
          if (get(st, st + mid - 1, 0) == get(1, mid, 1))
            l = mid + 1;
          else
            h = mid - 1;
        }
        long long len = h;
        if (m - len > 0 && i - (m - len) + 1 >= 1) {
          if (mer(get(st, i + 1 + m - 1, 0), get(i - (m - len) + 1, i, 0)) ==
              nxt) {
            cout << i - (m - len) + 1 << " " << i << "\n";
            cout << st << " " << i + 1 + m - 1 << "\n";
            return 0;
          }
        }
        if (m - len - 1 > 0 && i - (m - len - 1) + 1 >= 1) {
          if (mer(get(st, i + 1 + m - 1, 0),
                  get(i - (m - len - 1) + 1, i, 0)) == nxt) {
            cout << i - (m - len - 1) + 1 << " " << i << "\n";
            cout << st << " " << i + 1 + m - 1 << "\n";
            return 0;
          }
        }
      }
    }
    if (i >= m - 1 && i + 1 + m - 2 <= n) {
      auto p = mer(get(i - (m - 1) + 1, i, 0), get(i + 1, i + m - 1, 0));
      if (p == nxt) {
        cout << i - (m - 1) + 1 << " " << i << "\n";
        cout << i + 1 << " " << i + m - 1;
        return 0;
      }
    }
  }
}
