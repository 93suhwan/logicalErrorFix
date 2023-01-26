#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string e, g;
  cin >> e >> g;
  long long int count = 0;
  for (long long int i = 0; i < n; i++) {
    if (g[i] == '1' && (e[i] == '0' || e[i + 1] == '1' || e[i - 1] == '1')) {
      count++;
    }
  }
  cout << count << endl;
}
int main(void) {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
