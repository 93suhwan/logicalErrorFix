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
    vector<long long> d;
    vector<long long> l;
    for (long long i = 0; i < n; ++i) {
      if (s[i] == '0')
        d.push_back(i);
      else
        l.push_back(i);
    }
    long long ind1 = 0;
    long long ind2 = 0;
    long long k1 = 1;
    long long k2 = d.size() + 1;
    for (long long i = 0; i < n; ++i) {
      if (ind1 < d.size() && i == d[ind1]) {
        p[i] = k1;
        k1++;
        ind1++;
      } else {
        p[i] = k2;
        k2++;
      }
    }
    for (long long j = 0; j < n; ++j) {
      cout << p[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
