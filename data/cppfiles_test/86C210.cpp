#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int OO = 1e8;
const int N = 1e5 + 10, M = N << 1;
int n, m, k, T;
int a, b, c;
string str, s;
inline int getMX(int msk) {
  for (int i = 0; i < 3; ++i) {
    if ((msk >> i) & 1) continue;
    return i;
  }
  return 0;
}
inline void SetMsk(int &msk, char x) { msk |= (1 << (x - '0')); }
int dp[N][4], vis[N][4], vid;
int Solve(int idx, int msk) {
  if (idx == n) return getMX(msk);
  int &ret = dp[idx][msk];
  if (vis[idx][msk] == vid) return ret;
  vis[idx][msk] = vid;
  SetMsk(msk, str[idx]);
  SetMsk(msk, s[idx]);
  ret = Solve(idx + 1, msk);
  ret = max(ret, getMX(msk) + Solve(idx + 1, 0));
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> str >> s;
    ++vid;
    cout << Solve(0, 0) << "\n";
  }
  return 0;
}
