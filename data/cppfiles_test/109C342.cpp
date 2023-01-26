#include <bits/stdc++.h>
using namespace std;
int main() {
  int times;
  cin >> times;
  for (int r = 0; r < times; r++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      int x = s[i] - 48;
      if (x != 0) ans += x;
      if (i != n - 1 && x != 0) ans++;
    }
    cout << ans << endl;
  }
}
