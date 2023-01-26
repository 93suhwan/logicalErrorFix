#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int M = 5e5 + 5;
const int INF = 2e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, t, i, j, k;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2 == 1) {
      for (i = 1; i <= n / 2; i++) {
        cout << 'a';
      }
      cout << 'b';
      cout << 'c';
      for (i = 1; i <= n / 2 - 1; i++) {
        cout << 'a';
      }
      cout << '\n';
      continue;
    }
    n = n - 2;
    for (i = 1; i <= n / 2; i++) {
      cout << 'a';
    }
    cout << 'b';
    for (i = 1; i <= n / 2 - 1; i++) {
      cout << 'a';
    }
    cout << '\n';
  }
}
