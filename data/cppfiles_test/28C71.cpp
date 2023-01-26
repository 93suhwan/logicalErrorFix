#include <bits/stdc++.h>
using namespace std;
namespace DBH {
const int DIR4[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int DIR8[8][2] = {{1, 0},   {-1, 0}, {0, 1},  {0, -1},
                        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
const int MOD197 = 1e9 + 7;
const int MOD19 = 1e9;
const int MOD353 = 998244353;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
inline int LT(int x) { return x << 1; }
inline int RT(int x) { return (x << 1) | 1; }
inline int LB(int x) { return x & -x; }
inline int MSK(int x) { return 1 << x; }
inline int HF(int x) { return x >> 1; }
inline int DB(int x) { return x << 1; }
inline int GT(int x, int i) { return (x >> i) & 1; }
inline int ODD(int x) { return x & 1; }
template <typename T>
inline void qread(T &X) {
  X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
}  // namespace DBH
using namespace DBH;
int n, m;
int arr[300005];
int cnt[300005];
int pre[300005];
int conn;
int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }
void unite(int u, int v) {
  int ur = find(u);
  int vr = find(v);
  if (ur != vr) {
    conn--;
    pre[ur] = vr;
  }
}
int subsolve(int k) {
  conn = n;
  for (int i = 0; i < n; i++) {
    pre[i] = i;
  }
  for (int i = 0; i < n; i++) {
    unite(i, (arr[i] - 1 + k) % n);
  }
  return n - conn;
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[(i - arr[i] + 1 + n) % n]++;
  }
  vector<int> ans;
  for (int i = 0; i <= n - 1; i++) {
    if (cnt[i] < n - 2 * m) continue;
    int k = subsolve(i);
    if (k <= m) ans.push_back(i);
  }
  cout << ans.size() << " ";
  for (int i : ans) cout << i << " ";
  cout << endl;
}
int main() {
  ;
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
