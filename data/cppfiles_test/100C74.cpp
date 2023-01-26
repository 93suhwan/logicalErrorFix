#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ;
}
int main() {
  fastio();
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long int> v1(n), v2;
    priority_queue<long long int> pq;
    for (auto &i : (v1)) cin >> i;
    ;
    sort(v1.begin(), v1.end());
    long long int sum = 0, ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      ans = max(ans, v1[i] - sum);
      sum += (v1[i] - sum);
    }
    cout << ans;
    cout << "\n";
  }
}
