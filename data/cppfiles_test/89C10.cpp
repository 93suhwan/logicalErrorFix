#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], cnt[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
      int j = i + 1;
      while (j != 0 && a[i] % j == 0) {
        cnt[i]++;
        j--;
      }
    }
    int cur = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] > cur)
        ok = false;
      else
        cur++;
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
