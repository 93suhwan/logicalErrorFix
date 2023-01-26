#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int l = s.length();
    map<char, int> m;
    for (int i = 0; i < l; i++) m[s[i]]++;
    int d = m.size();
    cout << min(d, l / 2) << endl;
  }
  return 0;
}
