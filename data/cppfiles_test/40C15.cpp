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
const long long N = 3e5 + 7;
long long n, m;
vi g[N];
bool used[N];
long long par[N], h[N];
long long sum[N];
vi tree[N];
void dfs(long long u) {
  used[u] = 1;
  for (auto& v : g[u]) {
    if (!used[v]) {
      h[v] = h[u] + 1;
      par[v] = u;
      dfs(v);
      tree[u].push_back(v);
    }
  }
}
long long lca(long long u, long long v) {
  while (h[u] > h[v]) u = par[u];
  while (h[v] > h[u]) v = par[v];
  while (u != v) {
    u = par[u];
    v = par[v];
  }
  return u;
}
long long ans = 0;
void solve(long long u) {
  long long t = 0;
  for (auto& v : tree[u]) {
    solve(v);
    t += sum[v];
  }
  ans += t / 2;
  t &= 1;
  if (t && sum[u] == 0) {
    ans++;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long _ = (0); _ < (m); ++_) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  V<pair<long long, long long> > mem;
  long long q;
  cin >> q;
  for (long long _ = (0); _ < (q); ++_) {
    long long u, v;
    cin >> u >> v;
    mem.push_back(make_pair(u, v));
    long long l = lca(u, v);
    while (u != l) {
      sum[u] ^= 1;
      u = par[u];
    }
    while (v != l) {
      sum[v] ^= 1;
      v = par[v];
    }
  }
  bool ok = 1;
  for (long long u = (1); u < (n + 1); ++u) {
    ok &= sum[u] % 2 == 0;
  }
  if (ok) {
    cout << "YES" << '\n';
    for (auto& e : mem) {
      long long u = e.first, v = e.second;
      long long l = lca(u, v);
      vi le;
      while (u != l) {
        le.push_back(u);
        u = par[u];
      }
      vi ri;
      while (v != l) {
        ri.push_back(v);
        v = par[v];
      }
      reverse(ri.begin(), ri.end());
      vi tot;
      for (auto& e : le) tot.push_back(e);
      tot.push_back(l);
      for (auto& e : ri) tot.push_back(e);
      cout << tot.size() << '\n' << tot << '\n';
    }
  } else {
    cout << "NO" << '\n';
    solve(1);
    cout << ans << '\n';
  }
}
