#include <bits/stdc++.h>
using namespace std;
const long long N = 500010, M = 5000, Mod = 1e9 + 7;
long long n, m;
string pat[] = {
    "abc", "acb", "bac", "bca", "cba", "cab",
};
long long Cnt[N][6];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  string s;
  cin >> s;
  s = '?' + s;
  for (int j = 0; j < 6; j++) {
    int Cur = 0;
    for (int i = 1; i <= n; i++) {
      Cnt[i][j] = Cnt[i - 1][j];
      if (s[i] != pat[j][Cur]) {
        Cnt[i][j]++;
      }
      Cur++;
      Cur %= 3;
    }
  }
  for (int i = 0; i < m; i++) {
    long long l, r;
    cin >> l >> r;
    long long Res = 1e16;
    for (int j = 0; j < 6; j++) {
      Res = min(Res, Cnt[r][j] - Cnt[l - 1][j]);
    }
    cout << Res << endl;
  }
  return 0;
}
