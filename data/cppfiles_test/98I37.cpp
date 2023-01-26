#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    string a;
    string s;
    cin >> a >> s;
    vector<vector<int> > time('z' + 1, vector<int>('z' + 1, 26));
    int temp;
    for (int i = 0; i < a.size() - 1; i++)
      for (int j = i; j < a.size(); j++) {
        temp = min(time[a[i]][a[j]], j - i);
        time[a[i]][a[j]] = time[a[j]][a[i]] = temp;
      }
    int ans = 0;
    for (int i = 1; i < s.size(); i++) ans += time[s[i]][s[i - 1]];
    cout << ans << '\n';
  }
  return 0;
}
