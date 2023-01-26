#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    map<long long, long long> unique;
    cin >> n >> k;
    string s = to_string(n);
    long long cnt = 0;
    long long previ = -1;
    long long nowi = -1;
    char min = '9';
    bool f = false;
    for (long long i = 0; i < s.size(); i++) {
      if (f) {
        s[i] = min;
      } else {
        if (!unique[s[i]]) {
          cnt++;
          previ = nowi;
          nowi = i;
          if (!(cnt > k)) {
            if (min > s[i]) min = s[i];
            unique[s[i]] = true;
          }
        }
        if (cnt > k) {
          bool found = false;
          char assign = s[nowi] + 1;
          while (assign > s[nowi]) {
            if (unique[assign]) {
              found = true;
              unique[s[nowi]] = false;
              s[nowi] = assign;
              f = true;
              break;
            }
            if (assign >= '9') {
              break;
            }
            assign++;
          }
          if (!found) {
            if (min == s[previ]) min = s[previ] + 1;
            if (unique[s[previ] + 1]) min = '0';
            s[previ]++;
            f = true;
            i = previ;
          }
        }
      }
    }
    cout << s << '\n';
  }
  return 0;
}
