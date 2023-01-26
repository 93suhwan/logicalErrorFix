#include <bits/stdc++.h>
using namespace std;
int cnt[300];
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    memset(cnt, 0, sizeof cnt);
    int ans = 0, sum = 0;
    for (char c : s) cnt[c]++;
    for (int i = 'a'; i <= 'z'; i++)
      if (cnt[i] >= 2)
        ans++;
      else if (cnt[i] == 1)
        sum++;
    ans += sum / 2;
    cout << ans << endl;
  }
  return 0;
}
