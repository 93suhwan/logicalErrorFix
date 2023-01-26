#include <bits/stdc++.h>
using namespace std;
int ans, n, y, num, x0, cntx;
char ch[15];
string s;
vector<int> v;
map<int, bool> f;
void go(int ind) {
  if (ind == v.size()) {
    for (int j = 0; j <= 9; j++) {
      num = 0, x0 = 0;
      if (s[0] == '_')
        x0 = (ch[0] - '0');
      else if (s[0] == 'X')
        x0 = j;
      else
        x0 = (s[0] - '0');
      for (int i = n - 2; i < n; i++) {
        if (s[i] == '_')
          y = (ch[i] - '0');
        else if (s[i] == 'X')
          y = j;
        else
          y = (s[i] - '0');
        num = num * 10 + y;
      }
      if (!x0 && n > 1) continue;
      if (!(num % 25)) ans++;
      if (!cntx) break;
    }
    return;
  }
  for (int i = 0; i <= 9; i++) {
    ch[v[ind]] = char(i + '0');
    go(ind + 1);
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++)
    if (s[i] == '_')
      v.push_back(i);
    else if (s[i] == 'X')
      cntx++;
  go(0);
  cout << ans;
}
