#include <bits/stdc++.h>
using namespace std;
void compute(vector<int> v, vector<int> temp, int index, float &ans, int sum,
             int len, int total) {
  if (index == v.size()) {
    int n = v.size();
    if (len > 0 && len < n) {
      float avg1 = (float)sum / len;
      float avg2 = (float)(total - sum) / (n - len);
      ans = max(ans, avg1 + avg2);
    }
    return;
  }
  compute(v, temp, index + 1, ans, sum, len, total);
  compute(v, temp, index + 1, ans, sum + v[index], len + 1, total);
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    int total = 0;
    for (int i = 0; i < n; i++) total += v[i];
    float ans = INT_MIN;
    compute(v, {}, 0, ans, 0, 0, total);
    cout << ans << "\n";
  }
  return 0;
}
