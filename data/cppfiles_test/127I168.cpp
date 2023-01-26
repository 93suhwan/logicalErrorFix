#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s, tt;
  while (t--) {
    cin >> s >> tt;
    for (int i = 0; i < s.length(); i++) s[i] = 'a';
    cout << s << "b" << endl;
  }
  return 0;
}
