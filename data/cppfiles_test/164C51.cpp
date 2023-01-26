#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
namespace debug {
void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto z : x) cerr << (f++ ? "," : ""), __print(z);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
}  // namespace debug
using namespace debug;
const char nl = '\n';
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve() {
  int n, k;
  cin >> n >> k;
  string st;
  cin >> st;
  vector<int> redosled;
  vector<int> dep(n);
  vector<int> levi(n), desni(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    levi[i] = l;
    desni[i] = r;
  }
  function<void(int)> dfs = [&](int s) {
    if (levi[s] != -1) {
      dep[levi[s]] = dep[s] + 1;
      dfs(levi[s]);
    }
    redosled.push_back(s);
    if (desni[s] != -1) {
      dep[desni[s]] = dep[s] + 1;
      dfs(desni[s]);
    }
  };
  dfs(0);
  vector<bool> dobar(n);
  auto resi = [&](int l, int r) {
    if (r != n && st[redosled[r]] > st[redosled[l]]) {
      for (int i = l; i < r; ++i) {
        dobar[i] = true;
      }
    } else {
      for (int i = l; i < r; ++i) {
        dobar[i] = false;
      }
    }
  };
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && st[redosled[j]] == st[redosled[i]]) ++j;
    resi(i, j);
  }
  {
    vector<bool> novi(n);
    for (int i = 0; i < n; ++i) {
      novi[redosled[i]] = dobar[i];
    }
    dobar = novi;
  }
  const int LG = 18;
  vector<vector<int> > up(n, vector<int>(LG, -1));
  function<void(int, int)> dfs2 = [&](int s, int p) {
    up[s][0] = p;
    for (int i = 1; i < LG; ++i) {
      if (up[s][i - 1] == -1) {
        up[s][i] = -1;
        continue;
      }
      up[s][i] = up[up[s][i - 1]][i - 1];
    }
    int l = levi[s];
    int r = desni[s];
    if (l != -1) {
      dfs2(l, s);
    }
    if (r != -1) {
      dfs2(r, s);
    }
  };
  dfs2(0, -1);
  vector<bool> marked(n);
  ;
  function<void(int)> dfs3 = [&](int s) {
    int l = levi[s];
    int r = desni[s];
    if (l != -1) dfs3(l);
    cout << st[s];
    if (r != -1) dfs3(r);
  };
  function<void(int)> dfs4 = [&](int s) {
    if (levi[s] != -1) dfs4(levi[s]);
    if (!marked[s] && dobar[s]) {
      int tren = s;
      int ides = -1;
      int ima = -1;
      if (!marked[0]) {
        ides = -1;
        ima = dep[tren] + 1;
      } else {
        ides = tren;
        for (int i = LG - 1; i >= 0; --i) {
          int x = up[ides][i];
          if (x == -1) continue;
          if (marked[x]) continue;
          ides = x;
        }
        ides = up[ides][0];
        ima = dep[tren] - dep[ides];
      }
      if (ima <= k) {
        k -= ima;
        while (1) {
          if (tren == ides) break;
          marked[tren] = true;
          tren = up[tren][0];
        }
      }
    }
    cout << st[s];
    if (marked[s]) {
      cout << st[s];
      if (desni[s] != -1) dfs4(desni[s]);
    } else {
      if (desni[s] != -1) dfs3(desni[s]);
    }
  };
  dfs4(0);
  cout << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testCases = 1;
  while (testCases--) solve();
}
