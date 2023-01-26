#include <bits/stdc++.h>
using namespace std;
void JaiMataDi() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i] == '0') and (b[i] == '1'))
      cnt += 2;
    else if ((a[i] == '1') and (b[i] == '0'))
      cnt += 2;
    else if ((a[i] == '0') and (b[i] == '0')) {
      if (i + 1 < n) {
        if ((a[i + 1] == '1') and (b[i + 1] == '1'))
          cnt += 2, i++;
        else
          cnt += 1;
      } else
        cnt += 1;
    } else if ((a[i] == '1') and (b[i] == '1')) {
      if (i + 1 < n) {
        if ((a[i + 1] == '0') and (b[i + 1] == '0')) cnt += 2, i++;
      }
    }
  }
  cout << cnt << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) JaiMataDi();
}
