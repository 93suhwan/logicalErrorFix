#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
template <typename T>
std::istream& operator>>(std::istream& input, std::pair<T, T>& data) {
  input >> data.first >> data.second;
  return input;
}
template <typename T>
std::istream& operator>>(std::istream& input, std::vector<T>& data) {
  for (T& first : data) input >> first;
  return input;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const pair<T, T>& data) {
  output << "(" << data.first << "," << data.second << ")";
  return output;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const std::vector<T>& data) {
  for (const T& first : data) output << first << " ";
  return output;
}
std::ostream& operator<<(std::ostream& output, const __int128& first) {
  __int128 n = first;
  if (n == 0) {
    output << "0";
    return output;
  }
  if (n < 0) {
    n = -n;
    output << "-";
  }
  string s;
  while (n) {
    s += '0' + (n % 10);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
  return output;
}
long long div_up(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long div_down(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
long long math_mod(long long a, long long b) { return a - b * div_down(a, b); }
template <class T>
using V = vector<T>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
long long gcd(long long a, long long b) {
  while (b) {
    tie(a, b) = make_pair(b, a % b);
  }
  return a;
}
long long Bit(long long mask, long long bit) { return (mask >> bit) & 1; }
struct Rmq {
  const long long INF = 2e18;
  vi rmq;
  long long sz;
  Rmq() {}
  Rmq(long long n) {
    sz = 1;
    while (sz < n) sz *= 2;
    rmq.assign(sz * 2, -INF);
  }
  void put(long long i, long long first) {
    i += sz;
    ckmax(rmq[i], first);
    for (i /= 2; i; i /= 2) {
      rmq[i] = max(rmq[i * 2], rmq[i * 2 + 1]);
    }
  }
  long long get(long long l, long long r) {
    l += sz;
    r += sz;
    long long res = -INF;
    while (l < r) {
      if (l % 2 == 1) res = max(res, rmq[l]);
      if (r % 2 == 0) res = max(res, rmq[r]);
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    if (l == r) res = max(res, rmq[l]);
    return res;
  }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  V<string> a(n);
  cin >> a;
  V<vi> go(n, vi(m));
  for (long long c = (0); c < (m); ++c) {
    for (long long r = (0); r < (n); ++r) {
      go[r][c] = c;
      if (r == 0) {
        go[r][c] = -1;
      } else {
        if (a[r - 1][c] == '.') ckmin(go[r][c], go[r - 1][c]);
        if (c == 0) {
          go[r][c] = -1;
        } else {
          if (a[r][c - 1] == '.') ckmin(go[r][c], go[r][c - 1]);
        }
      }
    }
  }
  vi mx(m);
  for (long long i = (0); i < (m); ++i) {
    mx[i] = -1;
    for (long long j = (0); j < (n); ++j) {
      ckmax(mx[i], go[j][i]);
    }
  }
  Rmq d(m);
  for (long long i = (0); i < (m); ++i) {
    d.put(i, mx[i]);
  }
  long long q;
  cin >> q;
  for (long long _ = (0); _ < (q); ++_) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    if (d.get(l, r) <= l) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
