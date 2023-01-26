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
const pair<int, int> NILP = {0, -1};
inline int LT(int x) { return x << 1; }
inline int RT(int x) { return (x << 1) | 1; }
inline int LB(int x) { return x & -x; }
inline int MSK(int x) { return 1 << x; }
inline int HF(int x) { return x >> 1; }
inline int DB(int x) { return x << 1; }
inline int GT(int x, int i) { return (x >> i) & 1; }
inline int ST(int x, int i) { return x | (1 << i); }
inline int ODD(int x) { return x & 1; }
inline int SGN(int x) { return x >= 0 ? (x == 0 ? 0 : 1) : -1; }
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
int arr[1000005];
int tk[1000005];
void solve() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    tk[i] = arr[i] ? INF : 0;
  }
  for (int c = 0; c < 8; c++)
    for (int i = 0; i < n; i++) {
      int id = (i + d) % n;
      tk[id] = min(tk[id], tk[i] + 1);
    }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, tk[i]);
  }
  if (mx == INF) {
    cout << -1 << endl;
  } else {
    cout << mx << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
