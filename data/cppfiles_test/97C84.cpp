#include <bits/stdc++.h>
using namespace std;
template <class A>
void rd(vector<A>& v);
template <class T>
void rd(T& x) {
  cin >> x;
}
template <class H, class... T>
void rd(H& h, T&... t) {
  rd(h);
  rd(t...);
}
template <class A>
void rd(vector<A>& x) {
  for (auto& a : x) rd(a);
}
template <class T>
bool ckmin(T& a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
void __p(T a) {
  cout << a;
}
template <typename T, typename F>
void __p(pair<T, F> a) {
  cout << "{";
  __p(a.first);
  cout << ",";
  __p(a.second);
  cout << "}\n";
}
template <typename T>
void __p(std::vector<T> a) {
  cout << "{";
  for (auto it = a.begin(); it < a.end(); it++)
    __p(*it), cout << ",}\n"[it + 1 == a.end()];
}
template <typename T, typename... Arg>
void __p(T a1, Arg... a) {
  __p(a1);
  __p(a...);
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : ";
  __p(arg1);
  cout << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  int64_t bracket = 0, i = 0;
  for (;; i++)
    if (names[i] == ',' && bracket == 0)
      break;
    else if (names[i] == '(')
      bracket++;
    else if (names[i] == ')')
      bracket--;
  const char* comma = names + i;
  cout.write(names, comma - names) << " : ";
  __p(arg1);
  cout << " | ";
  __f(comma + 1, args...);
}
void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(cin.failbit);
  cout.precision(15);
  cout << fixed;
  if (((int64_t)(s).size())) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
const int64_t dx[] = {1, -1, 0, 0};
const int64_t dy[] = {0, 0, 1, -1};
const int64_t N = 500;
vector<int64_t> g[N * N], color(N*N, -1);
;
vector<bool> vis(N* N, false);
void end() {
  cout << "NO";
  exit(0);
}
int64_t id(pair<int64_t, int64_t> p) { return N * p.first + p.second; };
int64_t id(int64_t i, int64_t j) { return N * i + j; };
signed main() {
  setIO();
  int64_t n, m;
  rd(n, m);
  vector<string> a(n);
  rd(a);
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t j = 0; j < m; ++j) {
      if (a[i][j] == 'X') {
        vector<pair<int64_t, int64_t>> tmp;
        for (int64_t k = 0; k < 4; ++k) {
          int64_t ni = i + dx[k], nj = j + dy[k];
          if (a[ni][nj] == '.') {
            tmp.emplace_back(ni, nj);
          }
        }
        if (((int64_t)(tmp).size()) & 1) end();
        if (((int64_t)(tmp).size()) == 2) {
          g[id(tmp[0])].push_back(id(tmp[1]));
          g[id(tmp[1])].push_back(id(tmp[0]));
        } else if (((int64_t)(tmp).size()) == 4) {
          g[id(tmp[0])].push_back(id(tmp[2]));
          g[id(tmp[0])].push_back(id(tmp[3]));
          g[id(tmp[2])].push_back(id(tmp[0]));
          g[id(tmp[3])].push_back(id(tmp[0]));
          g[id(tmp[1])].push_back(id(tmp[2]));
          g[id(tmp[1])].push_back(id(tmp[3]));
          g[id(tmp[2])].push_back(id(tmp[1]));
          g[id(tmp[3])].push_back(id(tmp[1]));
        }
      }
    }
  }
  function<void(int64_t)> dfs = [&](int64_t i) -> void {
    for (auto j : g[i]) {
      if (!vis[j]) {
        vis[j] = true;
        color[j] = 1 ^ color[i];
        dfs(j);
      } else {
        if (!(color[i] ^ color[j])) assert(false);
      }
    }
  };
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t j = 0; j < m; ++j) {
      if (a[i][j] == '.' && !vis[id(i, j)]) {
        color[id(i, j)] = 0;
        vis[id(i, j)] = true;
        dfs(id(i, j));
      }
    }
  }
  int64_t ans[n][m];
  memset(ans, 0, sizeof(ans));
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t j = 0; j < m; ++j) {
      if (a[i][j] == '.') {
        ans[i][j] = color[id(i, j)] ? 1 : 4;
      }
    }
  }
  cout << "YES"
       << "\n";
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t j = 0; j < m; ++j) {
      if (a[i][j] == 'X') {
        for (int64_t k = 0; k < 4; ++k) {
          int64_t ni = i + dx[k], nj = j + dy[k];
          if (a[ni][nj] == '.') {
            ans[i][j] += ans[ni][nj];
          }
        }
      }
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}
