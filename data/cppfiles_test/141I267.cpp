#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k, t, k1, k2;
  string s, a, b;
  cin >> t;
  while (t > 0) {
    t--;
    cin >> a >> s;
    b = "";
    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());
    int j = 0;
    bool q = true;
    for (int i = 0; i < a.size(); i++) {
      if (j >= s.size()) {
        q = false;
        break;
      }
      k1 = (a[i] - '0');
      k2 = (s[j] - '0');
      if (k1 <= k2)
        k = k2 - k1;
      else {
        j++;
        if (j >= s.size()) {
          q = false;
          break;
        }
        k2 += ((s[j] - '0') * 10);
        k = k2 - k1;
      }
      j++;
      if (k >= 10) {
        q = false;
        break;
      }
      char w = (k + '0');
      b = w + b;
    }
    while (j < s.size()) {
      b = s[j] + b;
      j++;
    }
    if (q == false || j < s.size()) {
      cout << "-1\n";
    } else {
      q = false;
      for (int i = 0; i < b.size(); i++) {
        if (b[i] != '0') q = true;
        if (q) cout << b[i];
      }
      cout << "\n";
    }
  }
}
