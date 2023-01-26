#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string k;
    cin >> k;
    unordered_map<char, int> m;
    int j = 1;
    for (long long i = 0; i < k.size(); i++) {
      m[k[i]] = j;
    }
    string s;
    cin >> s;
    if (s.size() <= 1) {
      cout << 0 << endl;
    } else {
      int ans = 0;
      for (int i = 1; i < s.size(); i++) {
        ans += abs(m[s[i]] - m[s[i - 1]]);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
