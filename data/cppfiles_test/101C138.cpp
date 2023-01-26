#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], i;
    for (i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    long long int f = 1;
    long long int b[n + 1], r[n + 1];
    memset(b, 0, sizeof(b));
    memset(r, 0, sizeof(r));
    long long int nb = 0, nr = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == 'B') {
        if (a[i] < 1)
          f = 0;
        else if (a[i] >= n)
          b[n]++;
        else
          b[a[i]]++;
      }
      if (s[i] == 'R') {
        if (a[i] > n)
          f = 0;
        else if (a[i] <= 1)
          r[1]++;
        else
          r[a[i]]++;
      }
    }
    for (i = 1; i <= n; i++) {
      b[i] += b[i - 1];
      if (b[i] > i) f = 0;
    }
    if (r[n] >= 2) f = 0;
    for (i = n - 1; i >= 1; i--) {
      r[i] += r[i + 1];
      if (r[i] > n - i + 1) f = 0;
    }
    if (f)
      cout << "YES";
    else
      cout << "NO";
    cout << "\n";
  }
  return 0;
}
