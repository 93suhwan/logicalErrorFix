#include <bits/stdc++.h>
using namespace std;
void init() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  cout.sync_with_stdio(0);
}
vector<long long> visit(1000005, 0);
vector<bool> v(1000005, false);
vector<long long> vec;
long long n, d;
long long dfs(long long node) {
  if (!vec[node]) return 0;
  if (visit[node] > 0) return visit[node];
  if (!visit[node]) {
    return 1e18;
  }
  visit[node] = 0;
  long long next = (node + n - d) % n;
  visit[node] += dfs(next);
  visit[node]++;
  return visit[node];
}
int main() {
  init();
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    visit.clear();
    visit.resize(n + 5, 0);
    vec.clear();
    for (int i = 0; i < n; ++i) {
      long long a;
      cin >> a;
      vec.push_back(a);
    }
    long long mx = 0;
    for (int i = 0; i < n; ++i) {
      if (!visit[i]) mx = max(mx, dfs(i));
    }
    if (mx >= 1e18)
      cout << -1;
    else
      cout << mx;
    cout << "\n";
  }
}
