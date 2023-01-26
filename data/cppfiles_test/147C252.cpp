#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[s.size() + 5];
    a[0] = 1;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'N') tmp++;
    }
    if (tmp == 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
