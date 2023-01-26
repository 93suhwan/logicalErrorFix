#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int i, n = s.size(), ans = 0, ctr1 = 0;
    vector<int> hash(26, 0);
    for (i = 0; i < n; i++) {
      hash[s[i] - 'a']++;
    }
    for (i = 0; i < 26; i++) {
      if (hash[i] > 1)
        ans++;
      else if (hash[i] == 1)
        ctr1++;
    }
    ans += (ctr1 / 2);
    cout << ans << endl;
  }
  return 0;
}
