#include <bits/stdc++.h>
const long long inf = 2e9;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    vector<char> v;
    for (int i = 0; i < int(s.size()); ++i) v.push_back(s[i]);
    sort(v.begin(), v.end());
    string res = "";
    if (t == "abc" and v[0] == 'a') {
      bool good = 0;
      for (int i = 0; i < int(v.size()); ++i) {
        if (v[i] == 'b') continue;
        if (v[i] > 'c' and good == 0) {
          good = 1;
          for (int j = 0; j < int(v.size()); ++j) {
            if (v[j] == 'b') res += v[j];
          }
        }
        res += v[i];
      }
      if (!good) {
        for (int i = 0; i < int(v.size()); ++i) {
          if (v[i] == 'b') res += v[i];
        }
      }
    } else {
      for (auto &a : v) res += a;
    }
    cout << res << endl;
  }
  return 0;
}
