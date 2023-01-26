#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string first;
    string second;
    cin >> first >> second;
    int ans = 0;
    for (int i = 0; i < first.size(); i++) {
      if (first[i] == '1' && second[i] == '1') {
        while (i < first.size() && (first[i] == '1' && second[i] == '1')) {
          i++;
        }
        if (!(i == first.size())) {
          ans = ans + 2;
        }
      } else {
        if (first[i] == '0' && second[i] == '0') {
          if (i + 1 < first.size() && first[i + 1] == '1' &&
              second[i + 1] == '1') {
            ans = ans + 2;
            i++;
          } else
            ans = ans + 1;
        } else {
          ans = ans + 2;
        }
      }
    }
    cout << ans << endl;
  }
}
