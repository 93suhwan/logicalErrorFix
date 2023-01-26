#include <bits/stdc++.h>
using namespace std;
int a[1001000];
int bb[1010000];
int rr[1001000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      bb[i] = 0;
      rr[i] = 0;
      cin >> a[i];
      a[i] = max(a[i], 1);
      a[i] = min(a[i], n);
    }
    bb[n] = 0;
    rr[n] = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B')
        bb[a[i]]++;
      else
        rr[a[i]]++;
    }
    int g = 0;
    string ans = "YES";
    for (int i = 1; i <= n; i++) {
      g += bb[i];
      if (g > i) ans = "NO";
    }
    g = 0;
    for (int i = n; i >= 0; i--) {
      int x = n - i + 1;
      g += rr[i];
      if (g > x) ans = "NO";
    }
    cout << ans << endl;
  }
}
