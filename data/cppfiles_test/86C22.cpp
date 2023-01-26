#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a1;
    string a2;
    cin >> a1;
    cin >> a2;
    int sum = 0;
    int check = 2;
    for (int i = 0; i < n; i++) {
      if ((a1[i] == '0' && a2[i] == '1') || (a2[i] == '0' && a1[i] == '1')) {
        sum += 2;
        check = 2;
      } else if ((a1[i] == '0' && a2[i] == '0')) {
        if (check == 1) {
          sum += 2;
          check = 3;
        } else {
          sum++;
          check = 0;
        }
      } else if (a1[i] == '1' && a2[i] == '1') {
        if (check == 0) {
          sum++;
          check = 3;
        } else
          check = 1;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
