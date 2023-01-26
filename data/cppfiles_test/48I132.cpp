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
int A[100005];
int B[100005];
int Mx[100005][18];
int Mi[100005][18];
int LOG[100005];
int queryMx(int l, int r) {
  int e = LOG[r - l + 1];
  return max(Mx[l][e], Mx[r - (1 << e) + 1][e]);
}
int queryMi(int l, int r) {
  int e = LOG[r - l + 1];
  return min(Mi[l][e], Mi[r - (1 << e) + 1][e]);
}
void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) cin >> B[i];
  for (int i = 1; i <= n; i++)
    Mx[i][0] = Mi[i][0] = (A[i] = B[i] - A[i] + A[i - 1]);
  for (int i = 2; i <= 100005; i++) LOG[i] = LOG[i >> 1] + 1;
  for (int e = 1; e <= 17; e++)
    for (int i = 1; i + (1 << e) - 1 <= n; i++) {
      Mx[i][e] = max(Mx[i][e - 1], Mx[i + (1 << (e - 1))][e - 1]);
      Mi[i][e] = min(Mi[i][e - 1], Mi[i + (1 << (e - 1))][e - 1]);
    }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    if (A[r] - A[l - 1] != 0 || queryMi(l, r) - A[l - 1] < 0) {
      cout << -1 << endl;
      continue;
    }
    cout << queryMx(l, r) - A[l - 1] << endl;
  }
}
int main() {
  ;
  solve();
  return 0;
}
