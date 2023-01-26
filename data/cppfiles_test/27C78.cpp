#include <bits/stdc++.h>
using namespace std;
string solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (m < n - 1 || k <= 1 || m > n * (n - 1) / 2) {
    return "NO";
  } else if (m == 0 && n == 1) {
    return "YES";
  } else if (k == 2 || (k == 3 && (n * (n - 1) / 2 != m))) {
    return "NO";
  }
  return "YES";
}
int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cout << solve() << endl;
  }
  return 0;
}
