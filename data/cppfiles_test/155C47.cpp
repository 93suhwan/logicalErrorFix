#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long p[n], q[n], l = 0, r = 0;
    pair<long long, long long> a[n], b[n];
    for (long long i = 0; i < n; i++) cin >> p[i];
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        a[l].first = p[i];
        a[l].second = i;
        l++;
      } else {
        b[r].first = p[i];
        b[r].second = i;
        r++;
      }
    }
    sort(a, a + l);
    sort(b, b + r);
    for (long long i = 0; i < l; i++) q[a[i].second] = i + 1;
    for (long long i = 0; i < r; i++) q[b[i].second] = i + 1 + l;
    for (long long i = 0; i < n; i++) cout << q[i] << " ";
    cout << endl;
  }
  return 0;
}
