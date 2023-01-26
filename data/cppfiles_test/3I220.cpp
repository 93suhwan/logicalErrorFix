#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int ans = 0;
void func(int i, string s) {
  if (i == s.size()) {
    int n = s.size();
    if (n > 1 && ((s[n - 2] - '0') * 10 + s[n - 1] - '0') % 25 == 0 &&
        s[0] != '0') {
      ans++;
    }
    if (n == 1 && s[0] == '0') {
      ans++;
    }
    return;
  }
  if (s[i] != '_')
    func(i + 1, s);
  else {
    for (int j = 0; j < 10; j++) {
      s[i] = j + '0';
      func(i + 1, s);
    }
  }
}
void solve(string s) {
  if (s.size() <= 4) {
    func(0, s);
  } else {
    int mul = 1;
    for (int i = 1; i + 2 < s.size(); i++) {
      if (s[i] == '_') mul *= 10;
    }
    string t = "";
    t += s[0];
    t += s[(int)(s.size()) - 2];
    t += s.back();
    int was = ans;
    func(0, t);
    ans += (ans - was) * 9;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i <= 9; i++) {
    string t = s;
    int cnt = 0;
    for (int j = 0; j < t.size(); j++) {
      if (t[j] == 'X') {
        t[j] = i + '0';
        cnt++;
      }
    }
    solve(t);
    if (cnt == 0) break;
  }
  cout << ans << endl;
  return 0;
}
