#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    vector<vector<long long>> a(4);
    for (int i = 0; i < 4; i++) {
      int k, temp;
      cin >> k;
      for (int j = 0; j < k; j++) {
        cin >> temp;
        a[i].push_back(temp);
      }
    }
    long long ans = 0;
    ans = max(ans, (a[0].back() - a[0][0]) * h);
    ans = max(ans, (a[1].back() - a[1][0]) * h);
    ans = max(ans, (a[2].back() - a[2][0]) * w);
    ans = max(ans, (a[3].back() - a[3][0]) * w);
    cout << ans << "\n";
  }
}
