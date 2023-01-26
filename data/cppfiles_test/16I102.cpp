#include <bits/stdc++.h>
using namespace std;
int t;
int k;
string s;
int a[27];
int main() {
  scanf("%d", &t);
  while (t--) {
    bool vis[27];
    for (int i = 0; i < 27; i++) a[i] = 0, vis[i] = 0;
    scanf("%d", &k);
    cin >> s;
    int ans = 0;
    for (int i = 0; i < k; i++) {
      a[s[i] - 'a']++;
      vis[s[i] - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++) {
      if (a[i] == k) {
        ans = 0;
        break;
      }
      if (vis[i] && a[i] > 0) ans++, vis[i] = 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}
