#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> unorder[100005];
void push(int u, int v, int wt) {
  unorder[u].push_back(make_pair(v, wt));
  unorder[v].push_back(make_pair(u, wt));
}
int visited[100005];
vector<int> ans(100005, INT_MAX);
void shortestpath() {
  queue<int> q;
  q.push(1);
  visited[1] = 1;
  ans[1] = 0;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (auto a : unorder[t]) {
      if (visited[a.first] == 0) {
        visited[a.first] = 1;
        ans[a.first] = a.second + ans[t];
        q.push(a.first);
      }
    }
  }
}
bool isprime(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  int n, k;
  cin >> n >> k;
  int ar[n];
  map<int, vector<int>> mp;
  vector<pair<int, int>> vec;
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    vec.push_back(make_pair(ar[i], i));
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) {
    mp[vec[i].first].push_back(vec[i].second);
  }
  map<int, int> final;
  for (auto a : mp) {
    auto p = a.second;
    int y = p.size();
    maxx = max(maxx, y);
  }
  int f = min(k, maxx);
  vector<int> ve;
  for (auto a : mp) {
    auto p = a.second;
    int t = f;
    int i = 1;
    for (auto x : p) {
      ve.push_back(x);
      i++;
      if (i > t) break;
    }
  }
  int x = f;
  int p = ve.size() / f;
  p *= f;
  for (int i = 0; i < p; i++) {
    final[ve[i]] = x;
    x--;
    if (x == 0) {
      x = f;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << final[i] << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
