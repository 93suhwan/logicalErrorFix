#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    for (int i = 0; i < n; i++) {
      if (vec[i] >= 0) {
        v1.push_back(vec[i]);
      } else {
        v2.push_back(vec[i]);
      }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> res;
    if (n1 > 0) {
      int cur1 = n1 - 1;
      res.push_back(v1[cur1]);
      cur1 -= k;
      while (cur1 >= 0) {
        res.push_back(v1[cur1]);
        cur1 -= k;
      }
    }
    if (n2 > 0) {
      int cur2 = n2 - 1;
      res.push_back(-v2[cur2]);
      cur2 -= k;
      while (cur2 >= 0) {
        res.push_back(-v2[cur2]);
        cur2 -= k;
      }
    }
    long long int ans = 0;
    sort(res.begin(), res.end());
    int last = res.size();
    for (int i = 0; i < last - 1; i++) {
      ans += res[i] * 2LL;
    }
    ans += res[last - 1];
    cout << ans << endl;
  }
  return 0;
}
