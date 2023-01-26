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
const long long N = 6e5 + 7;
V<pair<long long, long long> > d[N];
pair<long long, long long> tree[N << 2];
void push(long long v) {
  ckmax(tree[v * 2 + 1], tree[v]);
  ckmax(tree[v * 2 + 2], tree[v]);
}
pair<long long, long long> getmax(long long v, long long l, long long r,
                                  long long ql, long long qr) {
  if (r < ql || qr < l) {
    return make_pair(-N, -N);
  }
  if (ql <= l && r <= qr) {
    return tree[v];
  }
  long long m = (l + r) / 2;
  push(v);
  return max(getmax(v * 2 + 1, l, m, ql, qr),
             getmax(v * 2 + 2, m + 1, r, ql, qr));
}
pair<long long, long long> getmax(long long l, long long r) {
  return getmax(0, 0, N, l, r);
}
void relax(long long v, long long l, long long r, long long ql, long long qr,
           pair<long long, long long> first) {
  if (r < ql || qr < l) {
    return;
  }
  if (ql <= l && r <= qr) {
    ckmax(tree[v], first);
    return;
  }
  long long m = (l + r) / 2;
  push(v);
  relax(v * 2 + 1, l, m, ql, qr, first);
  relax(v * 2 + 2, m + 1, r, ql, qr, first);
}
void relax(long long l, long long r, pair<long long, long long> first) {
  relax(0, 0, N, l, r, first);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = (0); i < (N << 2); ++i) {
    tree[i] = make_pair(-N, -N);
  }
  long long n, m;
  cin >> n >> m;
  vi c;
  for (long long i = (0); i < (m); ++i) {
    long long row, l, r;
    cin >> row >> l >> r;
    d[row].push_back(make_pair(l, r));
    c.push_back(l);
    c.push_back(r);
  }
  sort(c.begin(), c.end());
  c.resize(unique(c.begin(), c.end()) - c.begin());
  vi dp(n + 1, 1);
  vi par(n + 1, -1);
  pair<long long, long long> ans = make_pair(-1, -1);
  for (long long i = (1); i < (n + 1); ++i) {
    for (auto& seg : d[i]) {
      seg.first = lower_bound(c.begin(), c.end(), seg.first) - c.begin();
      seg.second = lower_bound(c.begin(), c.end(), seg.second) - c.begin();
    }
    for (auto& seg : d[i]) {
      long long l = seg.first, r = seg.second;
      auto t = getmax(l, r);
      t.first++;
      if (ckmax(dp[i], t.first)) {
        par[i] = t.second;
      }
    }
    for (auto& seg : d[i]) {
      long long l = seg.first, r = seg.second;
      relax(l, r, make_pair(dp[i], i));
    }
    ckmax(ans, make_pair(dp[i], i));
  }
  vi used(n + 1);
  long long u = ans.second;
  while (u != -1) {
    used[u] = 1;
    u = par[u];
  }
  cout << n - ans.first << '\n';
  for (long long i = (1); i < (n + 1); ++i) {
    if (!used[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}
