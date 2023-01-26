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
    vector<long long int> d;
    for (long long int i = 0; i < a.size(); i++) {
      if (a[i] == b[0]) d.push_back(i);
    }
    long long int k;
    long long int f = 1;
    for (long long int k = 0; k < d.size(); k++) {
      long long int i = d[k];
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
      if (f == 1)
        break;
      else if (k != d.size() - 1)
        f = 1;
    }
    if (f == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
