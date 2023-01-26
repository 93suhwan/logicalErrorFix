#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  if (n % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES ";
      return;
    } else {
      cout << "NO ";
      return;
    }
  } else {
    if (k % 2 == 1) {
      cout << "YES ";
      return;
    } else if (k % n == 0 && k != 0) {
      cout << "YES ";
      return;
    } else {
      cout << "NO ";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
}
