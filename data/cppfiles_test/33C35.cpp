#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(600);
  for (int i = 1; i < 600; i++) {
    a[i] = INT_MAX;
  }
  a[0] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x] = min(a[x], x);
    for (int j = 0; j < 600; j++) {
      if (a[j] < x) {
        a[j ^ x] = min(a[j ^ x], x);
      }
    }
  }
  vector<int> ans;
  for (int j = 0; j < 600; j++) {
    if (a[j] != INT_MAX) {
      ans.push_back(j);
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
