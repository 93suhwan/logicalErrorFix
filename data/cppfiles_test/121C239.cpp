#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test, ti, i, j, k, n, m, q;
  cin >> test;
  for (ti = 1; ti <= test; ti++) {
    cin >> n;
    string a, b;
    cin >> a >> b;
    int aone = count(a.begin(), a.end(), '1');
    int bone = count(b.begin(), b.end(), '1');
    long long dif = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) dif += 1;
    }
    long long ans = INT_MAX;
    if (aone == bone) {
      ans = min(ans, dif);
    }
    if (n - aone + 1 == bone) {
      ans = min(ans, n - dif);
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}
