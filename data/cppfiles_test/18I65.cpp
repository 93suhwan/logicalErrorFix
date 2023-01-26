#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
int test, n, k;
const int MAXN = 101;
int connect[MAXN], sum[MAXN], mi[MAXN];
vector<int> unused;
bool calc(pair<int, int> x, pair<int, int> y) {
  if (x.first > y.first) swap(x, y);
  return x.second > y.first && x.second < y.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) {
    unused.clear();
    memset((connect), 0, sizeof(connect));
    vector<pair<int, int> > chords;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
      int x, y;
      cin >> x >> y;
      if (x > y) swap(x, y);
      chords.push_back({x, y});
      connect[x] = connect[y] = 1;
    }
    for (int i = 1; i <= 2 * n; i++) {
      if (!connect[i]) unused.push_back(i);
    }
    for (int i = 0; i <= n - k - 1; i++)
      chords.push_back({unused[i], unused[i + n - k]});
    int ans = 0;
    for (int i = 0; i <= n - 1; i++) {
      for (int j = i + 1; j <= n - 1; j++) {
        ans += calc(chords[i], chords[j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
