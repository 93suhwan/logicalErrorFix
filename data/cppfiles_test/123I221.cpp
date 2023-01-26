#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<vector<int> > v(200005);
priority_queue<long long> pq, tmp;
int dfs(int cur, int p) {
  if (v[cur].size() == 1 && v[cur].back() == p) return 1;
  for (auto i : v[cur]) {
    if (i == p) continue;
    tmp.push(dfs(i, cur));
  }
  int tp = tmp.top();
  tmp.pop();
  while (tmp.size()) {
    pq.push(tmp.top());
    tmp.pop();
  }
  return tp + 1;
}
void sol(int tc) {
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  pq.push(dfs(0, -1));
  long long ans = -1000000000000000000, sm = n;
  for (int i = 0; i < k + 1; i++) {
    long long tmp = min(n / 2, sm);
    ans = max(ans, (n - i - tmp) * (i - tmp));
    if (pq.size()) {
      sm -= pq.top();
      pq.pop();
    }
  }
  cout << ans;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sol(0);
  return 0;
}
