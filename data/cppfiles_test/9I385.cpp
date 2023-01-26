#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int fre[27] = {};
    fre[s[0] - 'a']++;
    long long int count = 0;
    for (long long int i = 0; i < s.size(); i++) {
      if (fre[s[i] - 'a'] > 2) count++;
      fre[s[i] - 'a']++;
    }
    long long int ans = s.size() - count;
    cout << ans / 2 << '\n';
  }
}
