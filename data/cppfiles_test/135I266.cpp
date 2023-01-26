#include <bits/stdc++.h>
using namespace std;
int better(vector<int> &v, int pos, int sum, int k) {
  int index = v.size() - 1 - pos;
  int ans = sum;
  while (pos > 0) {
    ans -= v[pos - 1];
    ans -= v[v.size() - pos];
    pos--;
    k--;
  }
  for (int i = 0; i < k; i++) {
    ans -= (v[index] + v[index - 1]);
    ans += (v[index - 1] / v[index]);
    index -= 2;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> v(n);
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] == 1) cnt1++;
      sum += v[i];
    }
    sort(v.begin(), v.end());
    int pos = min(cnt1, n - cnt1);
    int ans = sum;
    int index = n - 1, flag = 0;
    for (int i = 0; i < k; i++) {
      ans -= (v[index] + v[index - 1]);
      ans += (v[index - 1] / v[index]);
      index -= 2;
    }
    int u = better(v, pos, sum, k);
    if (u >= 0)
      cout << min(u, ans) << endl;
    else
      cout << ans << endl;
  }
}
