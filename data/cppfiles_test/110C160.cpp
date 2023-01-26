#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1067, M = 1e5 + 1067;
int t, n;
int cnt[N];
vector<int> to[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  for (int test = 1; test <= t; test++) {
    cin >> n;
    for (int i = 1; i <= n; i++) to[i].clear();
    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      for (int j = 1; j <= k; j++) {
        int x;
        cin >> x;
        to[x].push_back(i);
      }
      cnt[i] = k;
    }
    set<int> listAvail;
    for (int i = 1; i <= n; i++)
      if (!cnt[i]) {
        listAvail.insert(i);
      }
    int dem = 0;
    int res = 0;
    while (!listAvail.empty()) {
      set<int> newList;
      res += 1;
      while (!listAvail.empty()) {
        int i = *listAvail.begin();
        dem += 1;
        for (auto j : to[i]) {
          --cnt[j];
          if (!cnt[j]) {
            if (j > i)
              listAvail.insert(j);
            else
              newList.insert(j);
          }
        }
        listAvail.erase(i);
      }
      listAvail = newList;
    }
    if (dem < n)
      cout << -1 << endl;
    else
      cout << res << endl;
  }
}
