#include <bits/stdc++.h>
using namespace std;
const int N = 50010, INF = 0x3f3f3f3f;
vector<pair<int, int> > q;
bool st[N];
void solve() {
  int n, k;
  cin >> n >> k;
  q.clear();
  memset(st, false, sizeof st);
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    q.push_back({a, b});
    st[a] = st[b] = true;
  }
  vector<int> res;
  for (int i = 1; i <= 2 * n; i++)
    if (!st[i]) res.push_back(i);
  sort(res.begin(), res.end());
  for (int i = 0, j = res.size() / 2; i < res.size() / 2; i++, j++)
    q.push_back({res[i], res[j]});
  int ans = 0;
  for (int i = 0; i < q.size(); i++)
    for (int j = 0; j < q.size(); j++) {
      if (i == j) continue;
      if (q[j].first >= q[i].first && q[j].first <= q[i].second &&
          !(q[j].second >= q[i].first && q[j].second <= q[i].second))
        ans++;
    }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
