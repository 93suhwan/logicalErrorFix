#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long int mod = 1e9 + 7;
const long long int MAX = LLONG_MAX;
const long long int MIN = LLONG_MIN;
const long long int mxsize = 2 * 1e6;
vector<long long int> adj[mxsize];
long long int vis[mxsize] = {0};
void dfs(long long int node) {
  vis[node] = 1;
  for (long long int i = 0; i < adj[node].size(); i++) {
    long long int child = adj[node][i];
    if (!vis[child]) {
      dfs(child);
    }
  }
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (x) {
    if (x % 2) {
      res = (res * y) % mod;
    }
    x = x / 2;
    y = (y * y) % mod;
  }
  return res % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int z = 0, o = 0;
    long long int f = 0, k = 0;
    long long int n = s.length();
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '0') {
        z++;
        f = 1;
      } else {
        if (f == 1) {
          k++;
          f = 0;
        }
        o++;
      }
    }
    if (f == 1) k++;
    if (z == 0) {
      cout << 0 << "\n";
    } else if (o == 0) {
      cout << 1 << "\n";
    } else {
      long long int x = min(2 * 1LL, k);
      cout << x << "\n";
    }
  }
  return 0;
}
