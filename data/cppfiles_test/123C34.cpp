#include <bits/stdc++.h>
using namespace std;
constexpr long long N = 600500;
constexpr long long D = 2000010;
constexpr long double EPS = 1e-8;
ofstream fout;
ifstream fin;
int flag = -1;
long long n, m, k;
vector<vector<int> > v;
vector<int> h;
vector<int> was;
bool comp(int a, int b) { return h[a] > h[b]; }
multiset<int, bool (*)(int, int)> s(comp);
void dfs(int x) {
  int o = 0;
  was[x] = 1;
  for (auto &y : (v[x])) {
    if (!was[y]) {
      dfs(y);
      o = max(o, h[y]);
    }
  }
  h[x] = o + 1;
}
void dfs1(int x) {
  was[x] = 1;
  int u, m = -1;
  for (auto &y : (v[x])) {
    if (!was[y]) {
      if (h[y] > m) {
        m = h[y];
        u = y;
      }
    }
  }
  if (m == -1) return;
  for (auto &y : (v[x])) {
    if (!was[y]) {
      if (y == u) {
        dfs1(y);
      } else {
        s.insert(y);
      }
    }
  }
}
void solve() {
  long long a, b;
  cin >> n >> k;
  s.clear();
  v.clear();
  h.clear();
  was.clear();
  v.resize(n);
  h.resize(n);
  was.resize(n);
  for (long long i = 0; i < (n - 1); i++) {
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(0);
  s.insert(0);
  fill(was.begin(), was.end(), 0);
  a = k;
  k = 0;
  while (k < a && !s.empty()) {
    k++;
    int x = *s.begin();
    s.erase(s.begin());
    dfs1(x);
  }
  long long mx = -((long long)1e15);
  long long e = count(was.begin(), was.end(), 1);
  if (k < a) {
    for (long long i = (k); i < (a + 1); i++) {
      mx = max(mx, (e - i) * (i));
    }
  } else {
    mx = ((long long)1e15);
    long long p = count(was.begin(), was.end(), 0);
    for (long long i = (0); i < (p + 1); i++) {
      mx = min(mx, (e - a + (p - i)) * (a - i));
    }
  }
  cout << mx << "\n";
}
signed main(signed argc, char *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(14);
  cout.fixed;
  srand(time(0));
  fout.precision(14);
  fout.fixed;
  int tt = 1;
  while (tt--) {
    solve();
  }
  fout.close();
  fin.close();
}
