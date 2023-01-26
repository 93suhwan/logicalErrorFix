#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, c = getchar();
  bool f = 0;
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = 1;
  for (; isdigit(c); c = getchar()) x = x * 10 + (c & 15);
  return f ? -x : x;
}
const int N = (int)1e5 + 5;
vector<int> x, y;
vector<pair<pair<int, int>, int>> nod;
vector<pair<int, int>> hang[N], lie[N];
int n, m, preh[3][N], sufh[3][N], prel[3][N], sufl[3][N];
struct BIT {
  int sum[N];
  void clear() { memset(sum, 0, sizeof(sum)); }
  void add(int x) {
    for (int i = x; i < N; i += (i & -i)) {
      sum[i]++;
    }
  }
  int query(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
      ans += sum[i];
    }
    return ans;
  }
} pre[3], suf[3];
int main() {
  n = gi();
  for (int i = 1; i <= n; ++i) {
    int a = gi(), b = gi(), c = gi();
    x.push_back(a);
    y.push_back(b);
    nod.push_back(make_pair(make_pair(a, b), c));
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());
  y.resize(unique(y.begin(), y.end()) - y.begin());
  n = x.size(), m = y.size();
  for (auto t : nod) {
    pair<int, int> pos = t.first;
    int col = t.second;
    pos.first = lower_bound(x.begin(), x.end(), pos.first) - x.begin() + 1;
    pos.second = lower_bound(y.begin(), y.end(), pos.second) - y.begin() + 1;
    hang[pos.first].push_back(make_pair(pos.second, col));
    lie[pos.second].push_back(make_pair(pos.first, col));
    preh[col - 1][pos.first]++;
    prel[col - 1][pos.second]++;
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 2; j <= n; ++j) {
      preh[i][j] += preh[i][j - 1];
    }
    for (int j = 2; j <= m; ++j) {
      prel[i][j] += prel[i][j - 1];
    }
    for (int j = 1; j <= n; ++j) {
      sufh[i][j] = preh[i][n] - preh[i][j - 1];
    }
    for (int j = 1; j <= m; ++j) {
      sufl[i][j] = prel[i][m] - prel[i][j - 1];
    }
  }
  int ans = 0;
  for (int i = 1; i < m; ++i) {
    if (lie[i].empty()) continue;
    for (auto t : lie[i]) {
      pre[t.second - 1].add(t.first);
      suf[t.second - 1].add(n - t.first + 1);
    }
    {
      int tpre[3], tsuf[3];
      for (int j = 0; j < 3; ++j) {
        tpre[j] = pre[j].query((*lie[i].begin()).first - 1);
        tsuf[j] = suf[j].query((*lie[i].begin()).first);
      }
      ans = max(ans, min(min(tpre[0], tsuf[1]), sufl[2][i + 1]));
      ans = max(ans, min(min(tpre[1], tsuf[0]), sufl[2][i + 1]));
      ans = max(ans, min(min(tpre[0], tsuf[2]), sufl[1][i + 1]));
      ans = max(ans, min(min(tpre[2], tsuf[0]), sufl[1][i + 1]));
      ans = max(ans, min(min(tpre[1], tsuf[2]), sufl[0][i + 1]));
      ans = max(ans, min(min(tpre[2], tsuf[1]), sufl[0][i + 1]));
    }
    for (auto t : lie[i]) {
      int tpre[3], tsuf[3];
      for (int j = 0; j < 3; ++j) {
        tpre[j] = pre[j].query(t.first);
        tsuf[j] = suf[j].query(t.first + 1);
      }
      ans = max(ans, min(min(tpre[0], tsuf[1]), sufl[2][i + 1]));
      ans = max(ans, min(min(tpre[1], tsuf[0]), sufl[2][i + 1]));
      ans = max(ans, min(min(tpre[0], tsuf[2]), sufl[1][i + 1]));
      ans = max(ans, min(min(tpre[2], tsuf[0]), sufl[1][i + 1]));
      ans = max(ans, min(min(tpre[1], tsuf[2]), sufl[0][i + 1]));
      ans = max(ans, min(min(tpre[2], tsuf[1]), sufl[0][i + 1]));
    }
  }
  for (int i = 0; i < 3; ++i) {
    pre[i].clear();
    suf[i].clear();
  }
  for (int i = m; i > 1; --i) {
    if (lie[i].empty()) continue;
    for (auto t : lie[i]) {
      pre[t.second - 1].add(t.first);
      suf[t.second - 1].add(n - t.first + 1);
    }
    {
      int tpre[3], tsuf[3];
      for (int j = 0; j < 3; ++j) {
        tpre[j] = pre[j].query((*lie[i].begin()).first - 1);
        tsuf[j] = suf[j].query((*lie[i].begin()).first);
      }
      ans = max(ans, min(min(tpre[0], tsuf[1]), prel[2][i - 1]));
      ans = max(ans, min(min(tpre[1], tsuf[0]), prel[2][i - 1]));
      ans = max(ans, min(min(tpre[0], tsuf[2]), prel[1][i - 1]));
      ans = max(ans, min(min(tpre[2], tsuf[0]), prel[1][i - 1]));
      ans = max(ans, min(min(tpre[1], tsuf[2]), prel[0][i - 1]));
      ans = max(ans, min(min(tpre[2], tsuf[1]), prel[0][i - 1]));
    }
    for (auto t : lie[i]) {
      int tpre[3], tsuf[3];
      for (int j = 0; j < 3; ++j) {
        tpre[j] = pre[j].query(t.first);
        tsuf[j] = suf[j].query(t.first + 1);
      }
      ans = max(ans, min(min(tpre[0], tsuf[1]), prel[2][i - 1]));
      ans = max(ans, min(min(tpre[1], tsuf[0]), prel[2][i - 1]));
      ans = max(ans, min(min(tpre[0], tsuf[2]), prel[1][i - 1]));
      ans = max(ans, min(min(tpre[2], tsuf[0]), prel[1][i - 1]));
      ans = max(ans, min(min(tpre[1], tsuf[2]), prel[0][i - 1]));
      ans = max(ans, min(min(tpre[2], tsuf[1]), prel[0][i - 1]));
    }
  }
  for (int i = 0; i < 3; ++i) {
    pre[i].clear();
    suf[i].clear();
  }
  for (int i = 1; i < n; ++i) {
    if (hang[i].empty()) continue;
    for (auto t : hang[i]) {
      pre[t.second - 1].add(t.first);
      suf[t.second - 1].add(m - t.first + 1);
    }
    {
      int tpre[3], tsuf[3];
      for (int j = 0; j < 3; ++j) {
        tpre[j] = pre[j].query((*hang[i].begin()).first - 1);
        tsuf[j] = suf[j].query((*hang[i].begin()).first);
      }
      ans = max(ans, min(min(tpre[0], tsuf[1]), sufh[2][i + 1]));
      ans = max(ans, min(min(tpre[1], tsuf[0]), sufh[2][i + 1]));
      ans = max(ans, min(min(tpre[0], tsuf[2]), sufh[1][i + 1]));
      ans = max(ans, min(min(tpre[2], tsuf[0]), sufh[1][i + 1]));
      ans = max(ans, min(min(tpre[1], tsuf[2]), sufh[0][i + 1]));
      ans = max(ans, min(min(tpre[2], tsuf[1]), sufh[0][i + 1]));
    }
    for (auto t : hang[i]) {
      int tpre[3], tsuf[3];
      for (int j = 0; j < 3; ++j) {
        tpre[j] = pre[j].query(t.first);
        tsuf[j] = suf[j].query(t.first + 1);
      }
      ans = max(ans, min(min(tpre[0], tsuf[1]), sufh[2][i + 1]));
      ans = max(ans, min(min(tpre[1], tsuf[0]), sufh[2][i + 1]));
      ans = max(ans, min(min(tpre[0], tsuf[2]), sufh[1][i + 1]));
      ans = max(ans, min(min(tpre[2], tsuf[0]), sufh[1][i + 1]));
      ans = max(ans, min(min(tpre[1], tsuf[2]), sufh[0][i + 1]));
      ans = max(ans, min(min(tpre[2], tsuf[1]), sufh[0][i + 1]));
    }
  }
  for (int i = 0; i < 3; ++i) {
    pre[i].clear();
    suf[i].clear();
  }
  for (int i = n; i > 1; --i) {
    if (hang[i].empty()) continue;
    for (auto t : hang[i]) {
      pre[t.second - 1].add(t.first);
      suf[t.second - 1].add(m - t.first + 1);
    }
    {
      int tpre[3], tsuf[3];
      for (int j = 0; j < 3; ++j) {
        tpre[j] = pre[j].query((*hang[i].begin()).first - 1);
        tsuf[j] = suf[j].query((*hang[i].begin()).first);
      }
      ans = max(ans, min(min(tpre[0], tsuf[1]), preh[2][i - 1]));
      ans = max(ans, min(min(tpre[1], tsuf[0]), preh[2][i - 1]));
      ans = max(ans, min(min(tpre[0], tsuf[2]), preh[1][i - 1]));
      ans = max(ans, min(min(tpre[2], tsuf[0]), preh[1][i - 1]));
      ans = max(ans, min(min(tpre[1], tsuf[2]), preh[0][i - 1]));
      ans = max(ans, min(min(tpre[2], tsuf[1]), preh[0][i - 1]));
    }
    for (auto t : hang[i]) {
      int tpre[3], tsuf[3];
      for (int j = 0; j < 3; ++j) {
        tpre[j] = pre[j].query(t.first);
        tsuf[j] = suf[j].query(t.first + 1);
      }
      ans = max(ans, min(min(tpre[0], tsuf[1]), preh[2][i - 1]));
      ans = max(ans, min(min(tpre[1], tsuf[0]), preh[2][i - 1]));
      ans = max(ans, min(min(tpre[0], tsuf[2]), preh[1][i - 1]));
      ans = max(ans, min(min(tpre[2], tsuf[0]), preh[1][i - 1]));
      ans = max(ans, min(min(tpre[1], tsuf[2]), preh[0][i - 1]));
      ans = max(ans, min(min(tpre[2], tsuf[1]), preh[0][i - 1]));
    }
  }
  printf("%d\n", 3 * ans);
  return 0;
}
