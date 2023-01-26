#include <bits/stdc++.h>
using namespace std;
long long n, m1, m2, fa1[100005], fa2[100005], u, v, ans[100005][3], cnt;
long long find1(long long x) {
  fa1[x] = (fa1[x] == x) ? x : find1(fa1[x]);
  return fa1[x];
}
long long find2(long long x) {
  fa2[x] = (fa2[x] == x) ? x : find2(fa2[x]);
  return fa2[x];
}
void bin1(long long x, long long y) {
  fa1[find1(x)] = find1(y);
  return;
}
void bin2(long long x, long long y) {
  fa2[find2(x)] = find2(y);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; i++) fa1[i] = fa2[i] = i;
  for (int i = 1; i <= m1; i++) {
    cin >> u >> v;
    bin1(u, v);
  }
  for (int i = 1; i <= m2; i++) {
    cin >> u >> v;
    bin2(u, v);
  }
  cnt = 0;
  for (int i = 1; i <= n - 1; i++)
    for (int j = i + 1; j <= n; j++)
      if ((find1(i) != find1(j)) && (find2(i) != find2(j))) {
        cnt++;
        ans[cnt][1] = i;
        ans[cnt][2] = j;
        bin1(i, j);
        bin2(i, j);
      }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) cout << ans[i][1] << ' ' << ans[i][2] << endl;
  return 0;
}
