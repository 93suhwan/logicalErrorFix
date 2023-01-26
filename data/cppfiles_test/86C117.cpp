#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
      int j = i;
      if (a[i] != b[i])
        cnt += 2;
      else {
        if (a[i] == '0' && i < n && a[i + 1] != b[i + 1])
          cnt += 1;
        else if (a[i] == '0' && i < n && a[i + 1] == b[i + 1] &&
                 a[i + 1] == '1') {
          cnt += 2;
          i++;
        } else if (a[i] == '0')
          cnt += 1;
        else if (a[i] == '1' && i < n && a[i + 1] == '0' &&
                 a[i + 1] == b[i + 1]) {
          cnt += 2;
          i++;
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
