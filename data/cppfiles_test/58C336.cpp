#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int col, test;
  cin >> test;
  while (test--) {
    int col;
    cin >> col;
    string first;
    string second;
    cin >> first >> second;
    string res = "YES";
    for (int i = 0; i < col; i++) {
      if (first[i] == '1' && second[i] == '1') {
        res = "NO";
        break;
      }
    }
    cout << res << endl;
  }
}
