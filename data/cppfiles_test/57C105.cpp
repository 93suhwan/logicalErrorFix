#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
int t, n, a[2100];
vector<int> ans;
void rev(int x) {
  reverse(a + 1, a + x + 1);
  ans.push_back(x);
}
bool check() {
  int ret = 0;
  vector<int> tmp;
  for (int i = 0; i < ans.size(); i++) {
    if (i != ans.size() - 1 and ans[i] == ans[i + 1]) {
      i++;
      ret = 1;
    } else {
      tmp.push_back(ans[i]);
    }
  }
  swap(ans, tmp);
  return ret;
}
int main() {
  cin >> t;
  while (t--) {
    bool imp = 0;
    cin >> n;
    ans.clear();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] % 2 != i % 2) imp = 1;
    }
    if (imp) {
      cout << "-1\n";
      continue;
    }
    for (int i = n; i >= 3; i -= 2) {
      int pos = 0, pos2 = 0;
      for (int j = 1; j <= n; j++) {
        if (a[j] == i) pos = j;
      }
      for (int j = 1; j <= n; j++) {
        if (a[j] == i - 1) pos2 = j;
      }
      int pos3 = 0;
      for (int j = 1; j <= n; j++) {
        if (a[j] == i) pos3 = j;
      }
      rev(pos3);
      int pos4 = 0;
      for (int j = 1; j <= n; j++) {
        if (a[j] == i - 1) pos4 = j;
      }
      rev(pos4 - 1);
      rev(pos4 + 1);
      rev(3);
      rev(i);
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] != i) {
        imp = 1;
        break;
      }
    }
    if (imp)
      cout << "-1\n";
    else {
      while (check()) {
      }
      if (ans.size() > (5 * n) / 2)
        cout << "-1\n";
      else {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
          cout << ans[i] << " \n"[i == ans.size() - 1];
      }
    }
  }
}
