#include <bits/stdc++.h>
using namespace std;
void arraychk(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
  ;
}
vector<int> ed[2 * 100005];
int a[2 * 100005], now = 1, done;
set<int> current[2 * 100005];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int tt = 1;
  cin >> tt;
  for (int cse = 1; cse <= tt; cse++) {
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, x = 0, y = 0, ans = 1,
        sum = 0;
    done = 0;
    cin >> n;
    current[0].clear();
    for (int i = 0; i < n + 1; i++) ed[i].clear();
    for (int i = 1; i < n + 1; i++) {
      current[i].clear();
      cin >> a[i];
      m = a[i];
      if (m == 0) done++, current[0].insert(i);
      while (m--) {
        cin >> x;
        ed[x].push_back(i);
      }
    }
    bool flag = (!current[0].empty());
    x = 0;
    while (flag && done < n) {
      if (done != n && current[x].empty()) flag = 0;
      for (auto xx : current[x]) {
        for (auto yy : ed[xx]) {
          a[yy]--;
          if (a[yy] == 0) {
            done++;
            if (yy > xx)
              current[x].insert(yy);
            else
              current[x + 1].insert(yy);
          }
        }
      }
      if (done == n) {
        if (!current[x + 1].empty()) x++;
        break;
      }
      ++x;
    }
    cout << ((flag) ? x + 1 : -1) << endl;
  }
  return 0;
}
