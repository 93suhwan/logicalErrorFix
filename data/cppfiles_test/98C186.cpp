#include <bits/stdc++.h>
using namespace std;
int ret_index(string s, char a) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == a) {
      return i + 1;
      break;
    }
  }
  return -1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int temp = 0;
    cin >> s;
    string p;
    cin >> p;
    int current = ret_index(s, p[1]);
    int pre = ret_index(s, p[0]);
    for (int i = 0; i < p.length(); i++) {
      current = ret_index(s, p[i]);
      temp = temp + abs(current - pre);
      pre = current;
    }
    cout << temp << endl;
  }
}
