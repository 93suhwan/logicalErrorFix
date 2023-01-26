#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int diff = n / 2;
    mp.clear();
    bool ck = 0;
    for (int i = 0; i + diff <= n; i++) {
      string tmp = s.substr(i, diff);
      if (mp[tmp] != 0) {
        cout << mp[tmp] << " " << mp[tmp] + diff - 1 << " " << i + 1 << " "
             << i + diff << '\n';
        ck = 1;
        break;
      }
      mp[tmp] = i + 1;
    }
    if (ck) continue;
    for (int i = 0; i + diff <= n; i++) {
      if (s[i] == '0') {
        int cnt = 0;
        int j = i;
        while (j < n && s[j] == '0') {
          j++;
          cnt++;
        }
        if (cnt >= diff) {
          cout << 1 << " " << n << " " << i + 1 << " " << i + diff - 1 << '\n';
          break;
        } else if (cnt == diff - 1 && j < n) {
          cout << 1 << " " << n << " " << i + 1 << " " << i + diff << '\n';
          break;
        }
        i = j;
      }
    }
  }
  return 0;
}
