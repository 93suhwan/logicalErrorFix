#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int N = 3e5 + 5, LG = 17, MOD = 998244353;
const long double PI = acos(-1);
void doWork() {
  int n, m;
  cin >> n >> m;
  set<int> st;
  for (int i = 1; i < n + 1; i++) st.insert(i);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    st.erase(b);
  }
  int root = *st.begin();
  for (int i = 1; i < n + 1; i++)
    if (i != root) {
      cout << root << ' ' << i << endl;
    }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    doWork();
  }
  return 0;
}
