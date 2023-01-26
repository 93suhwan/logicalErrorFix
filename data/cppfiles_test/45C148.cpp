#include <bits/stdc++.h>
using namespace std;
int n;
int a[100007];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int ntest;
  cin >> ntest;
  while (ntest--) {
    cin >> n;
    int le, chan;
    le = chan = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0)
        chan++;
      else
        le++;
    }
    if (n % 2 == 0) {
      if (le != n / 2) {
        cout << -1 << '\n';
        continue;
      }
      vector<int> ch, l;
      ch.clear();
      l.clear();
      for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0)
          ch.push_back(i);
        else
          l.push_back(i);
      }
      int ans1, ans2;
      ans1 = ans2 = 0;
      for (int i = n; i >= 1; i--) {
        if (i % 2 == 0) {
          ans1 += abs(i - l[l.size() - 1]);
          l.pop_back();
          ans2 += abs(i - ch[ch.size() - 1]);
          ch.pop_back();
        }
      }
      cout << min(ans1, ans2) << '\n';
    } else {
      if (le != n / 2 + 1 && chan != n / 2 + 1) {
        cout << -1 << '\n';
        continue;
      }
      if (le == n / 2 + 1) {
        vector<int> v;
        v.clear();
        int ans = 0;
        for (int i = 1; i <= n; i++)
          if (a[i] % 2 != 0) {
            v.push_back(i);
          }
        for (int i = n; i >= 1; i--)
          if (i % 2 != 0) {
            ans += (abs(i - v[v.size() - 1]));
            v.pop_back();
          }
        cout << ans << '\n';
      } else {
        vector<int> v;
        v.clear();
        int ans = 0;
        for (int i = 1; i <= n; i++)
          if (a[i] % 2 == 0) {
            v.push_back(i);
          }
        for (int i = n; i >= 1; i--)
          if (i % 2 != 0) {
            ans += (abs(i - v[v.size() - 1]));
            v.pop_back();
          }
        cout << ans << '\n';
      }
    }
  }
  return 0;
}
