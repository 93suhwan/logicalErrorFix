#include <bits/stdc++.h>
using namespace std;
int const mod = 1e9 + 7;
int get_Icount(int arr[], int n) {
  multiset<int> set1;
  set1.insert(arr[0]);
  int invcount = 0;
  multiset<int>::iterator itset1;
  for (int i = 1; i < n; i++) {
    set1.insert(arr[i]);
    itset1 = set1.upper_bound(arr[i]);
    invcount += (int)distance(itset1, set1.end());
  }
  return invcount;
}
void test_case() {
  int n, m;
  cin >> n >> m;
  int p[n + 1];
  for (int i = 1; i <= n; i++) cin >> p[i];
  vector<int> ans(n, 0);
  for (int i = 1; i <= n; i++) {
    int k = i - p[i];
    if (k >= 0)
      ans[abs(k)]++;
    else
      ans[n + k]++;
  }
  int val = n - 2 * m;
  vector<int> tr;
  for (int i = 0; i < n; i++) {
    if (ans[i] >= val) tr.push_back(i);
  }
  cout << tr.size() << " ";
  for (int cc : tr) cout << cc << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) test_case();
}
