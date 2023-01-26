#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int LOG = 16;
const int maxn = (1 << 16);
inline long long int Max(const long long int &x, const long long int &y) {
  return x > y ? x : y;
}
inline long long int Min(const long long int &x, const long long int &y) {
  return x > y ? y : x;
}
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long int readl() {
  char ch = getchar();
  long long int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int A[N], mn[maxn];
vector<int> res, pos[N];
int find(int i, int a) {
  int l = 0, r = pos[i].size() - 1;
  if (a >= pos[i][r]) return r + 1;
  if (a < pos[i][0]) return 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (pos[i][mid] == a) {
      return mid + 1;
    }
    if (pos[i][mid] < a && pos[i][mid + 1] > a) {
      return mid + 1;
    }
    if (pos[i][mid] < a) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return r;
}
int main() {
  int n = read();
  for (int i = 0; i < maxn; i++) {
    mn[i] = INF;
  }
  for (int i = 1; i <= n; i++) {
    A[i] = read();
    pos[A[i]].push_back(i);
  }
  for (int i = 0; i <= 5000; i++) {
    if (pos[i].size() == 0) continue;
    mn[i] = min(mn[i], pos[i][0]);
    for (int j = 0; j < maxn; j++) {
      if (mn[j] != INF) {
        int _pos = find(i, mn[j]);
        if (_pos < 0 || _pos > pos[i].size() - 1) continue;
        _pos = pos[i][_pos];
        if (_pos > mn[j]) {
          int tmp = (i ^ j);
          mn[tmp] = min(mn[tmp], _pos);
        }
      }
    }
  }
  res.push_back(0);
  for (int i = 1; i < maxn; i++) {
    if (mn[i] != INF) {
      res.push_back(i);
    }
  }
  cout << res.size() << endl;
  for (auto x : res) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
