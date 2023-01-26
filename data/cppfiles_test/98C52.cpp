#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    string a;
    string s;
    cin >> a >> s;
    vector<int> pos('z' + 1);
    for (int i = 0; i < a.size(); i++) pos[a[i]] = i;
    int ans = 0;
    for (int i = 1; i < s.size(); i++) ans += abs(pos[s[i]] - pos[s[i - 1]]);
    cout << ans << '\n';
  }
  return 0;
}
