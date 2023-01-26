#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<set<int>> a(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        int x;
        cin >> x;
        if (x == 1) a[i].insert(j + 1);
      }
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
      for (int j = i + 1; j <= 5; j++) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        bool ok = false;
        for (int q = 0; q < n; q++) {
          if (a[q].count(i) && a[q].count(j))
            cnt3++;
          else if (a[q].count(i))
            cnt1++;
          else if (a[q].count(j))
            cnt2++;
          else
            ok = true;
        }
        if (ok) continue;
        if (abs(cnt1 - cnt2) <= cnt3) {
          ans = 1;
          break;
        }
      }
    }
    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
