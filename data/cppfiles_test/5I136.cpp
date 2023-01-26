#include <bits/stdc++.h>
using namespace std;
vector<long long> x;
void solve() {
  long long n;
  cin >> n;
  string g, e;
  cin >> e >> g;
  long long count = 0;
  long long total = 0;
  for (auto i : g) {
    if (i == '1') {
      total++;
    }
  }
  for (long long j = 0; j < n; j++) {
    if (e[j] == '1' && g[j] == '1') {
      if (j != 0 && (e[j - 1] != '0' || g[j - 1] != '0')) {
        continue;
      }
      if (j != n - 1 && (e[j + 1] != '0' || g[j + 1] != '0')) {
        continue;
      }
      count++;
    }
  }
  cout << total - count << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
