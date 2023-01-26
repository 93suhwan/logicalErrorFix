#include <bits/stdc++.h>
using namespace std;
bool tprime[1000001];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a[26]{0};
    int x = 0, y = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      a[int(s[i]) - 97]++;
    }
    for (int i = 0; i < 26; i++) {
      if (a[i] > 1)
        y++;
      else if (a[i] == 1)
        x++;
    }
    cout << y + (x / 2) << endl;
  }
  return 0;
}
