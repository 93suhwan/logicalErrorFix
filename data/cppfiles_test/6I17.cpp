#include <bits/stdc++.h>
using namespace std;
template <class T>
int chkmax(T& a, T b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
int chkmin(T& a, T b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class iterator>
void output(iterator begin, iterator end, ostream& out = cerr) {
  while (begin != end) {
    out << (*begin) << " ";
    begin++;
  }
  out << endl;
}
template <class T>
void output(T x, ostream& out = cerr) {
  output(x.begin(), x.end(), out);
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int MAX_N = 1e5 + 228;
const int C = 1e5 + 228;
const int K = 300;
int n, a[MAX_N];
int gcd(int a, int b) {
  if (!a || !b) return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b) swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}
const int MAX_P = 6;
int pd[C + 1][MAX_P], pd_cnt[C + 1];
int ief[C + 1][1 << MAX_P], pptr[C + 1], mptr[C + 1];
void prepare_mobius() {
  for (int p = 2; p <= C; ++p) {
    if (pd_cnt[p] == 0) {
      for (int x = p; x <= C; x += p) {
        pd[x][pd_cnt[x]++] = p;
      }
    }
  }
  fill(mptr + 1, mptr + C, (1 << MAX_P) - 1);
  for (int i = 1; i <= C; ++i) {
    for (int sub = 1; sub < (1 << pd_cnt[i]); ++sub) {
      int prod = i;
      for (int j = 0; j < pd_cnt[i]; ++j) {
        if ((sub >> j) & 1) {
          prod /= pd[i][j];
        }
      }
      if (__builtin_popcount(sub) % 2 == 0) {
        ief[i][pptr[i]++] = prod;
      } else {
        ief[i][mptr[i]--] = prod;
      }
    }
  }
}
void read() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
}
long long cnt[C + 1], f[C + 1], res[MAX_N], cache[MAX_N];
void mobius_transform(long long* arr, int len) {
  copy(arr + 1, arr + len + 1, cache + 1);
  for (int i = len; i >= 1; --i) {
    for (int j = 0; j < pptr[i]; ++j) {
      arr[ief[i][j]] += cache[i];
    }
    for (int j = mptr[i] + 1; j < (1 << MAX_P); ++j) {
      arr[ief[i][j]] -= cache[i];
    }
  }
}
void compute_small(int step) {
  fill(f, f + C + 1, 0);
  fill(cnt, cnt + C + 1, 0);
  for (int i = step; i <= n; i += step) {
    cnt[a[i]]++;
  }
  for (int i = 1; i <= C; ++i) {
    for (int j = i; j <= C; j += i) {
      f[i] += cnt[j];
    }
  }
  for (int i = 1; i <= C; ++i) {
    f[i] = f[i] * (f[i] - 1) / 2;
  }
  mobius_transform(f, C);
  for (int i = 1; i <= C; ++i) {
    res[step] += f[i] * (long long)i;
  }
}
void compute_large(int step) {
  for (int i = step; i <= n; i += step) {
    for (int j = i + step; j <= n; j += step) {
      res[step] += gcd(a[i], a[j]);
    }
  }
}
long long ans;
void solve() {
  for (int i = 1; i <= n; ++i) {
    if (i <= K) {
      compute_small(i);
    } else {
      compute_large(i);
    }
  }
  mobius_transform(res, n);
  for (int i = 1; i <= n; ++i) {
    ans += res[i] * i;
  }
  ans *= 2;
  for (int i = 1; i <= n; ++i) {
    ans += (long long)a[i] * (long long)i;
  }
  cout << ans << '\n';
}
signed main() {
  fast_io();
  read();
  prepare_mobius();
  solve();
}
