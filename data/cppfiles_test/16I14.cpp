#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    long long n = s.size();
    long long c = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        c++;
      }
    }
    cout << c << endl;
  }
}
