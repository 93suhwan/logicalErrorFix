#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i = 0, ve, ans, a = 0, b = -1;
    cin >> n;
    vector<long long int> vec;
    for (; i < n; i++) {
      cin >> ve;
      if (a < ve) {
        a = ve;
        b = i;
      }
      vec.push_back(ve);
    }
    ans = vec[0];
    for (int i = 0; i < n; i++) {
      ans = ans & vec[i];
    }
    cout << ans << "\n";
  }
  return 0;
}
