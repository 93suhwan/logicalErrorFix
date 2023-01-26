#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (int i = 0; i < int(v.size()); ++i) is >> v[i];
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
  for (T x : v) os << x << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> s) {
  for (T x : s) os << x << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, multiset<T> s) {
  for (T x : s) os << x << " ";
  return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> m) {
  for (auto x : m) os << x << " ";
  return os;
}
template <typename T>
T sum(vector<T> v) {
  T summ = 0;
  for (int i = 0; i < int(int(v.size())); ++i) summ += v[i];
  return summ;
}
long long mod_pow(long long a, long long b) {
  long long sol = 1;
  while (b) {
    if (b & 1) {
      sol = (sol * a) % mod;
      b--;
    } else {
      a = (a * a) % mod;
      b /= 2;
    }
  }
  return sol;
}
long long rem(long long a, long long b) {
  long long res = a % b;
  return res < 0 ? res + b : res;
}
bool dfs(int v, vector<int> &status, vector<vector<int> > &g) {
  for (int to : g[v]) {
    if (status[to] == 0) {
      status[to] = 1;
      if (dfs(to, status, g)) return true;
    } else if (status[to] == 1) {
      return true;
    }
  }
  status[v] = 2;
  return false;
}
void test_case() {
  int n;
  cin >> n;
  vector<vector<int> > g(n + 1);
  vector<int> free;
  for (int i = 1; i < int(n + 1); ++i) {
    int k;
    cin >> k;
    if (k == 0) {
      free.push_back(i);
    }
    for (int j = 0; j < int(k); ++j) {
      int req;
      cin >> req;
      g[req].push_back(i);
    }
  }
  vector<int> status(n + 1);
  for (int i = 1; i < int(n + 1); ++i) {
    if (status[i] == 0 && dfs(i, status, g)) {
      cout << "-1\n";
      return;
    }
  }
  for (int i = 1; i < int(n + 1); ++i) {
    cerr << i << "   ";
    for (int x : g[i]) {
      cerr << x << " ";
    }
    cerr << "\n";
  }
  deque<pair<int, int> > q;
  int ans = 1;
  vector<int> vis(n + 1);
  for (int f : free) {
    vis[f] = true;
    q.push_back({f, 0});
  }
  while (!q.empty()) {
    auto [v, w] = q.front();
    if (w == 1) {
      ans++;
      deque<pair<int, int> > qaux;
      while (!q.empty()) {
        v = q.front().first;
        q.pop_front();
        for (int to : g[v]) {
          if (!vis[to]) {
            to > v ? qaux.push_front({to, 0}) : qaux.push_back({to, 1});
            vis[to] = true;
          }
        }
      }
      while (!qaux.empty()) {
        v = qaux.front().first;
        w = qaux.front().second;
        qaux.pop_front();
        w == 0 ? q.push_front({v, 0}) : q.push_back({v, 1});
      }
    } else {
      q.pop_front();
      for (int to : g[v]) {
        if (!vis[to]) {
          to > v ? q.push_front({to, 0}) : q.push_back({to, 1});
          vis[to] = true;
        }
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < int(t); ++i) test_case();
  return 0;
}
