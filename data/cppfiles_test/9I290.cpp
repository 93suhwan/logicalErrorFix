#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char a[60];
    cin >> a;
    int num = 0;
    int n = strlen(a);
    int ans = 0;
    if (n % 2 == 0) {
      map<char, int> s1;
      map<char, int> s2;
      int ans1 = 0;
      int ans2 = 0;
      for (int i = 0; a[i]; i++) {
        if (i % 2) {
          if (s1[a[i]] == 1) continue;
          s1[a[i]] = 1;
          ans1++;
        } else {
          if (s2[a[i]] == 1) continue;
          s2[a[i]] = 1;
          ans2++;
        }
        ans = max(ans1, ans2);
      }
      cout << ans << endl;
    } else {
      int sum = 0;
      for (int i = 0; a[i]; i++) {
        int ans1 = 0;
        int ans2 = 0;
        map<char, int> s1;
        map<char, int> s2;
        for (int j = 0, k = 0; a[j]; j++, k++) {
          if (j == i) {
            k--;
            continue;
          }
          if (k % 2) {
            if (s1[a[j]] == 1) continue;
            s1[a[j]] = 1;
            ans1++;
          } else {
            if (s2[a[j]] == 1) continue;
            s2[a[j]] = 1;
            ans2++;
          }
        }
        ans = max(ans1, ans2);
        if (ans > sum) sum = ans;
      }
      cout << sum << endl;
    }
  }
}
