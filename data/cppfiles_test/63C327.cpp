#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize(2)
using namespace std;
inline long long rd() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
struct pair_hash {
  template <class T1, class T2>
  size_t operator()(pair<T1, T2> const &pair) const {
    size_t h1 = hash<T1>()(pair.first);
    size_t h2 = hash<T2>()(pair.second);
    return h1 ^ h2;
  }
};
int cmp(int first, int second) { return first > second; }
const int N = 1e6 + 10, INF = 0x3f3f3f3f, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
int first[N], s[N], lz[N];
int p1[N], p2[N];
int find(int p[], int x) {
  if (p[x] != x) p[x] = find(p, p[x]);
  return p[x];
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  for (long long i = (1); i <= (n); ++i) p1[i] = i, p2[i] = i;
  while (m1--) {
    int first, second;
    cin >> first >> second;
    first = find(p1, first);
    second = find(p1, second);
    if (first != second) p1[first] = second;
  }
  while (m2--) {
    int first, second;
    cin >> first >> second;
    first = find(p2, first);
    second = find(p2, second);
    if (first != second) p2[first] = second;
  }
  vector<pair<int, int> > kp;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int a1 = find(p1, i), b1 = find(p1, j);
      int a2 = find(p2, i), b2 = find(p2, j);
      if (a1 != b1 && a2 != b2) {
        p1[a1] = b1;
        p2[a2] = b2;
        kp.push_back({i, j});
      }
    }
  }
  cout << kp.size() << endl;
  for (auto k : kp) cout << k.first << ' ' << k.second << endl;
}
