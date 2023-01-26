#include <bits/stdc++.h>
using namespace std;
long long my_own() {
  long long n, i, j = 0, k, count = 0, ans = 0, sum = 0, x = 0, z = 0;
  cin >> n;
  long long a[n][5];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < 5; j++) cin >> a[i][j];
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  long long sup = 0;
  for (long long i = 1; i < n; i++) {
    count = 0;
    for (long long j = 0; j < 5; j++)
      if (a[i][j] < a[sup][j]) count++;
    if (count > 2) sup = i;
  }
  for (long long i = 0; i < n; i++) {
    if (i != sup) {
      count = 0;
      for (long long j = 0; j < 5; j++)
        if (a[i][j] < a[sup][j]) count++;
      if (count > 2) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << sup + 1 << endl;
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) my_own();
  return 0;
}
