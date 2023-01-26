#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
using std::vector;
const int mod = 998244353, G = 3, IG = 332748118;
template <typename T>
inline T max(T &x, T &y) {
  return x > y ? x : y;
}
template <typename T>
inline T min(T &x, T &y) {
  return x < y ? x : y;
}
auto Mod = [](int x) -> int {
  if (x < 0) {
    return x + mod;
  } else if (x >= mod) {
    return x - mod;
  } else {
    return x;
  }
};
auto ksm = [](int x, int y) -> int {
  int ret = 1;
  for (; y; y /= 2, x = (long long)x * x % mod) {
    if (y & 1) {
      ret = (long long)ret * x % mod;
    }
  }
  return ret;
};
inline int GetLim(int x) {
  if (x == 0) {
    return 1;
  } else {
    return 1 << (32 - __builtin_clz(x));
  }
}
struct poly {
  vector<int> elem;
  poly(vector<int> a) { elem = a; }
  int &operator[](int x) { return elem[x]; }
  inline unsigned int size() { return elem.size(); }
  poly operator-();
  poly operator*(int a);
  friend poly operator+(poly a, poly b);
  friend poly operator-(poly a, poly b);
  friend poly operator*(poly a, poly b);
};
poly poly::operator-() {
  poly a = *this;
  for (auto &x : a.elem) {
    x = -x;
  }
  return a;
}
poly poly::operator*(int a) {
  poly x = *this;
  for (auto &i : x.elem) {
    i = (long long)i * a % mod;
  }
  return x;
}
poly operator+(poly a, poly b) {
  poly x(b.size() >= a.size() ? b.elem : a.elem);
  if (x.size() == b.size()) {
    for (int i = 0; i < a.size(); ++i) {
      x[i] += a[i];
    }
  } else {
    for (int i = 0; i < b.size(); ++i) {
      x[i] += b[i];
    }
  }
  return x;
}
poly operator-(poly v, poly a) {
  poly x(v.size() >= a.size() ? v.elem : a.elem);
  if (x.size() == v.size()) {
    for (int i = 0; i < a.size(); ++i) {
      x[i] = Mod(x[i] - a[i]);
    }
  } else {
    for (int i = 0; i < v.size(); ++i) {
      x[i] = Mod(v[i] - x[i]);
    }
  }
  return x;
}
int r[524288];
void FFT(poly &a, int ty, int lim) {
  for (int i = 0; i < lim; ++i) {
    if (i < r[i]) {
      std::swap(a[i], a[r[i]]);
    }
  }
  for (int o = 2, j = 1; o <= lim; o <<= 1, j <<= 1) {
    int wn = ksm(ty == 1 ? G : IG, (mod - 1) / o);
    for (int i = 0; i < lim; i += o) {
      for (int k = 0, w = 1; k < j; ++k, w = (long long)w * wn % mod) {
        int io = a[i + k], oi = (long long)a[i + j + k] * w % mod;
        a[i + k] = Mod(io + oi);
        a[i + j + k] = Mod(io - oi);
      }
    }
  }
  if (ty == -1) {
    int qs = ksm(lim, mod - 2);
    for (int i = 0; i < lim; ++i) {
      a[i] = (long long)a[i] * qs % mod;
    }
  }
  return;
}
poly operator*(poly a, poly b) {
  int lim = GetLim(a.size() + b.size() - 2);
  a.elem.resize(lim);
  b.elem.resize(lim);
  for (int i = 1; i < lim; ++i) {
    r[i] = (r[i / 2] / 2) | (i & 1 ? lim / 2 : 0);
  }
  FFT(a, 1, lim);
  FFT(b, 1, lim);
  for (int i = 0; i < lim; ++i) {
    a[i] = (long long)a[i] * b[i] % mod;
  }
  FFT(a, -1, lim);
  while (a.elem.back() == 0) {
    a.elem.pop_back();
  }
  return a;
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> d(n + 1, -1), fac(n + 1, 1);
  d[1] = 0;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    ++d[x];
    ++d[y];
  }
  for (int i = 1; i <= n; ++i) {
    fac[i] = (long long)fac[i - 1] * i % mod;
  }
  std::function<poly(int, int)> solve = [&](int l, int r) {
    if (r == l) {
      return poly(vector<int>({1, d[l]}));
    } else {
      int mid = (l + r) / 2;
      return solve(l, mid) * solve(mid + 1, r);
    }
  };
  poly f = solve(1, n);
  int ans = 0;
  for (int i = 0; i <= n && i < f.size(); ++i) {
    ans =
        (ans + (long long)Mod(i & 1 ? -1 : 1) * f[i] % mod * fac[n - i] % mod) %
        mod;
  }
  cout << ans << '\n';
  return 0;
}
