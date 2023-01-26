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
    set<int> st;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int count[n + 1], tot = 0;
    for (int i = 1; i <= n; i++) {
      count[i] = 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (st.count(arr[i]) == 0 && arr[i] <= n) {
        count[arr[i]]++;
        st.insert(arr[i]);
        cnt++;
      } else {
        int mx = (arr[i] - 1) / 2;
        if (mx >= n) {
          mx = n;
        }
        count[mx]++;
      }
    }
    for (int i = 1; i <= n; i++) {
      tot += count[i];
      if (tot > i) {
        ok = false;
      }
    }
    if (tot == n && ok) {
      cout << n - cnt << endl;
    } else {
      cout << -1 << endl;
    }
    st.clear();
  }
  return 0;
}
