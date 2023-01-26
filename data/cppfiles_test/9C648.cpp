#include <bits/stdc++.h>
using namespace std;
int main() {
  int g;
  cin >> g;
  for (int gg = 1; gg <= g; gg++) {
    int a[30] = {0};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) a[s[i] - 'a' + 1]++;
    int cnt = 0;
    for (int i = 1; i <= 26; i++) {
      if (a[i] == 1)
        cnt++;
      else if (a[i] >= 2) {
        cnt += 2;
      }
    }
    cout << cnt / 2 << endl;
  }
  return 0;
}
