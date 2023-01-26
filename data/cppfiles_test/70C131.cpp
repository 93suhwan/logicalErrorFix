#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 10, mod = 1e9 + 7;
char buf[N];
int main() {
  int tc = 1;
  scanf("%d", &tc);
  for (int cn = 1; cn <= tc; cn++) {
    scanf("%s", buf);
    string s = buf;
    vector<pair<int, int>> lst(26);
    for (int i = 0; i < 26; i++) {
      lst[i].first = -1;
      lst[i].second = i;
    }
    vector<int> cnt(26, 0);
    for (int i = 0; i < (int)s.size(); i++) {
      int c = s[i] - 'a';
      lst[c].first = i;
      cnt[c]++;
    }
    int len = 0;
    sort(lst.begin(), lst.end());
    string order;
    bool ok = 1;
    for (int i = 0, ord = 1; i < 26; i++) {
      if (lst[i].first == -1) continue;
      int c = lst[i].second;
      order += (c + 'a');
      if ((cnt[c] % ord) != 0) {
        ok = 0;
        break;
      }
      len += (cnt[c] / ord);
      ord++;
    }
    if (len > (int)s.size()) ok = 0;
    if (!ok) {
      puts("-1");
      continue;
    }
    string ans = s.substr(0, len);
    string temp = ans;
    string t;
    for (int i = 0; i < (int)order.size(); i++) {
      t += temp;
      string temp1;
      for (int j = 0; j < (int)temp.size(); j++) {
        if (temp[j] == order[i]) continue;
        temp1 += temp[j];
      }
      temp = temp1;
    }
    if (t != s)
      puts("-1");
    else
      printf("%s %s\n", ans.c_str(), order.c_str());
  }
  return 0;
}
