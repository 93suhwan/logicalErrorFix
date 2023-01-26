#include <bits/stdc++.h>
using namespace std;
long long x;
vector<long long> b;
long long f(string s) {
  long long k = 0;
  for (auto to : s)
    if (int(to) == x) k++;
  return k - ((long long)s.size() - k);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<string> a(n);
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    x = 97;
    long long ans = 0;
    for (int l = 0; l < 5; l++) {
      for (int i = 0; i < n; i++) b[i] = f(a[i]);
      sort(b.begin(), b.end());
      reverse(b.begin(), b.end());
      long long s = 0;
      for (int i = 0; i < n; i++) {
        s += b[i];
        if (s <= 0) {
          ans = max(ans, (long long)i);
          break;
        }
      }
      if (s > 0) ans = max(ans, n);
      x++;
    }
    cout << ans << endl;
  }
}
