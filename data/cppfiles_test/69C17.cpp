#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  long long int a[63];
  long long int k1 = 1;
  for (int i = 0; i < 63; i++) {
    a[i] = k1;
    k1 = k1 * 2;
  }
  t = 1;
  cin >> t;
  while (t--) {
    long long int n = 0, c1 = 0, i = 0, sum = 0, k1 = 0, j = 0, k2 = 0,
                  ans = 100000000000, k = 0;
    string s = "";
    cin >> n;
    string s1, s2;
    s1 = to_string(n);
    for (int i = 0; i < 63; i++) {
      s2 = to_string(a[i]);
      k1 = s2.size();
      k2 = s1.size();
      c1 = 0;
      j = 0;
      for (k = 0; k < s1.size(); k++) {
        if (s1[k] != s2[j]) {
          c1++;
        } else {
          j++;
        }
      }
      c1 += k1 - j;
      ans = min(ans, c1);
    }
    cout << ans;
    cout << '\n';
  }
}
