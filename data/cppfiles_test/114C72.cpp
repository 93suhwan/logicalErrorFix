#include <bits/stdc++.h>
using namespace std;
const int M = 200007;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
priority_queue<pair<long long, vector<int> > > q;
vector<vector<int> > ans;
map<vector<int>, bool> wr, vist;
vector<int> st;
long long n, m, c[13], a[13][M], sum;
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    st.push_back(c[i]);
    for (int j = 1; j <= c[i]; ++j) scanf("%lld", &a[i][j]);
    sum += a[i][c[i]];
  }
  scanf("%lld", &m);
  while (m--) {
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }
    wr[v] = 1;
  }
  q.push({sum, st});
  while (!q.empty()) {
    vector<int> cur = q.top().second;
    long long sum = q.top().first;
    q.pop();
    if (vist[cur]) continue;
    vist[cur] = 1;
    if (!wr[cur]) {
      for (auto i : cur) cout << i << " ";
      cout << "\n";
      break;
    }
    ans.push_back(cur);
    for (int i = 0; i < n; ++i) {
      if (cur[i] > 1) {
        sum -= a[i + 1][cur[i]];
        --cur[i];
        sum += a[i + 1][cur[i]];
        q.push({sum, cur});
        sum -= a[i + 1][cur[i]];
        ++cur[i];
        sum += a[i + 1][cur[i]];
      }
    }
  }
  return 0;
}
