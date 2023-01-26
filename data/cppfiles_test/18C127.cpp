#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int mx = 1e6 + 5;
const int INF = 1000000007;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y >>= 1;
    x = (x * x) % 1000000007;
  }
  return (res % 1000000007);
}
void solve() {
  long long n, d;
  cin >> n >> d;
  vector<long long> arr(n);
  cin >> arr;
  vector<int> adj[n];
  queue<int> q;
  vector<long long> dis(n, INF);
  for (int i = 0; i < n; i++) {
    long long next = (i + d) % n;
    if (arr[i] == 0) {
      q.push(i);
      dis[i] = 0;
    }
    adj[i].push_back(next);
  }
  while (q.size()) {
    long long sz = q.size();
    for (int i = 0; i < sz; i++) {
      long long curr = q.front();
      q.pop();
      for (auto child : adj[curr]) {
        if (arr[child] == 1 && dis[child] > dis[curr] + 1) {
          dis[child] = dis[curr] + 1;
          q.push(child);
          arr[child] = 0;
        }
      }
    }
  }
  long long ans = 0;
  for (auto i : dis) {
    if (i == INF) {
      cout << "-1\n";
      return;
    }
    ans = max(ans, i);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
