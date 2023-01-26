#include <bits/stdc++.h>
using namespace std;
string int_to_string(long long n) {
  string s = "";
  while (n) {
    long long now = n % 10;
    s += now + '0';
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long string_to_int(string s) {
  long long n = 0;
  for (int i = 0; i < (int)(s.size()); ++i) {
    n *= 10;
    n += s[i] - '0';
  }
  return n;
}
void chmin(int &a, int b) {
  if (b < a) {
    a = b;
  }
}
void chmax(int &a, int b) {
  if (b > a) {
    a = b;
  }
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int month[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
const int MAXN = 2e5 + 10;
vector<pair<int, int> > v[MAXN];
vector<pair<pair<int, int>, int> > E;
int d[MAXN];
int n, m;
void init() {
  E.clear();
  for (int i = 1; i <= n; ++i) {
    v[i].clear();
    d[i] = -1;
  }
}
bool dfs(int now, int fa) {
  for (int i = 0; i < (int)(v[now].size()); ++i) {
    int u = v[now][i].first, c = v[now][i].second;
    if (d[u] != -1) {
      if (d[now] ^ c != d[u]) {
        return 0;
      }
    } else {
      d[u] = d[now] ^ c;
      if (!dfs(u, now)) {
        return 0;
      }
    }
  }
  return 1;
}
void solve() {
  cin >> n >> m;
  init();
  for (int i = 1; i <= n - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    E.push_back(make_pair(pair<int, int>(a, b), c));
    if (c != -1) {
      c = __builtin_popcount(c) & 1;
      v[a].push_back(pair<int, int>(b, c));
      v[b].push_back(pair<int, int>(a, c));
    }
  }
  for (int i = 1; i <= m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(pair<int, int>(b, c));
    v[b].push_back(pair<int, int>(a, c));
  }
  for (int i = 1; i <= n; ++i) {
    if (d[i] == -1) {
      d[i] = 0;
      if (!dfs(i, 0)) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < (int)(E.size()); ++i) {
    if (E[i].second != -1) {
      cout << E[i].first.first << " " << E[i].first.second << " " << E[i].second
           << endl;
    } else {
      cout << E[i].first.first << " " << E[i].first.second << " "
           << (d[E[i].first.first] ^ d[E[i].first.second]) << endl;
    }
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  int TEST_CASE = 1;
  cin >> TEST_CASE;
  while (TEST_CASE--) {
    solve();
  }
  return 0;
}
