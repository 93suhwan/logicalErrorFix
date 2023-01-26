#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 200005;
long long t, n, cnt, x, m, a[maxn], ans, pos, pos1, pos2, l, r, mid, y, z, mx,
    k, mod = 1000000007, tw[65], cnt1, cnt2, mn, vis[maxn], sum;
long long b[4 * maxn];
string s, s2, s3, s4;
char cc[205][205];
char ch;
long long fpow(long long x, long long y) {
  if (y == 0) {
    return 1 % mod;
  }
  long long a = x % mod;
  long long a2 = 1 % mod;
  while (y > 1) {
    if (y % 2) {
      a2 *= a;
      a2 %= mod;
    }
    a *= a;
    a %= mod;
    y /= 2;
  }
  return (a * a2) % mod;
}
void build(long long l, long long r, long long v) {
  if (l == r) {
    b[v] = a[l];
    return;
  }
  long long mid = (l + r) / 2;
  build(l, mid, 2 * v + 1);
  build(mid + 1, r, 2 * v + 2);
  b[v] = b[2 * v + 1] + b[2 * v + 2];
}
long long qu(long long l, long long r, long long v, long long l2,
             long long r2) {
  if (l == l2 && r == r2) {
    return b[v];
  }
  long long mid = (l + r) / 2;
  if (mid >= r2) {
    return qu(l, mid, 2 * v + 1, l2, r2);
  } else if (mid + 1 <= l2) {
    return qu(mid + 1, r, 2 * v + 2, l2, r2);
  } else {
    return qu(l, mid, 2 * v + 1, l2, mid) +
           qu(mid + 1, r, 2 * v + 2, mid + 1, r2);
  }
}
void modify(long long l, long long r, long long v, long long l2, long long r2,
            long long m) {
  if (l == l2 && r == r2) {
    b[v] = m;
    return;
  }
  long long mid = (l + r) / 2;
  if (mid >= r2) {
    modify(l, mid, 2 * v + 1, l2, r2, m);
  } else if (mid + 1 <= l2) {
    modify(mid + 1, r, 2 * v + 2, l2, r2, m);
  } else {
    modify(l, mid, 2 * v + 1, l2, mid, m);
    modify(mid + 1, r, 2 * v + 2, mid + 1, r2, m);
  }
  b[v] = b[2 * v + 1] + b[2 * v + 2];
}
bool cmp(long long x, long long y) { return x < y; }
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        cc[i][j] = '=';
      }
    }
    cnt = 0;
    pos = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1') {
        a[cnt] = i;
        cnt++;
      } else {
        b[pos] = i;
        pos++;
      }
    }
    if (pos <= 2 && pos > 0) {
      cout << "NO" << '\n';
    } else if (pos == 0) {
      for (long long i = 0; i < n; i++) {
        cc[i][i] = 'X';
      }
      cout << "YES" << '\n';
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
          cout << cc[i][j];
        }
        cout << '\n';
      }
    } else {
      cout << "YES" << '\n';
      for (long long i = 0; i < n; i++) {
        cc[i][i] = 'X';
      }
      for (long long i = 0; i < pos; i++) {
        cc[b[i]][b[(i + 1) % pos]] = '+';
        cc[b[(i + 1) % pos]][b[i]] = '-';
      }
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
          cout << cc[i][j];
        }
        cout << '\n';
      }
    }
  }
}
