#include <bits/stdc++.h>
using namespace std;
void sp(long long cs) {
  long long n, i, j, m, k = 0, cnt = 0, ans = 0, res = 0, sum = 0;
  cin >> n;
  long long a[n + 2];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] >= cnt) {
      cnt = a[i];
      k = i;
    }
  }
  cout << cnt - k << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t, cs = 0;
  cin >> t;
  while (t--) {
    cs++;
    sp(cs);
  }
  return 0;
}
