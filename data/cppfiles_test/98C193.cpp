#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int t, ans;
char ch[N];
map<char, int> mp;
signed main() {
  cin >> t;
  while (t--) {
    scanf("%s", ch + 1);
    int n = strlen(ch + 1), ans = 0;
    mp.clear();
    for (int i = 1; i <= 26; i++) mp[ch[i]] = i;
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    for (int i = 2; i <= n; i++) {
      ans += abs(mp[ch[i]] - mp[ch[i - 1]]);
    }
    cout << ans << '\n';
  }
  return 0;
}
