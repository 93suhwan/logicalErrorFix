#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int d[1000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < 1000; i++) d[i] = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 1000; j++)
      if (d[j] < a[i]) d[j ^ a[i]] = min(d[j ^ a[i]], a[i]);
  }
  vector<int> ans;
  for (int i = 0; i < 1000; i++)
    if (d[i] != 1e9) ans.push_back(i);
  cout << ans.size() << "\n";
  for (int x : ans) cout << x << " ";
}
