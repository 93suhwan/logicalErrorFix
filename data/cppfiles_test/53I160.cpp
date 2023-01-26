#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, n, m, k, i, j, cnt;
  string s, s1;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    cnt = 1;
    for (i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) {
        cnt++;
      }
    }
    if (cnt > k) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
