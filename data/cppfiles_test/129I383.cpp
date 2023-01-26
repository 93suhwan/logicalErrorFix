#include <bits/stdc++.h>
using namespace std;
void usefile() {}
int main() {
  usefile();
  int cas;
  cin >> cas;
  while (cas--) {
    int n;
    cin >> n;
    int arr[n];
    int mx = 0, cnt = 0, op = 0;
    set<int> st;
    int cnto = 0, cntn = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] <= n) {
        st.insert(arr[i]);
        cnt++;
      } else {
        for (int j = 1; j <= (arr[i] - 1) / 2 && j <= n; j++) {
          st.insert(j);
        }
      }
    }
    if (st.size() == n) {
      cout << n - cnt << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
