#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int t, n;
int a[N];
int main() {
  cin >> t;
  while (t--) {
    map<int, long long> m;
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (!m[a[i]])
        m[a[i]] = 1;
      else
        m[a[i]]++;
      sum += a[i];
    }
    double avg = sum / n;
    double k = sum - avg * (n - 2);
    if (k != int(k)) {
      cout << 0 << endl;
      continue;
    }
    long long count = 0;
    for (int i = 1; i <= n; i++) {
      if (!m[a[i]]) continue;
      if (2 * a[i] == k) {
        count += m[a[i]] * (m[a[i]] - 1) / 2;
        m[a[i]] = 0;
      } else if (m[k - a[i]]) {
        count += m[k - a[i]] * m[a[i]];
        m[k - a[i]] = 0;
        m[a[i]] = 0;
      }
    }
    cout << count << endl;
  }
  return 0;
}
