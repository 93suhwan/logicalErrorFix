#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s[N];
int sum[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < m; ++j)
      if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X') sum[j] = 1;
  for (int i = 1; i < m; ++i) sum[i] += sum[i - 1];
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    puts(sum[r] - sum[l] ? "NO" : "YES");
  }
}
