#include <bits/stdc++.h>
using namespace std;
long long int longmin(long long int x, long long int y) {
  if (x > y) return y;
  return x;
}
long long int longmax(long long int x, long long int y) {
  if (x > y) return x;
  return y;
}
void solve() {
  int n;
  cin >> n;
  int u;
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= n; i++) {
    cin >> u;
    pq.push({u, i});
  }
  vector<pair<int, int>> pairs;
  while (!pq.empty() || pq.top().first != 0) {
    auto tp = pq.top();
    pq.pop();
    auto tp2 = pq.top();
    pq.pop();
    if (tp2.first == 0) break;
    pairs.push_back({tp2.second, tp.second});
    pq.push({tp2.first - 1, tp2.second});
    pq.push({tp.first - 1, tp.second});
  }
  cout << pairs.size() << "\n";
  for (auto i : pairs) cout << i.first << " " << i.second << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start, stop;
  start = clock();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  stop = clock();
  double timetaken = (double)(stop - start) / (double)CLOCKS_PER_SEC;
  cerr << "\n\n";
  cerr << timetaken << setprecision(5) << "\n";
}
