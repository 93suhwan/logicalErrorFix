#include <bits/stdc++.h>
using namespace std;
void debug(int x) { cout << "debug: " << x << '\n'; }
void del(string &s) {
  for (auto &x : s) {
    if (x == '1')
      break;
    else
      x = '$';
  }
  s.erase(remove(s.begin(), s.end(), '$'), s.end());
}
string sa, sb;
set<string> reached;
void f(string s) {
  if (s.size() > 64) return;
  if (reached.count(s) > 0) return;
  reached.insert(s);
  string s1 = s, s2 = s;
  reverse(s1.begin(), s1.end());
  s1 = '1' + s1;
  reverse(s2.begin(), s2.end());
  del(s2);
  f(s1);
  f(s2);
}
int main() {
  long long a, b;
  cin >> a >> b;
  bitset<64> x(a), y(b);
  sa = x.to_string(), sb = y.to_string();
  del(sa);
  del(sb);
  f(sa);
  if (reached.count(sb) > 0)
    cout << "YES";
  else
    cout << "NO";
}
