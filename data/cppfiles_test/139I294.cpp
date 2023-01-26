#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int yes = 1;
    for (int y = 0; y < s.size() / 2; y++) {
      if (s[y] != s[y + s.size() / 2]) yes = 0;
    }
    if (yes == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
