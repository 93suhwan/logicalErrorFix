#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    long long int i = 0;
    while (a[i] != b[0]) i++;
    long long int f = 1;
    long long int r = 1, l = 0;
    for (long long int j = 1; j < b.size(); j++) {
      if (r == 1) {
        if (i + 1 < a.size() && a[i + 1] == b[j])
          i++;
        else if (i < a.size() && a[i - 1] == b[j]) {
          r = 0;
          l = 1;
          i--;
        } else {
          f = 0;
          break;
        }
      } else {
        if (r == 0) {
          if (i - 1 >= 0 && a[i - 1] == b[j])
            i--;
          else {
            f = 0;
            break;
          }
        }
      }
    }
    if (f == 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
