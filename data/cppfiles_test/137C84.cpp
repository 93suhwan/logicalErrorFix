#include <bits/stdc++.h>
using namespace std;
long long x, y;
string a, b;
set<string> q;
void dfs(string s) {
  while (s[s.length() - 1] == '0') s.pop_back();
  if (s.length() > 70 || q.count(s)) return;
  q.insert(s);
  reverse(s.begin(), s.end());
  dfs(s);
  dfs(s + "1");
}
int main() {
  cin >> x >> y;
  while (x) a.push_back('0' + x % 2), x /= 2;
  while (y) b.push_back('0' + y % 2), y /= 2;
  dfs(a);
  if (q.count(b))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
