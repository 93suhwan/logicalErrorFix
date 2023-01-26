#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, c = 0;
  cin >> t;
  string s;
  for (int i = 0; i < t; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'N') c++;
    }
    if (c == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
    c = 0;
  }
  return 0;
}
