#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string str;
    str.push_back(s[0]);
    for (int i = 1; i < s.size(); i++)
      if (s[i] != s[i + 1] || s[i] != s[i - 1]) str.push_back(s[i]);
    cout << str.size() / 2 << endl;
  }
  return 0;
}
