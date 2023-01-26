#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
using namespace std;
int n, m;
char s[maxn];
int sum[10][maxn];
int main() {
  cin >> n >> m;
  string t;
  scanf("%s", s + 1);
  t = "abc";
  int cnt = 0;
  do {
    for (int i = 1; i <= n; i++) {
      sum[cnt][i] = sum[cnt][i - 1] + (s[i] != t[i % 3]);
    }
    cnt++;
  } while (next_permutation(t.begin(), t.end()));
  while (m--) {
    int l, r;
    cin >> l >> r;
    int res = 0x3f3f3f3f;
    for (int i = 0; i < 6; i++) {
      res = min(res, sum[i][r] - sum[i][l - 1]);
    }
    cout << res << "\n";
  }
  return 0;
}
