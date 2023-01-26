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
        if (x == 1) a[i].insert(j);
      }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
      int cnt1 = 0, cnt2 = 0, cnt3 = 0;
      bool ok = true;
      for (int j = i + 1; j < 5; j++) {
        for (int q = 0; q < n; q++) {
          if (a[q].count(i + 1) & a[q].count(j + 1))
            cnt3++;
          else if (a[q].count(i + 1))
            cnt1++;
          else if (a[q].count(j + 1))
            cnt2++;
          else {
            ok = false;
            break;
          }
        }
        if (ok) continue;
        if (max(cnt1, cnt1) - min(cnt1, cnt2) <= cnt3 && cnt1 > 0 && cnt2 > 0) {
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
