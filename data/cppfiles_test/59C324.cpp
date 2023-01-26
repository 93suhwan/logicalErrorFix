#include <bits/stdc++.h>
using namespace std;
map<int, set<int>> day;
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    day.clear();
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0, k; j < 5; j++) {
        cin >> k;
        if (k == 1) day[j].insert(i);
      }
    int pos = 0;
    for (int i = 0; i < 5; i++)
      for (int j = i + 1; j < 5; j++) {
        int l = 1;
        int c1 = 0, c2 = 0, c3 = 0;
        for (int s = 0; s < n; s++) {
          if (day[i].find(s) == day[i].end() && day[j].find(s) != day[j].end())
            c1++;
          else if (day[i].find(s) != day[i].end() &&
                   day[j].find(s) == day[j].end())
            c2++;
          else if (day[i].find(s) != day[i].end() &&
                   day[j].find(s) != day[j].end())
            c3++;
          else
            l = 0;
        }
        if (!l) continue;
        if (c1 < n / 2) c3 -= n / 2 - c1;
        if (c2 < n / 2) c3 -= n / 2 - c2;
        if (c3 >= 0) {
          pos = 1;
          break;
        }
      }
    cout << (pos ? "YES\n" : "NO\n");
  }
}
