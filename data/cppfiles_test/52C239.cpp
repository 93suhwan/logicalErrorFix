#include <bits/stdc++.h>
using namespace std;
void tarea() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long p = 1, i = 0, ans = 0;
    while (k) {
      if (k % 2 == 1) {
        p = 1;
        for (long long j = 0; j < i; j++) {
          p *= n;
          p %= 1000000007;
        }
        ans += (p % 1000000007);
        ans %= 1000000007;
        k /= 2;
      } else {
        k /= 2;
      }
      i++;
    }
    cout << ans % 1000000007 << endl;
  }
  return;
}
int main() {
  tarea();
  return 0;
}
