#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
int T;
string str;
string temp;
int n;
bool st[26];
bool check(string& s) {
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r]) return false;
    l++, r--;
  }
  return true;
}
bool check(char c) {
  temp.clear();
  for (int i = 0; i < n; ++i) {
    if (str[i] == c) continue;
    temp.push_back(str[i]);
  }
  return check(temp);
}
int cal(char c) {
  int l = 0, r = n - 1;
  int ans = 0;
  while (l < r) {
    if (str[l] == str[r]) {
      l++, r--;
    } else {
      if (str[l] == c) {
        l++;
        ans++;
      } else if (str[r] == c) {
        r--;
        ans++;
      }
    }
  }
  return ans;
}
int solve() {
  if (check(' ')) return 0;
  int ans = n;
  for (int i = 0; i <= 25; ++i) {
    if (st[i] && check('a' + i)) {
      ans = min(ans, cal('a' + i));
    }
  }
  if (ans == n) ans = -1;
  return ans;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    cin >> n >> str;
    memset(st, 0, sizeof st);
    for (int i = 0; i < n; ++i) {
      st[str[i] - 'a'] = true;
    }
    printf("%d\n", solve());
  }
  return 0;
}
