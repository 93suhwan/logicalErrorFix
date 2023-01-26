#include <bits/stdc++.h>
using namespace std;
struct st {
  int l = 1;
  int r = 0;
  int d = 0;
};
int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; ++z) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> help_a(n);
    vector<st> ans;
    for (int i = 0; i < n - 1; ++i) {
      int maxId = 0;
      for (int j = 0; j < n - i; ++j) {
        if (a[maxId] < a[j]) maxId = j;
      }
      int d = maxId + 1;
      for (int j = 0; j < n - i; ++j) {
        if (j - d >= 0)
          help_a[j - d] = a[j];
        else {
          help_a[n + j - i - d] = a[j];
        }
      }
      a = help_a;
      st tmp;
      tmp.r = n - i;
      tmp.d = d;
      if (n - i - 1 >= d) ans.push_back(tmp);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
      cout << ans[i].l << " " << ans[i].r << " " << ans[i].d << endl;
  }
  return 0;
}
