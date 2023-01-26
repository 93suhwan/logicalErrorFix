#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long OO = 1e9 + 1;
const int N = 1e4 + 5, M = 2000 + 10;
int n, m, k, T;
int a, b, c, d;
vector<int> v;
bool dp[2][M];
void clr(int lvl, int len, int val) {
  for (int i = 0; i <= len; ++i) dp[lvl][i] = val;
}
bool Solve(int val) {
  clr(1, val, 1);
  clr(0, val, 0);
  for (int lvl = 0; lvl < n; ++lvl) {
    int cur = lvl & 1;
    int prv = cur ^ 1;
    clr(cur, val, 0);
    for (int i = 0; i <= val; ++i) {
      if (i + v[lvl] <= val) dp[cur][i + v[lvl]] |= dp[prv][i];
      if (i - v[lvl] >= 0) dp[cur][i - v[lvl]] |= dp[prv][i];
    }
  }
  for (int i = 0; i <= val; ++i)
    if (dp[(n - 1) & 1][i]) return true;
  return false;
}
int BS() {
  int l = *max_element(v.begin(), v.end()), r = M - 1, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (Solve(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> n;
    v.resize(n);
    for (auto &it : v) cin >> it;
    cout << BS() << "\n";
  }
  return 0;
}
