#include <bits/stdc++.h>
using namespace std;
string last[4] = {"00", "25", "50", "75"};
bool isCompatible(string s1, string s2) {
  char x;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == 'X') {
      x = s2[i];
      break;
    }
  }
  for (int i = 0; i < s1.size(); i++) {
    if ((isdigit(s1[i]) && s1[i] != s2[i]) || (s1[i] == 'X' && s2[i] != x))
      return false;
  }
  return true;
}
int Solve(string s, int start, int end) {
  int res = 0;
  for (int i = start; i < end; i++) {
    string q = to_string(i);
    for (int j = 0; j < 4; j++) {
      string tmp = q + last[j];
      res += (isCompatible(s, tmp) ? 1 : 0);
    }
  }
  return res;
}
int main() {
  string s;
  cin >> s;
  int res = 0;
  ;
  if (s.size() == 1) {
    if (s[0] >= '1' && s[0] <= '9')
      res = 0;
    else
      res = 1;
  } else if (s.size() == 2) {
    for (int i = 0; i < 4; i++) {
      string q = last[i];
      res += (isCompatible(s, q) ? 1 : 0);
    }
  } else {
    int front = s.size() - 2;
    int start = pow(10, front - 1), end = pow(10, front);
    res = Solve(s, start, end);
  }
  cout << res;
  return 0;
}
