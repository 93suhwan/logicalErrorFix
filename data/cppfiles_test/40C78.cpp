#include <bits/stdc++.h>
using namespace std;
void eraseDups(vector<int>& a) { a.erase(unique(a.begin(), a.end()), a.end()); }
int strToInt(string& a) {
  stringstream x(a);
  int b;
  x >> b;
  return b;
}
int bitCnt(int a) {
  bitset<64> b(a);
  return b.count();
}
int bitCnt(string a) {
  bitset<64> b(a);
  return b.count();
}
vector<int> readVI(int n) {
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return a;
}
vector<vector<int> > readVVI(int n, int m) {
  vector<vector<int> > a(n, vector<int>(m));
  for (int i = 0; i < n; i++) a[i] = readVI(m);
  return a;
}
vector<long long> readVLL(long long n) {
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return a;
}
vector<vector<long long> > readVVLL(long long n, long long m) {
  vector<vector<long long> > a(n, vector<long long>(m));
  for (int i = 0; i < n; i++) a[i] = readVLL(m);
  return a;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void print(vector<int>& a) {
  for (auto el : a) {
    cout << el << ' ';
  }
  cout << '\n';
}
void print(vector<pair<int, int> >& a) {
  for (auto el : a) {
    cout << el.first << ',' << el.second << ' ';
  }
  cout << '\n';
}
void print(vector<int>& a, int n) {
  int cnt = 0;
  for (auto el : a) {
    if (cnt++ == n) break;
    cout << el << ' ';
  }
  cout << '\n';
}
void print(vector<vector<int> >& a) {
  for (auto el : a) {
    print(el);
  }
}
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
const int INF = 2e9;
const long long INFF = INT64_MAX;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, q;
const int N = 3e5 + 5;
vector<vector<int> > paths(N);
vector<pair<int, int> > edges(N);
vector<int> deg(N);
void mst() {
  vector<pair<int, int> > res;
  vector<int> par(n + 5);
  for (int i = 0; i <= n; i++) par[i] = i;
  function<int(int)> find = [&](int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
  };
  auto merge = [&](int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return 0;
    par[b] = a;
    return 1;
  };
  for (auto& [a, b] : edges) {
    if (merge(a, b)) {
      paths[a].push_back(b);
      paths[b].push_back(a);
    }
  }
}
void go() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges.push_back({a, b});
  }
  mst();
  vector<pair<int, int> > queries;
  vector<int> par(n + 5), lvl(n + 5);
  queue<pair<int, int> > bfs;
  lvl[1] = 0;
  bfs.push({1, 0});
  while (!bfs.empty()) {
    int pos, Par;
    tie(pos, Par) = bfs.front();
    bfs.pop();
    for (auto el : paths[pos]) {
      if (el == Par) continue;
      lvl[el] = lvl[pos] + 1;
      par[el] = pos;
      bfs.push({el, pos});
    }
  }
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    deg[a] ^= 1;
    deg[b] ^= 1;
    queries.push_back({a, b});
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += deg[i];
  if (ans == 0) {
    cout << "YES\n";
    auto answer = [&](int a, int b) {
      vector<int> pre, suf;
      while (a != b) {
        int A = lvl[a], B = lvl[b];
        if (A == B) {
          pre.push_back(a);
          suf.push_back(b);
          a = par[a];
          b = par[b];
        } else if (A > B) {
          pre.push_back(a);
          a = par[a];
        } else {
          suf.push_back(b);
          b = par[b];
        }
      }
      pre.push_back(a);
      while (!suf.empty()) {
        pre.push_back(suf.back());
        suf.pop_back();
      }
      cout << pre.size() << '\n';
      print(pre);
    };
    for (auto& [a, b] : queries) answer(a, b);
    return;
  }
  cout << "NO\n";
  cout << ans / 2 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) go();
  return (0 - 0);
}
