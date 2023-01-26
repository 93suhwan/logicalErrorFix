#include <bits/stdc++.h>
using namespace std;
int t;
int n;
long long a[1000000];
map<long long, int> m;
int main() {
  cin >> t;
  while (t--) {
    m.clear();
    cin >> n;
    long long s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s = s + a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans = ans + m[a[i] * n];
      m[2 * s - a[i] * n] += 1;
    }
    cout << ans << endl;
  }
  return 0;
}
