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
const long long LINF = 0x7f7f7f7f7f7f7f7f;
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
void s_main();
int main() {
  ;
  cout.tie(0);
  ios::sync_with_stdio(false);
  s_main();
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> heros;
  for (int i = 0; i < n; i++) {
    long long v;
    cin >> v;
    heros.push_back(v);
  }
  sort(heros.begin(), heros.end());
  long long sum = accumulate(heros.begin(), heros.end(), 0ll);
  heros.erase(unique(heros.begin(), heros.end()), heros.end());
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    int it = lower_bound(heros.begin(), heros.end(), x) - heros.begin();
    long long money = LINF;
    for (int i = 0; i < 3; i++) {
      int id = it + i - 1;
      if (id >= 0 && id < heros.size()) {
        money = min(money,
                    max(0ll, x - heros[id]) + max(0ll, y - (sum - heros[id])));
      }
    }
    cout << money << endl;
  }
}
void s_main() { solve(); }
