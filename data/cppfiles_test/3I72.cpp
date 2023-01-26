#include <bits/stdc++.h>
using namespace std;
int ans, n, y, num, x0;
char ch[15];
string s;
vector<int> v;
map<int, bool> f;
void go(int ind) {
  if (ind == v.size()) {
    for (int j = 0; j <= 9; j++) {
      num = 0, x0 = 0;
      for (int i = 0; i < n; i++) {
        if (s[i] == '_')
          y = (ch[i] - '0');
        else if (s[i] == 'X')
          y = j;
        else
          y = (s[i] - '0');
        if (!i) x0 = y;
        num = num * 10 + y;
      }
      if (!x0 && n > 1) break;
      if (!(num % 25)) ans++;
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
    if (s[i] == '_') v.push_back(i);
  go(0);
  cout << ans / 10;
}
