#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    multiset<pair<long long, long long>> m;
    pair<long long, long long> vect;
    vector<pair<long long, long long>> v;
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      long long l, r;
      cin >> l >> r;
      vect.first = l;
      vect.second = r;
      m.insert(vect);
      v.push_back({l, r});
    }
    for (long long i = 0; i < n; i++) {
      long long fi = v[i].first;
      long long se = v[i].second;
      if (fi == se) {
        cout << fi << " " << fi << " " << fi << endl;
        continue;
      }
      long long tmp = 0;
      for (long long j = fi; j <= se; j++) {
        pair<long long, long long> vec;
        if (j == fi) {
          vec.first = fi + 1;
          vec.second = se;
          if (m.find(vec) != m.end()) {
            cout << fi << " " << se << " " << fi << endl;
            m.erase(m.find(vec));
            tmp = 1;
          }
        } else if (j == se) {
          vec.first = fi;
          vec.second = se - 1;
          if (m.find(vec) != m.end()) {
            cout << fi << " " << se << " " << se << endl;
            m.erase(m.find(vec));
            tmp = 1;
          }
        } else {
          vec.first = fi;
          vec.second = j - 1;
          if (m.find(vec) != m.end()) {
            cout << fi << " " << se << " " << j << endl;
            m.erase(m.find(vec));
            tmp = 1;
          } else {
            vec.first = j + 1;
            vec.second = se;
            if (m.find(vec) != m.end()) {
              cout << fi << " " << se << " " << j << endl;
              m.erase(m.find(vec));
              tmp = 1;
            }
          }
        }
        if (tmp == 1) {
          break;
        }
      }
    }
  }
  return 0;
}
