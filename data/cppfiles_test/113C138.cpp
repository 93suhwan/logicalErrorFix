#include <bits/stdc++.h>
using namespace std;
long long n;
signed main() {
  cin >> n;
  while (n--) {
    bool use = 0;
    string a, b;
    long long na, nb;
    cin >> a >> na >> b >> nb;
    if (a.length() + na > b.length() + nb)
      cout << ">\n";
    else if (a.length() + na < b.length() + nb)
      cout << "<\n";
    else {
      for (long long i = 0; i < 100006; i++) {
        char cmpa = '0', cmpb = '0';
        if (i > a.length() && i > b.length()) break;
        if (i < a.length()) cmpa = a[i];
        if (i < b.length()) cmpb = b[i];
        if (cmpb == cmpa) continue;
        if (cmpa > cmpb) {
          use = 1;
          cout << ">\n";
          break;
        }
        if (cmpa < cmpb) {
          use = 1;
          cout << "<\n";
          break;
        }
      }
      if (!use) cout << "=\n";
    }
  }
}
