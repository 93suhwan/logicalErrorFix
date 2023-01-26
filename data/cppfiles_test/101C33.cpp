#include <bits/stdc++.h>
using namespace std;
int t;
int n;
bool cmp(pair<int, int> x, pair<int, int> y) {
  if (x.second == y.second && x.second == 0)
    return x.first < y.first;
  else if (x.second == y.second && x.second == 1)
    return x.first > y.first;
  else
    return x.second < y.second;
}
pair<int, int> a[200005];
int main() {
  cin >> t;
  while (t--) {
    bool check = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) {
      char x;
      cin >> x;
      if (x == 'B')
        a[i].second = 0;
      else
        a[i].second = 1;
    }
    sort(a + 1, a + 1 + n, cmp);
    int l = 1;
    int r = n;
    for (int i = 1; i <= n; i++) {
      if (a[i].second == 0) {
        if (a[i].first < l) check = 1;
        l++;
      }
      if (a[i].second == 1) {
        if (a[i].first > r) check = 1;
        r--;
      }
    }
    if (check == 1)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
  return 0;
}
