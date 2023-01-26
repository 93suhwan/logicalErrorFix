#include <bits/stdc++.h>
using namespace std;
void run_case() {
  int n;
  cin >> n;
  pair<int, int> p[n];
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second, p[i].first %= 4, p[i].second %= 4;
  int mep[4][4];
  memset(mep, 0, sizeof mep);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int diff1 = abs(p[i].first - p[j].first);
      int diff2 = abs(p[i].second - p[j].second);
      if (!diff1 && !diff2)
        ans += i;
      else
        ans += mep[p[i].first][p[i].second] + mep[p[j].first][p[j].second];
    }
    int x = p[i].first % 4;
    int y = p[i].second % 4;
    mep[x][y]++;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) run_case();
}
