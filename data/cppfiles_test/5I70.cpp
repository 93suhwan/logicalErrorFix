#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string e, g;
  cin >> e >> g;
  long long int count = 0;
  vector<bool> taken(n);
  for (long long int i = 0; i < n; i++) {
    if (g[i] == '1') {
      for (long long int j = i - 1; j <= i + 1; j++) {
        if (j >= 0 && j < n) {
          if (!taken[j]) {
            if ((e[j] == '1' && i != j) || (e[j] == '0' && i == j)) {
              taken[j] == 1;
              count++;
              break;
            }
          }
        }
      }
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
