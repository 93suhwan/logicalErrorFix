#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  int n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    vector<int> blue, red;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      if (c == 'R')
        red.push_back(a[i]);
      else
        blue.push_back(a[i]);
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    bool check = true;
    int pos = 1;
    for (int i = 0; i < (int)blue.size(); i++) {
      if (blue[i] <= 0 || blue[i] < pos) {
        check = false;
        break;
      }
      pos++;
    }
    if (check) {
      for (int i = 0; i < (int)red.size(); i++) {
        if (red[i] > n || red[i] > pos) {
          check = false;
          break;
        }
        pos++;
      }
    }
    if (check)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
