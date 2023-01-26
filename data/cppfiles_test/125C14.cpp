#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const int inf = 1e9;
const ll inf64 = 1e18;
struct Kuhn {
  int n = 0;
  vector<vector<int>> g;
  vector<int> used, mt;
  Kuhn() = default;
  Kuhn(int nn) {
    n = nn;
    g.resize(n);
    mt.assign(n, -1);
  }
  void add_edge(int u, int v) { g[v].push_back(u); }
  int dfs(int v) {
    if (used[v]) return 0;
    used[v] = 1;
    for (int to : g[v]) {
      if (mt[to] == -1 || dfs(mt[to])) {
        mt[v] = to;
        mt[to] = v;
        return 1;
      }
    }
    return 0;
  }
  vector<pii> find_max_matching() {
    for (int run = 1; run;) {
      run = 0;
      used.assign(n, 0);
      for (int v = 0; v < n; v++) {
        if (g[v].empty()) continue;
        if (!used[v] && mt[v] == -1 && dfs(v)) {
          run = 1;
        }
      }
    }
    vector<pii> M;
    for (int i = 0; i < n; i++) {
      if (mt[i] != -1 && i < mt[i]) M.emplace_back(i, mt[i]);
    }
    return M;
  }
};
struct GeneralMatching {
  int n = 0, cc = 10;
  vector<vector<int>> g;
  vector<int> mt, used, base, p, color, base_used, p_used;
  queue<int> q;
  Kuhn kuhn;
  int used_timer = 10;
  int base_timer = 10;
  int p_timer = 10;
  GeneralMatching(int nn)
      : n(nn),
        mt(n, -1),
        used(n),
        base(n),
        p(n),
        color(n),
        g(n),
        kuhn(n),
        base_used(n),
        p_used(n) {}
  void add_edge(int u, int v, bool add_to_kuhn) {
    g[u].push_back(v), g[v].push_back(u);
    if (add_to_kuhn) kuhn.add_edge(u, v);
  }
  void add(int v) {
    if (used[v] != used_timer) used[v] = used_timer, q.push(v);
  }
  int& get_base(int v) {
    if (base_used[v] != base_timer) {
      base_used[v] = base_timer;
      base[v] = v;
    }
    return base[v];
  }
  int& get_p(int v) {
    if (p_used[v] != p_timer) {
      p_used[v] = p_timer;
      p[v] = -1;
    }
    return p[v];
  }
  int get_lca(int u, int v) {
    cc++;
    while (1) {
      u = get_base(u), color[u] = cc;
      if (mt[u] == -1) break;
      u = get_p(mt[u]);
    }
    while (1) {
      v = get_base(v);
      if (color[v] == cc) break;
      v = get_p(mt[v]);
    }
    return v;
  }
  void mark_path(int v, int child, int b) {
    while (get_base(v) != b) {
      color[get_base(v)] = color[get_base(mt[v])] = cc;
      get_p(v) = child, child = mt[v], v = get_p(child);
    }
  }
  int bfs(int root) {
    add(root);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int to : g[v]) {
        if (get_base(v) == get_base(to) || mt[v] == to)
          continue;
        else if (used[to] == used_timer) {
          int w = get_lca(v, to);
          cc++, mark_path(v, to, w), mark_path(to, v, w);
          for (int i = 0; i < n; i++)
            if (color[get_base(i)] == cc) get_base(i) = w, add(i);
        } else if (get_p(to) == -1) {
          get_p(to) = v;
          if (mt[to] == -1) return to;
          add(mt[to]);
        }
      }
    }
    return -1;
  }
  void xor_path(int v) {
    while (v != -1) {
      int pv = get_p(v), ppv = mt[pv];
      mt[v] = pv, mt[pv] = v;
      v = ppv;
    }
  }
  void greedy_init() {
    for (auto [u, v] : kuhn.find_max_matching()) {
      mt[u] = v;
      mt[v] = u;
    }
  }
  bool inc(int root) {
    used_timer++;
    p_timer++;
    base_timer++;
    while (!q.empty()) q.pop();
    int v = bfs(root);
    if (v == -1) return false;
    xor_path(v);
    return true;
  }
  void match() {
    for (int i = 0; i < n && i <= 605; i++)
      if (mt[i] == -1) inc(i);
  }
  vector<pii> find_max_matching() {
    greedy_init();
    static mt19937 rnd(42);
    for (int v = 0; v < n; v++) {
      sort(g[v].begin(), g[v].end());
      g[v].erase(unique(g[v].begin(), g[v].end()), g[v].end());
      shuffle(g[v].begin(), g[v].end(), rnd);
    }
    match();
    vector<pii> M;
    for (int i = 0; i < n; i++) {
      if (mt[i] != -1 && i < mt[i]) M.emplace_back(i, mt[i]);
    }
    return M;
  }
};
int measure(const vector<int>& a) {
  unordered_set<int> Q;
  for (int i = 0; i + 1 < (int)a.size(); i++) {
    if (a[i] == a[i + 1]) Q.insert(a[i]);
  }
  return (int)Q.size();
}
struct output {
  vector<int> res;
  void print() {
    for (auto x : res) cout << x << " ";
    cout << "\n";
  }
  bool operator==(const output& o) const {
    cout << "measure = " << measure(res) << "\n";
    return measure(res) == measure(o.res);
  }
};
struct input {
  int n;
  vector<int> a;
  input() = default;
  void read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
  }
  void print() {
    cout << n << "\n";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
  }
  void gen() {
    static mt19937 rnd(42);
    const int MAXN = 10;
    n = rnd() % MAXN + 2;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) a[i] = rnd() % (n + 1);
  }
  output fast() {
    int k = *max_element(a.begin(), a.end()) + 1;
    GeneralMatching gm(2 * k + n + 1);
    vector<int> sat(n + 1);
    for (int i = 1; i < n; i++) {
      if (a[i] > 0 && a[i] == a[i + 1]) sat[a[i]] = 1;
    }
    for (int i = 1; i <= k; i++) {
      if (sat[i]) {
        gm.add_edge(i, i + k, true);
      }
    }
    vector<vector<int>> even(k + 1, vector<int>(k + 1));
    vector<int> odd(n + 1);
    vector<pii> s(n + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] > 0) continue;
      int j = i;
      while (j <= n && a[j] == 0) j++;
      j--;
      for (int q = i; q <= j; q++) s[q] = {i, j};
      int len_parity = (j - i + 1) % 2;
      if (len_parity) {
        if (i > 1) gm.add_edge(i + 2 * k, a[i - 1], true), odd[a[i - 1]] = i;
        if (j < n) gm.add_edge(i + 2 * k, a[j + 1], true), odd[a[j + 1]] = i;
      } else {
        if (i > 1 && j < n) {
          gm.add_edge(a[i - 1], a[j + 1], false);
          even[a[i - 1]][a[j + 1]] = i;
          even[a[j + 1]][a[i - 1]] = i;
        }
      }
      i = j;
    }
    vector<pii> M = gm.find_max_matching();
    vector<int> res = a;
    for (auto [u, v] : M) {
      if (u > v) swap(u, v);
      if (u <= k && v <= k) {
        int i = even[u][v];
        auto [l, r] = s[i];
        res[l] = res[l - 1];
        res[r] = res[r + 1];
      } else if (u <= k && v > 2 * k) {
        int i = v - 2 * k;
        auto [l, r] = s[i];
        if (l > 1 && a[l - 1] == u)
          res[l] = res[l - 1];
        else
          res[r] = res[r + 1];
      }
    }
    for (int i = 1; i < n; i++) {
      if (res[i] > 0 && res[i] == res[i + 1]) sat[res[i]] = 1;
    }
    for (int x = 1, i = 1; i <= n; i++) {
      if (res[i] == 0 && res[i + 1] == 0) {
        while (sat[x]) x++;
        res[i] = res[i + 1] = x;
        sat[x] = 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (res[i] == 0) res[i] = 1;
    }
    res.erase(res.begin());
    return output{res};
  }
  vector<int> rec(int i) {
    if (i == n + 1) {
      return a;
    } else if (a[i]) {
      return rec(i + 1);
    } else {
      vector<int> res, tmp;
      for (a[i] = 1; a[i] <= n; a[i]++) {
        tmp = rec(i + 1);
        if (res.empty() || measure(res) < measure(tmp)) res = tmp;
      }
      a[i] = 0;
      return res;
    }
  }
  output slow() {
    vector<int> res = rec(1);
    res.erase(res.begin());
    return output{res};
  }
};
void test_case() {
  input in;
  in.read();
  output res = in.fast();
  res.print();
}
void work() {
  int t = 1;
  while (t--) test_case();
}
void test() {
  for (int t = 1;; t++) {
    input in;
    in.gen();
    input in_fs = in;
    input in_sl = in;
    output fs = in_fs.fast();
    output sl = in_sl.slow();
    if (fs == sl) {
      cout << "OK" << endl;
      fs.print();
      cout << "\n=========" << endl;
    } else {
      cout << "WA " << t << "\n";
      cout << "exp\n";
      sl.print();
      cout << "\n=========\n";
      cout << "fnd\n";
      fs.print();
      cout << "\n=========\n";
      in.print();
      break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  work();
  return 0;
}
