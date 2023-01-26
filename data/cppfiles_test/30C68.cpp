#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("-ffloat-store")
using namespace std;
const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403() {}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
long long int seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long int rnd(long long int l = 0, long long int r = INF) {
  return uniform_int_distribution<long long int>(l, r)(rng);
}
class CMP {
 public:
  bool operator()(pair<long long int, long long int> a,
                  pair<long long int, long long int> b) {
    return !(a.first < b.first || (a.first == b.first && a.second <= b.second));
  }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt == m.end())
    m.insert({x, cnt});
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int mod = 1000000007L;
namespace atcoder {
struct dsu {
 public:
  dsu() : _n(0) {}
  explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}
  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }
  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }
  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }
  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }
  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int> &v) { return v.empty(); }),
        result.end());
    return result;
  }

 private:
  int _n;
  std::vector<int> parent_or_size;
};
}  // namespace atcoder
long long int T, n, i, j, k, in, cnt, l, r, u, v, x, y;
long long int m;
string s;
vector<long long int> a;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  {
    const int N = 1e6 + 1;
    long long int n, q;
    cin >> n >> q;
    vector<vector<long long int>> fac(N + 1);
    vector<long long int> primes;
    vector<long long int> iden(N + 1, -1);
    for (long long int i = 2; i <= N; ++i) {
      if (!fac[i].empty()) continue;
      iden[i] = ((long long int)(primes).size()) + n;
      primes.push_back(i);
      for (long long int j = i; j <= N; j += i) fac[j].push_back(i);
    }
    const long long int m = ((long long int)(primes).size());
    42;
    ;
    atcoder::dsu d(n + m);
    vector<long long int> a(n);
    for (long long int i = 0; i < n; ++i) {
      auto &x = a[i];
      cin >> x;
      for (auto y : fac[x]) d.merge(i, iden[y]);
    }
    set<pair<long long int, long long int>> ss;
    for (long long int i = 0; i < n; ++i) {
      const auto u = a[i], v = a[i] + 1;
      for (auto y : fac[v]) {
        for (auto x : fac[u]) {
          const long long int f1 = d.leader(iden[x]), f2 = d.leader(iden[y]);
          if (f1 == f2) continue;
          ss.insert({min(f1, f2), max(f1, f2)});
        }
        for (auto x : fac[v]) {
          const long long int f1 = d.leader(iden[x]), f2 = d.leader(iden[y]);
          if (f1 == f2) continue;
          ss.insert({min(f1, f2), max(f1, f2)});
        }
      }
    }
    while (q--) {
      long long int u, v;
      cin >> u >> v;
      u--;
      v--;
      u = d.leader(u);
      v = d.leader(v);
      if (u > v) swap(u, v);
      if (u == v) {
        cout << 0 << "\n";
        continue;
      }
      if (ss.count({u, v})) {
        cout << 1 << "\n";
        continue;
      }
      cout << 2 << "\n";
    }
  }
  aryanc403();
  return 0;
}
