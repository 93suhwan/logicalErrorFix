#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> adj[n + 1];
    map<long long, long long> m;
    for (int i = 0; i < n; i++) {
      long long a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      m[b]++;
    }
    long long total = (n * (n - 1ll) * (n - 2ll)) / 6ll;
    long long minus = 0;
    for (long long i = 1; i <= n; i++) {
      long long sz = adj[i].size();
      if (sz <= 1) continue;
      for (auto it : adj[i]) {
        minus += ((sz - 1ll) * (m[it] - 1ll));
      }
    }
    cout << total - minus << "\n";
  }
  return 0;
}
