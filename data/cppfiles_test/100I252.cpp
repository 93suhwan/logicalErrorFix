#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, y;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, mn = 1000000001;
    cin >> n;
    vector<int> v(n);
    if (n == 1) {
      int a;
      cin >> a;
      cout << a << '\n';
    } else {
      for (int j = 0; j < n; j++) {
        cin >> v[j];
        if (v[j] < mn) mn = v[j];
      }
      int x = mn;
      for (int k = 0; k < n - 1; k++) {
        int mnn = 1000000001, cnt = 0;
        for (int j = 0; j < n - k - 1; j++) {
          v[j] -= x;
          if (v[j] == 0 && cnt == 0) {
            v.erase(v.begin() + j);
            j--;
            cnt++;
          } else if (v[j] < mnn)
            mnn = v[j];
        }
        y = max(x, mnn);
        x = mnn;
      }
      cout << y << '\n';
    }
  }
}
