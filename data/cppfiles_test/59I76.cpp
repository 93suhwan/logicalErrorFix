#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
int a[1005][5];
void solve() {
  int n;
  cin >> n;
  set<int> st;
  int b[10];
  memset(b, 0, sizeof(b));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) {
        st.insert(j);
        b[j]++;
      }
    }
  if (st.size() <= 1) {
    cout << "NO" << '\n';
    ;
    return;
  }
  sort(b, b + 5);
  if (b[4] + b[3] >= n) {
    cout << "YES" << '\n';
    ;
  } else
    cout << "NO" << '\n';
  ;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
