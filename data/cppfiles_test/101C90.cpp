#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto &x : v) cin >> x;
    string s;
    cin >> s;
    long long r = 0, b = 0;
    vector<long long> R, B;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'R') {
        R.push_back(v[i]);
        r++;
      }
      if (s[i] == 'B') {
        B.push_back(v[i]);
        b++;
      }
    }
    sort(B.begin(), B.end());
    sort(R.begin(), R.end());
    long long l = 1;
    bool poss = 1;
    for (auto x : B) {
      if (x < l) {
        poss = 0;
        break;
      }
      l++;
    }
    l = b + 1;
    for (auto x : R) {
      if (x > l) {
        poss = 0;
        break;
      }
      l++;
    }
    poss ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
