#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0), cin.sync_with_stdio(0);
o:
  int t;
  cin >> t;
  while (t--) {
    string key;
    map<char, int> key_idx;
    cin >> key;
    for (int i = 0; i < 26; ++i) {
      key_idx[key[i]] = i;
    }
    string str;
    int res = 0;
    for (int i = 1; i < ((int)((str).size())); ++i) {
      res += abs(key_idx[str[i]] - key_idx[str[i - 1]]);
    }
    cout << res << "\n";
  }
  return 0;
}
