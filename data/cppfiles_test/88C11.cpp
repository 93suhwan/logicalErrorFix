#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 10;
const int maxn = 1e5 + 5;
struct Node {
  int val;
  int pos;
  friend bool operator<(Node a, Node b) {
    if (a.val != b.val) {
      return a.val < b.val;
    } else {
      return a.pos < b.pos;
    }
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    Node node[n * m + 1];
    for (int i = 1; i < n * m + 1; i++) cin >> node[i].val, node[i].pos = i;
    sort(node + 1, node + 1 + n * m);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1 + m * (i - 1); j <= m * (i); j++) {
        for (int k = 1 + m * (i - 1); k < j; k++) {
          if (node[k].pos < node[j].pos && node[k].val != node[j].val) ans++;
        }
      }
    }
    cout << ans << "\n";
  }
}
