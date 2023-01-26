#include <bits/stdc++.h>
using namespace std;
struct Tree {
  int val;
  Tree* right = NULL;
  Tree* left = NULL;
};
long long int b_expo(long long x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  int a;
  vector<pair<int, int>> adj[m + 1];
  for (long long int i = 1; i < n + 1; i++) {
    for (long long int j = 1; j < m + 1; j++) {
      cin >> a;
      if (a == 1) {
        adj[j].push_back({1, i});
      } else if (a == 3) {
        adj[j].push_back({-1, i});
      }
    }
  }
  for (long long int i = 0; i < k; i++) {
    cin >> a;
    if (adj[a].size() == 0) {
      cout << a << " ";
    } else {
      int id = a, lvl = 1;
      while (lvl != n + 1) {
        int s = 0, e = adj[id].size() - 1;
        int ans = -1;
        while (s <= e) {
          int mid = (s + e) / 2;
          if (adj[id][mid].second < lvl)
            s = m + 1;
          else {
            ans = mid;
            e = mid - 1;
          }
        }
        if (ans == -1) {
          lvl = n + 1;
        } else {
          lvl = adj[id][ans].second;
          int nxt = adj[id][ans].first;
          adj[id].erase(adj[id].begin() + ans);
          id += nxt;
        }
      }
      cout << id << " ";
    }
  }
  cout << endl;
}
int main() {
  solve();
  return 0;
}
