#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
vector<int> v1{-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> v2{0, 1, 1, 1, 0, -1, -1, -1};
vector<int> v3{0, 1, 0, -1, 0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    long long maxi = 0;
    int ind;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (maxi < v[i]) {
        ind = i;
      }
      maxi = max(maxi, v[i]);
    }
    long long curmin = maxi;
    long long ans = 0;
    int l = ind - 1, r = ind + 1;
    while (l >= 0) {
      curmin = min(curmin, v[l]);
      ans = max(ans, maxi * curmin);
      l--;
    }
    curmin = maxi;
    while (r < n) {
      curmin = min(curmin, v[r]);
      ans = max(ans, maxi * curmin);
      r++;
    }
    cout << ans << endl;
  }
  return 0;
}
