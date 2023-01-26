#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      if (c == '+') {
        if (i % 2)
          sum[i] = sum[i - 1] + 1;
        else
          sum[i] = sum[i - 1] - 1;
      } else {
        if (i % 2)
          sum[i] = sum[i - 1] - 1;
        else
          sum[i] = sum[i - 1] + 1;
      }
    }
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      int temp = sum[r] - sum[l - 1];
      if (temp == 0)
        cout << 0 << endl;
      else if ((r - l + 1) % 2)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
