#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], sum[N], n, m, q;
string s[N];
vector<int> dp[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i <= (n + 5); i++) dp[i].resize(m + 5);
  for (int i = (1); i <= (n); i++) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++)
      if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X') a[j - 1] = 1;
  for (int i = (1); i <= (m); i++) sum[i] = sum[i - 1] + a[i];
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l == r)
      puts("YES");
    else {
      if (sum[r - 1] - sum[l - 1] > 0)
        puts("NO");
      else
        puts("YES");
    }
  }
  return 0;
}
