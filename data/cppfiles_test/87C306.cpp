#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long int n, k, a, x, m, i, j, mx = 0, cnt = 0, ans = 0, mn = INT_MAX;
    string s, out = "NO";
    cin >> m >> n;
    multiset<long long int> st;
    multiset<long long int>::iterator mst;
    for (i = 1; i <= n; i++) {
      cin >> x;
      st.insert(x);
      mst = st.lower_bound(x);
      ans += distance(st.begin(), mst);
    }
    cout << ans;
    printf("\n");
  }
  return 0;
}
