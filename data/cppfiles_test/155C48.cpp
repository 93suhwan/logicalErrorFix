#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t > 0) {
    t--;
    long long n;
    cin >> n;
    vector<long long> p(n);
    for (long long i = 0; i < n; ++i) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    map<long long, long long> d;
    map<long long, long long> l;
    long long k1 = 1;
    for (long long i = 0; i < n; ++i) {
      if (s[i] == '0') {
        d[p[i]] = 0;
      }
    }
    for (auto o : d) {
      d[o.first] = k1;
      k1++;
    }
    long long k2 = d.size() + 1;
    for (long long i = 0; i < n; ++i) {
      if (s[i] == '1') {
        l[p[i]] = 0;
      }
    }
    for (auto o : l) {
      l[o.first] = k2;
      k2++;
    }
    long long ind1 = 0;
    long long ind2 = 0;
    for (long long j = 0; j < n; ++j) {
      if (s[j] == '0')
        cout << d[p[j]] << " ";
      else
        cout << l[p[j]] << " ";
    }
    cout << "\n";
  }
  return 0;
}
