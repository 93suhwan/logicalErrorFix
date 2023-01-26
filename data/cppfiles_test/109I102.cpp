#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int a[maxn], b[maxn];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int na = a[0], nb = b[0];
    int ans = 0, wa = 0, wb = 0;
    while (na > nb) {
      if (a[wa] <= na) {
        na = a[wa++];
      }
      if (b[wb] >= nb) {
        nb = b[wb++];
      }
    }
    ans = wa + wb;
    if (ans > 0) ans -= 2;
    cout << ans << endl;
  }
  return 0;
}
