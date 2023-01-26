#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[26] = {}, c = 0;
    for (auto i : s) {
      if (a[i - 'a'] == 2) continue;
      c++;
      a[i - 'a']++;
    }
    cout << c / 2 << "\n";
  }
  return 0;
}
