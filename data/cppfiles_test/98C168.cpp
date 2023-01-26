#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0), cin.sync_with_stdio(0);
o:
  int t;
  cin >> t;
  while (t--) {
    string temp;
    map<char, int> key_idx;
    cin >> temp;
    for (int i = 0; i < ((int)((temp).size())); ++i) {
      key_idx[temp[i]] = i;
    }
    string str;
    cin >> str;
    int res = 0;
    for (int i = 1; i < ((int)((str).size())); ++i) {
      res += abs(key_idx[str[i]] - key_idx[str[i - 1]]);
    }
    cout << res << "\n";
  }
  return 0;
}
