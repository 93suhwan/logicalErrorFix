#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    string s, temp;
    cin >> s;
    temp = s;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
      if (temp[i] != s[i]) ans += 1;
    }
    cout << ans << endl;
  }
}
