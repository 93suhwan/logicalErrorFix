#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n;
int a[N];
map<int, bool> mp;
vector<int> need;
vector<int> have;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    mp.clear();
    need.clear(), have.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] > n) {
        have.push_back(a[i]);
      }
      if (mp[a[i]] == false)
        mp[a[i]] = true;
      else
        have.push_back(a[i]);
    }
    sort(have.begin(), have.end());
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
      if (mp[i] == false) need.push_back(i);
    bool succ = true;
    for (int i = 0; i < have.size(); i++)
      if (need[i] * 2 >= have[i]) succ = false;
    if (succ)
      cout << need.size() << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
