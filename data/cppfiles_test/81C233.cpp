#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pre(n, 0);
    int sum = 0, p = 1, i;
    for (i = 0; i < n; i++) {
      if (s[i] == '+')
        sum += p;
      else
        sum -= p;
      pre[i] = sum;
      p = p * (-1);
    }
    int l, r;
    for (i = 0; i < q; i++) {
      cin >> l >> r;
      l--;
      r--;
      if (l == 0)
        sum = pre[r];
      else
        sum = pre[r] - pre[l - 1];
      if (sum == 0)
        cout << "0\n";
      else if ((r - l + 1) % 2)
        cout << "1\n";
      else
        cout << "2\n";
    }
  }
  return 0;
}
