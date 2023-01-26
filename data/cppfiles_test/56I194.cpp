#include <bits/stdc++.h>
using namespace std;
long long int a[500005], b[500005], c[500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, i, j, k, w, y, z, n, m, x, l, r;
  cin >> t;
  while (t--) {
    string s;
    i = 1;
    j = 2, x = 1;
    cout << 1 << " " << 1 << endl;
    cin >> s;
    if (s == "Done") continue;
    while (1) {
      cout << i << " " << j << endl;
      x++;
      cin >> s;
      if (x >= 128) break;
      if (s == "Left" || s == "Down-Left" || s == "Up-Left") {
        if (j == 2)
          j = 1;
        else
          j = 2;
      } else if (s == "Right" || s == "Down-Right" || s == "Up-Right" ||
                 j >= 7) {
        i++;
        cout << i << " " << j << endl;
        cin >> s;
        x++;
        if (s == "Done") break;
        if (j == 2)
          j += 2;
        else
          j = 2;
      } else if (s == "Done")
        break;
      else
        j += 2;
    }
  }
}
