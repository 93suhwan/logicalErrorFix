#include <bits/stdc++.h>
using namespace std;
int n;
int a[200000];
string h;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  cin >> h;
  reverse(h.begin(), h.end());
  bool flip = (h[0] == 'R');
  if (flip) {
    for (int i = 0; i < n; i++) {
      h[i] = (h[i] == 'L' ? 'R' : 'L');
    }
  }
  int i = 0, j = n - 1;
  vector<pair<int, char>> ans;
  for (int k = 1; k < n; k++) {
    char c = h[k];
    if (c == 'L') {
      if (i % 2)
        ans.push_back({a[i], 'R'}), i++;
      else
        ans.push_back({a[j], (j % 2 ? 'R' : 'L')}), j--;
    } else {
      if (!(i % 2))
        ans.push_back({a[i], 'L'}), i++;
      else
        ans.push_back({a[j], (j % 2 ? 'R' : 'L')}), j--;
    }
  }
  assert(i == j);
  ans.push_back({a[i], (i % 2 == 0 ? 'L' : 'R')});
  reverse(ans.begin(), ans.end());
  for (auto p : ans) {
    cout << p.first << " ";
    if (flip)
      cout << (p.second == 'L' ? 'R' : 'L');
    else
      cout << p.second;
    cout << '\n';
  }
}
