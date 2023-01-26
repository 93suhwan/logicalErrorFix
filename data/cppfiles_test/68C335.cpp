#include <bits/stdc++.h>
using namespace std;
bool check(int ind, string t, string s) {
  int p = s.size() - 1;
  int ct = 1;
  for (int i = 1; i < t.size(); i++) {
    if (ind < p && s[ind + 1] == t[i]) ind += 1;
    if (ind > 0 && s[ind - 1] == t[i])
      ind = ind - 1;
    else
      return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ct = 1;
    int i = 0;
    while (i <= n) {
      i++;
      ct = i * i;
      if (ct == n) {
        i--;
        break;
      } else if (ct > n) {
        i--;
        break;
      }
    }
    ct = i * i;
    int a = 1;
    int b = i + 1;
    for (int j = ct + 1; j <= (i + 1) * (i + 1); j++) {
      if (j == n) {
        cout << a << " " << b << endl;
        break;
      } else {
        if (a >= (i + 1)) b--;
        if (a < i + 1) a++;
      }
    }
  }
}
