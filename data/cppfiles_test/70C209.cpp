#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size(), bad = 0;
    vector<char> order;
    vector<int> count(26, 0);
    vector<bool> vis(26, false);
    vector<char> ans;
    int i, j, len = 0;
    for (i = n - 1; i >= 0; i--) {
      if (vis[s[i] - 'a'] == false) {
        order.push_back(s[i]);
        vis[s[i] - 'a'] = true;
      }
      count[s[i] - 'a']++;
    }
    reverse(order.begin(), order.end());
    for (i = 0; i < order.size(); i++) {
      if (count[order[i] - 'a'] % (i + 1) != 0) {
        bad = 1;
        break;
      }
      len += count[order[i] - 'a'] / (i + 1);
    }
    if (bad) {
      cout << -1 << endl;
      continue;
    }
    for (i = 0; i < len; i++) ans.push_back(s[i]);
    vector<bool> removed(26, false);
    vector<int> anscount(26, 0);
    for (i = 0; i < len; i++) anscount[ans[i] - 'a']++;
    i = 0, j = 0;
    int currsize = len, c = 0;
    while (i < n) {
      int start = i;
      j = 0;
      for (; i < start + currsize && j < len;) {
        if (removed[ans[j] - 'a'] == true) {
          j++;
          continue;
        }
        if (ans[j] != s[i]) {
          bad = 1;
          break;
        }
        i++;
        j++;
      }
      if (i != start + currsize) bad = 1;
      if (bad) break;
      removed[order[c] - 'a'] = true;
      currsize -= anscount[order[c] - 'a'];
      c++;
    }
    if (bad) {
      cout << -1 << endl;
      continue;
    }
    for (i = 0; i < len; i++) cout << ans[i];
    cout << " ";
    for (i = 0; i < order.size(); i++) cout << order[i];
    cout << endl;
  }
}
