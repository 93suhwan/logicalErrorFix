#include <bits/stdc++.h>
using namespace std;
vector<string> solve(int n) {
  vector<string> a;
  vector<string> b;
  if (n == 1) {
    a.push_back("()");
    return a;
  }
  if (n == 2) {
    a.push_back("(())");
    a.push_back("()()");
    return a;
  }
  a = solve(n - 1);
  for (int i = 0; i < a.size(); i++) {
    string x = "(", y = "(", z = "(";
    x = x + a[i] + ")";
    y = y + ")" + a[i];
    z = a[i] + y + ")";
    b.push_back(x);
    b.push_back(y);
    b.push_back(z);
  }
  b.pop_back();
  return b;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> s;
    s = solve(n);
    for (int i = 0; i < s.size(); i++) {
      cout << s[i] << "\n";
    }
  }
  return 0;
}
