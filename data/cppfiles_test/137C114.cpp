#include <bits/stdc++.h>
using namespace std;
string bit_to_str(unsigned long long x) {
  string s = "";
  while (x > 0) {
    s.push_back('0' + (x % 2));
    x /= 2;
  }
  return s;
}
string y;
set<string> working;
string op1(string x) {
  reverse(x.begin(), x.end());
  while (!x.empty()) {
    if (x.back() == '1') break;
    x.pop_back();
  }
  return x;
}
string op2(string x) {
  reverse(x.begin(), x.end());
  x.push_back('1');
  return x;
}
bool rec(string x) {
  if (x == y) return true;
  if (working.find(x) != working.end()) return false;
  working.insert(x);
  if (x.length() > y.length() && x.front() == '1') return false;
  string x1 = op1(x), x2 = op2(x);
  if (rec(x1)) return true;
  if (rec(x2)) return true;
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  while (tc--) {
    working.clear();
    working.insert("");
    unsigned long long xs, ys;
    cin >> xs >> ys;
    string x = bit_to_str(xs);
    y = bit_to_str(ys);
    if (rec(x)) {
      cout << "YES";
    } else
      cout << "NO";
  }
  return 0;
}
