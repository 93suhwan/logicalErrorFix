#include <bits/stdc++.h>
using namespace std;
string sol1(int n) {
  string s = "";
  for (int i = 0; i < n; ++i) {
    s += "(";
  }
  for (int i = 0; i < n; ++i) {
    s += ")";
  }
  return s;
}
string sol2(int n) {
  string s = "";
  for (int i = 0; i < n; ++i) {
    s += "()";
  }
  return s;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    string s;
    for (int i = 0; i < n; ++i) {
      string s;
      s = sol1(n - i) + sol2(i);
      cout << s << endl;
    }
  }
}
