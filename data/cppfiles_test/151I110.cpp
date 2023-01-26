#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve() {
  map<int, vector<int> > pos;
  int arr[500005];
  int q, cnt1 = 0;
  cin >> q;
  while (q--) {
    int a, x, y;
    cin >> a;
    if (a == 1) {
      cin >> x;
      pos[x].push_back(cnt1);
      arr[cnt1] = x;
      cnt1++;
    } else {
      cin >> x >> y;
      if (x != y) {
        if (pos[x].size() < pos[y].size()) {
          cout << "ok"
               << " ";
          swap(pos[x], pos[y]);
        }
        for (int i = 0; i < pos[x].size(); i++) {
          pos[y].push_back(pos[x][i]);
          arr[pos[x][i]] = y;
        }
        pos[x].clear();
      }
    }
  }
  for (int i = 0; i < cnt1; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, tc;
  t = 1, tc = 0;
  while (t--) {
    solve();
  }
}
