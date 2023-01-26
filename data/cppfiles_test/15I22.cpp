#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
int expmod(long long int a, long long int b, int m) {
  int res = 1;
  a = a % m;
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return res;
}
long long prodsum(vector<int>& arr, int k) {
  int n = arr.size();
  if (k == 0) return 1;
  if (n < k) return 0;
  if (arr[0] == arr.back()) {
    int common = arr[0];
    long long ans = expmod(common, k, MOD);
    for (int i = 1; i <= k; i++) {
      ans *= n + 1 - i;
      ans %= MOD;
      ans *= expmod(i, MOD - 2, MOD);
      ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    return ans;
  }
  vector<int> part(arr.begin() + 1, arr.end());
  return prodsum(part, k) + arr[0] * prodsum(part, k - 1);
}
int solve(vector<vector<int>>& adj, int k) {
  int n = adj.size();
  if (k == 2) {
    return (n * n - n) / 2;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    set<int> visited = {i};
    vector<map<int, int>> counts;
    for (int nbr : adj[i]) {
      visited.insert(nbr);
      map<int, int> m;
      set<int> current = {nbr};
      int dist = 1;
      m[1] = 1;
      while (current.size()) {
        m[dist] = current.size();
        set<int> next;
        for (int vtx : current) {
          for (int next_nbr : adj[vtx]) {
            if (!visited.count(next_nbr)) {
              next.insert(next_nbr);
              visited.insert(next_nbr);
            }
          }
        }
        current = next;
        dist++;
      }
      counts.push_back(m);
    }
    bool done = false;
    int dist = 1;
    while (!done) {
      vector<int> vals;
      for (map<int, int> count : counts) {
        if (count.find(dist) != count.end()) {
          vals.push_back(count[dist]);
        }
      }
      sort(vals.begin(), vals.end(), greater<int>());
      if (vals.size() < k) {
        done = true;
      } else {
        ans += prodsum(vals, k);
      }
      dist++;
    }
  }
  return ans;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    while (n-- > 1) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    cout << solve(adj, k) << endl;
  }
}
