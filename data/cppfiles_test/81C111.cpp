#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int a[N], sum[N];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int _;
  for (cin >> _; _--;) {
    int n, q;
    string s;
    cin >> n >> q >> s;
    int id = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (i & 1) {
        if (s[i] == '+')
          a[++id] = -1;
        else
          a[++id] = 1;
      } else {
        if (s[i] == '-')
          a[++id] = -1;
        else
          a[++id] = 1;
      }
      sum[id] = sum[id - 1] + a[id];
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      if (abs(sum[r] - sum[l - 1]) == 0)
        cout << "0\n";
      else if (abs(sum[r] - sum[l - 1]) & 1)
        cout << "1\n";
      else
        cout << "2\n";
    }
  }
}
