#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int max(long long int a, long long int b) {
  if (a >= b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a >= b) return b;
  return a;
}
bool cycle(vector<vector<int>>& v, vector<int>& vis, int node) {
  vis[node] = 1;
  for (auto child : v[node]) {
    if (vis[child]) return true;
    if (cycle(v, vis, child)) return true;
  }
  vis[node] = 0;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for (long long int i = 0; i <= n - 1; i++) {
      int x;
      cin >> x;
      for (long long int j = 1; j <= x; j++) {
        int k;
        cin >> k;
        k--;
        indegree[k]++;
        adj[i].push_back(k);
      }
    }
    queue<int> Q;
    for (long long int i = 0; i <= n - 1; i++) {
      if (indegree[i] == 0) Q.push(i);
    }
    stack<int> st;
    while (Q.size()) {
      int x = Q.front();
      Q.pop();
      st.push(x);
      for (auto child : adj[x]) {
        indegree[child]--;
        if (indegree[child] == 0) {
          Q.push(child);
        }
      }
    }
    if (st.size() != n) {
      cout << "-1\n";
    } else {
      int ans = 1;
      vector<int> val(n, 0);
      while (!st.empty()) {
        int x = st.top();
        st.pop();
        int p = 1;
        for (auto child : adj[x]) {
          if (child < x)
            p = max(p, val[child]);
          else
            p = max(p, val[child] + 1);
        }
        val[x] = p;
        ans = max(ans, val[x]);
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
