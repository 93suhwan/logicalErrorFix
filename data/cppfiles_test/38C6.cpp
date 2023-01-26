#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int sum[N], n, m, q;
string s[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  for (int i = (2); i <= (n); i++)
    for (int j = (2); j <= (m); j++)
      if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X') sum[j - 1] = 1;
  for (int i = (1); i <= (m); i++) sum[i] += sum[i - 1];
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    puts(sum[r - 1] - sum[l - 1] ? "NO" : "YES");
  }
  return 0;
}
