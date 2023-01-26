#include <bits/stdc++.h>
using namespace std;
const long long INF = (1LL << 60) - 1;
const int N = (int)(1e5) + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    sort(s.begin(), s.end());
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
      mp[s[i]]++;
    }
    if (!mp[t[0]] or !mp[t[1]] or !mp[t[2]] or t != "abc") {
      cout << s << "\n";
    } else {
      while (mp['a']) {
        cout << 'a';
        mp['a']--;
      }
      while (mp['c']) {
        cout << 'c';
        mp['c']--;
      }
      while (mp['b']) {
        cout << 'b';
        mp['b']--;
      }
      for (int i = 0; i < n; i++) {
        if (s[i] != 'a' and s[i] != 'b' and s[i] != 'c') cout << s[i];
      }
      cout << "\n";
    }
  }
  cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms"
       << "\n";
  return 0;
}
