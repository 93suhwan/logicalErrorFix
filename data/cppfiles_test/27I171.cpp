#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1;
int T;
long long n, m, k;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    long long edges = n * (n - 1) / 2;
    if (k <= 1) {
      cout << "NO\n";
      continue;
    }
    if (m == 0) {
      cout << "YES\n";
      continue;
    }
    if (k == 2) {
      cout << "NO\n";
      continue;
    }
    if (m > edges) {
      cout << "NO\n";
      continue;
    }
    if (k == 3) {
      if (m == edges)
        cout << "YES\n";
      else
        cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
  return 0;
}
