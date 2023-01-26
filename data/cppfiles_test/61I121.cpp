#include <bits/stdc++.h>
using namespace std;
long long C(long long n, long long k) {
  double res = 1;
  for (int i = 1; i <= k; ++i) res = res * (n - k + i) / i;
  return (long long)(res + 0.01);
}
vector<vector<long long int> > readGraph(long long n, long long m) {
  vector<vector<long long int> > g(n);
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  return g;
}
vector<vector<long long int> > readTree(int n) { return readGraph(n, n - 1); }
vector<long long int> adj[10005];
void solve() {
  long long n;
  cin >> n;
  vector<long long int> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long int> ans;
  bool flag = false;
  vector<bool> vis(n);
  for (long long i = 0; i < n; i++) {
    ans.push_back(i + 1);
    if (!flag && a[i] == 0 && a[(i + 1) % n] == 1) {
      ans.push_back(n + 1);
      ans.push_back(i + 2);
      i++;
      flag = true;
    }
  }
  ans.erase(unique((ans).begin(), (ans).end()), ans.end());
  if (!flag)
    cout << -1 << "\n";
  else {
    for (auto c : ans) cout << c << " ";
    cout << "\n";
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
