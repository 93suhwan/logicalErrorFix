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
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    mp[ar[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (mp[ar[i]] > k) {
      mp[ar[i]]--;
      cout << "0"
           << " ";
    } else if (mp[ar[i]] > 0) {
      cout << mp[ar[i]] << " ";
      mp[ar[i]]--;
    } else {
      cout << "0" << '\n';
    }
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
