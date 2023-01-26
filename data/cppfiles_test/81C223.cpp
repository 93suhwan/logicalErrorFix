#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    string s;
    cin >> s;
    int odd[n], even[n];
    fill(odd, odd + n, 0);
    fill(even, even + n, 0);
    for (int i = 0; i < n; i++) {
      if (i % 2 && s[i] == '+') {
        even[i]--;
        odd[i]++;
      } else if (i % 2 || s[i] == '+') {
        even[i]++;
        odd[i]--;
      } else {
        even[i]--;
        odd[i]++;
      }
      if (i) {
        odd[i] += odd[i - 1];
        even[i] += even[i - 1];
      }
    }
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      --l;
      --r;
      int cur = 0;
      if (!l)
        cur = even[r];
      else if (l % 2)
        cur = odd[r] - odd[l - 1];
      else
        cur = even[r] - even[l - 1];
      if (!cur)
        cout << 0 << endl;
      else if (cur % 2)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
  return 0;
}
