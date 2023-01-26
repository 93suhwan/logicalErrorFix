#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t) {
    t -= 1;
    int n, q;
    cin >> n >> q;
    vector<int> sums(n);
    string s;
    cin >> s;
    int sm = 0;
    for (int i = 0; i < n; i += 1) {
      int pl;
      if (s[i] == '+')
        pl = 1;
      else
        pl = -1;
      if (i % 2 == 0)
        sm += pl;
      else
        sm -= pl;
      sums[i] = sm;
    }
    for (int tt = 0; tt < q; tt += 1) {
      int l, r;
      cin >> l >> r;
      l -= 1;
      r -= 1;
      int cs = sums[r];
      if (l != 0) cs -= sums[l - 1];
      if (cs == 0)
        cout << "0\n";
      else {
        if (cs % 2 == 0)
          cout << "2\n";
        else
          cout << "1\n";
      }
    }
  }
}
