#include <bits/stdc++.h>
using namespace std;
string go(string t) {
  while (t.back() == '0') t.pop_back();
  reverse(t.begin(), t.end());
  return t;
}
string to_bit(long long x) {
  if (x == 0)
    return "";
  else {
    string s = to_bit(x / 2);
    s.push_back(char((x % 2) + '0'));
    return s;
  }
}
int main() {
  long long x, y;
  cin >> x >> y;
  unordered_map<string, int> map;
  queue<string> q;
  q.push(to_bit(x));
  map[to_bit(x)];
  while (!q.empty()) {
    string k = q.front();
    q.pop();
    if (k.size() > 100) continue;
    for (int i = 0; i < 2; i++) {
      string k2 = go(k + string(1, char('0' + i)));
      if (map.find(k2) == map.end()) {
        map[k2];
        q.push(k2);
      }
    }
  }
  if (map.find(to_bit(y)) != map.end()) {
    cout << "YES\n";
  } else
    cout << "NO\n";
  return 0;
}
