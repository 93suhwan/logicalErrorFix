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
    for (long long int i = 0; i < s.size(); i++) {
      fre[s[i] - 'a']++;
    }
    long long int count = 0;
    for (long long int i = 0; i < s.size(); i++) {
      if (fre[s[i] - 'a'] >= 2) {
        count += 2;
        fre[s[i] - 'a'] = 0;
      } else {
        count += fre[s[i] - 'a'];
        fre[s[i] - 'a'] = 0;
      }
    }
    cout << count / 2 << '\n';
  }
}
