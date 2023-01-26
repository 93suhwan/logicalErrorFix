#include <bits/stdc++.h>
using namespace std;
class type {
 public:
  int a, b, c, d, e, f;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n][5], fg = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> arr[i][j];
    }
    if (n == 1) fg = 1;
    stack<type> st;
    for (int i = 0; i < n; i++) {
      type var;
      var.a = arr[i][0];
      var.b = arr[i][1];
      var.c = arr[i][2];
      var.d = arr[i][3];
      var.e = arr[i][4];
      var.f = i;
      st.push(var);
    }
    while (st.size() > 1) {
      type x = st.top();
      st.pop();
      type y = st.top();
      st.pop();
      int cnt = 0;
      if (x.a < y.a) cnt++;
      if (x.b < y.b) cnt++;
      if (x.c < y.c) cnt++;
      if (x.d < y.d) cnt++;
      if (x.e < y.e) cnt++;
      if (cnt < 3)
        st.push(y);
      else
        st.push(x);
    }
    type var = st.top();
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      if (var.f == i) continue;
      int cnt = 0;
      if (var.a < arr[i][0]) cnt++;
      if (var.b < arr[i][1]) cnt++;
      if (var.c < arr[i][2]) cnt++;
      if (var.d < arr[i][3]) cnt++;
      if (var.e < arr[i][4]) cnt++;
      if (cnt >= 3) {
        maxi++;
      }
    }
    if (maxi == n - 1) fg = 1;
    if (fg)
      cout << (var.f + 1);
    else
      cout << -1;
    cout << '\n';
  }
  return 0;
}
