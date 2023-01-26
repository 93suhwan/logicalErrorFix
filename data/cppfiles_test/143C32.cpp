#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v;
    map<long long, long long> m;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
      if (m[a[i]] == 2) v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    long long e = 0, c = 0;
    for (long long i = 0; i <= n; i++) {
      if (e == 1)
        cout << -1 << " ";
      else if (m[i] > 0) {
        cout << m[i] + c << " ";
      } else if (m[i] == 0) {
        if (v.size() > 0) {
          if (e == 0) {
            cout << c << " ";
            auto it = lower_bound(v.begin(), v.end(), i);
            if (it == v.begin()) {
              e = 1;
            } else {
              it--;
              m[*it]--;
              c += (i - *it);
              if (m[*it] < 2) {
                v.erase(it);
              }
            }
          } else
            cout << -1 << " ";
        } else {
          if (e == 0) {
            cout << c << " ";
            e = 1;
          } else
            cout << -1 << " ";
        }
      }
    }
    cout << endl;
  }
}
