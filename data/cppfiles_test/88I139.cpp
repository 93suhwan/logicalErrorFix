#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long i, j;
  vector<long long> a, b;
  map<long long, deque<long long> > pos;
  map<long long, deque<long long> >::iterator ii;
  map<long long, deque<pair<long long, long long> > > places;
  for (i = 0; i < n * m; i++) {
    long long q;
    cin >> q;
    a.push_back(q);
    b.push_back(q);
    pos[q].push_back(i);
  }
  long long ryad = 1, mesto = 1;
  for (ii = pos.begin(); ii != pos.end(); ii++) {
    long long now = ii->first;
    deque<long long> cur = ii->second;
    for (i = 0; i < cur.size(); i++) {
      places[now].push_back({mesto, -ryad});
      mesto++;
      if (mesto > m) {
        ryad++;
        mesto = 1;
      }
    }
    sort(places[now].rbegin(), places[now].rend());
  }
  bool used[n + 4][m + 4];
  for (i = 0; i <= n + 1; i++)
    for (j = 0; j < m + 1; j++) used[i][j] = false;
  long long ans = 0;
  for (i = 0; i < n * m; i++) {
    long long cur = a[i];
    long long r = -places[cur][0].second;
    long long p = places[cur][0].first;
    places[cur].pop_front();
    for (j = 1; j < p; j++) {
      if (used[r][j]) ans++;
    }
    used[r][p] = true;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
