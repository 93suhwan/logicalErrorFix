#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> vis(n);
    for (int i = 0, ggdem = m; i < ggdem; ++i) {
      long long a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      c--;
      vis[b] = 1;
    }
    long long ve = -1;
    for (int i = 0, ggdem = n; i < ggdem; ++i) {
      if (vis[i] == 0) ve = i;
    }
    for (int i = 0, ggdem = n; i < ggdem; ++i) {
      if (i != ve) {
        cout << i + 1 << " " << ve + 1 << "\n";
      }
    }
  }
  return 0;
}
