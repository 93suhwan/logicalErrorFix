#include <bits/stdc++.h>
using namespace std;
vector<long long> x;
const long long M = 31;
void solve() {
  long long n;
  cin >> n;
  string e, g;
  cin >> e >> g;
  long long count = 0;
  for (long long j = 0; j < n; j++) {
    if (g[j] == '0') {
      continue;
    } else if (j != 0 && e[j - 1] == '1') {
      count++;
    } else if (e[j] == '0') {
      count++;
    } else if ((j != (n - 1)) && e[j + 1] == '1') {
      e[j + 1] = '0';
      count++;
    }
  }
  cout << count << "\n";
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
