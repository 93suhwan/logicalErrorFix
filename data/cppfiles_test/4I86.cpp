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
ostream& operator<<(ostream& os, pair<int, int> pp) {
  return os << pp.first << ' ' << pp.second;
}
const int MOD = 1e9 + 7;
int mul(int a, int b) { return (1LL * a * b) % MOD; }
int diff(int a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
  return a;
}
void subt(int& a, const int& b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}
int sum(int a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}
void add(int& a, const int& b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}
int power(int a, int deg) {
  int res = 1;
  for (; deg; a = mul(a, a), deg >>= 1) {
    if (deg & 1) {
      res = mul(res, a);
    }
  }
  return res;
}
int inverse(int a) { return power(a, MOD - 2); }
int divide(int a, int b) { return mul(a, inverse(b)); }
void operator+=(pair<int, int>& a, const pair<int, int>& b) {
  add(a.first, b.first);
  add(a.second, b.second);
}
void operator-=(pair<int, int>& a, const pair<int, int>& b) {
  subt(a.first, b.first);
  subt(a.second, b.second);
}
pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
  return {sum(a.first, b.first), sum(a.second, b.second)};
}
pair<int, int> operator-(const pair<int, int>& a, const pair<int, int>& b) {
  return {diff(a.first, b.first), diff(a.second, b.second)};
}
struct DpHolder;
map<DpHolder*, int> storage;
int get_id(DpHolder* ptr) {
  if (storage.find(ptr) == storage.end()) {
    storage[ptr] = storage.size();
  }
  return storage[ptr];
}
struct DpHolder {
  vector<pair<int, int>> val, f;
  pair<int, int> total;
  int n, mod;
  pair<int, int> prefsum(int pos) {
    pair<int, int> res = total - fget(n - 2 - pos);
    res.second = sum(res.second, mul(res.first, mod));
    return res;
  }
  pair<int, int> fget(int pos) {
    pair<int, int> res;
    while (pos >= 0) {
      res += f[pos];
      pos = (pos & (pos + 1)) - 1;
    }
    return res;
  }
  pair<int, int> get(int pos) {
    if (pos < 0) {
      return {0, 0};
    }
    pair<int, int> res = val[n - 1 - pos];
    res.second = sum(res.second, mul(res.first, mod));
    return res;
  }
  void push(pair<int, int> new_val) {
    new_val.second = diff(new_val.second, mul(new_val.first, mod));
    pair<int, int> new_f = total - fget((n & (n + 1)) - 1) + new_val;
    total += new_val;
    f.push_back(new_f);
    val.push_back(new_val);
    n++;
  }
  void update(int pos, pair<int, int> delta) {
    delta.second = diff(delta.second, mul(delta.first, mod));
    pos = n - 1 - pos;
    val[pos] += delta;
    while (pos < n) {
      f[pos] += delta;
      pos = (pos | (pos + 1));
    }
  }
  void augment(int a) { add(mod, a); }
};
DpHolder* add_up(DpHolder* from, DpHolder* to) {
  if (from->n > to->n) {
    swap(from, to);
  }
  for (int i = 0; i < from->n; ++i) {
    to->update(i, from->get(i));
  }
  delete from;
  return to;
}
const int MAX_N = 2e5 + 228;
vector<vector<pair<int, int>>> g;
vector<vector<int>> children;
long long a[MAX_N];
int n, k, up_clr[MAX_N], h[MAX_N];
void hang(int v, int pv) {
  h[v] = 0;
  for (auto [v1, clr] : g[v]) {
    if (v1 != pv) {
      up_clr[v1] = clr;
      children[v].push_back(v1);
      hang(v1, v);
      chkmax(h[v], h[v1] + 1);
    }
  }
  sort(children[v].begin(), children[v].end(),
       [](int u, int v) { return h[u] > h[v]; });
}
void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  g.resize(n);
  children.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, clr;
    cin >> u >> v >> clr;
    u--;
    v--;
    g[u].emplace_back(v, clr);
    g[v].emplace_back(u, clr);
  }
  hang(0, 0);
}
int ans;
DpHolder* dfs(int v) {
  if (children[v].empty()) {
    DpHolder* holder = new DpHolder();
    holder->push({1, a[v]});
    return holder;
  }
  vector<DpHolder*> holders(2);
  holders[0] = dfs(children[v][0]);
  holders[1] = new DpHolder();
  for (int i = 1; i < children[v].size(); ++i) {
    int v1 = children[v][i];
    DpHolder* cur = dfs(v1);
    int type = (up_clr[v1] != up_clr[children[v][0]]);
    for (int cost = 0; cost < cur->n; ++cost) {
      if (cost > k) {
        break;
      }
      pair<int, int> dp_val = cur->get(cost);
      for (int it = 0; it < 2; ++it) {
        int max_cost = k - cost - (type != it);
        if (max_cost >= 0) {
          pair<int, int> other = holders[i]->prefsum(max_cost);
          int delta = 0;
          add(delta, mul(dp_val.first, other.second));
          add(delta, mul(dp_val.second, other.first));
          add(delta, mul(mul(dp_val.first, other.first), a[v]));
          add(ans, delta);
        }
      }
    }
    holders[type] = add_up(cur, holders[type]);
  }
  pair<int, int> v1 = holders[0]->get(min(holders[0]->n - 1, k));
  pair<int, int> v2 = holders[1]->get(min(holders[1]->n - 1, k));
  int delta = 0;
  add(delta, mul(v1.first, a[v]));
  add(delta, v1.second);
  add(delta, mul(v2.first, a[v]));
  add(delta, v2.second);
  add(ans, delta);
  holders[up_clr[v]]->push({0, 0});
  DpHolder* result = add_up(holders[1], holders[0]);
  result->augment(a[v]);
  result->update(0, {1, a[v]});
  return result;
}
void solve() {
  dfs(0);
  for (int i = 0; i < n; ++i) {
    add(ans, a[i]);
  }
  cout << ans << '\n';
}
void test_DP_holder() {
  DpHolder holder;
  holder.push({1, 2});
  holder.push({2, 4});
  cerr << holder.get(0) << '\n';
  cerr << holder.get(1) << '\n';
}
signed main() {
  fast_io();
  read();
  solve();
}
