#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC = 1;
  cin >> TC;
  while (TC--) {
    int n;
    cin >> n;
    vector<int> arr(n), red, blue;
    for (int i = 0; i < n; i++) cin >> arr[i];
    char ch;
    for (int i = 0; i < n; i++) {
      cin >> ch;
      if (ch == 'R')
        red.push_back(arr[i]);
      else
        blue.push_back(arr[i]);
    }
    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end());
    bool flag = true;
    int val = 1;
    for (int i = 0; i < blue.size(); i++) {
      if (blue[i] < val) {
        flag = false;
        break;
      }
      val++;
    }
    if (flag) {
      for (int i = 0; i < red.size(); i++) {
        if (red[i] > val) {
          flag = false;
          break;
        }
        val++;
      }
    }
    cout << (flag ? "YES" : "NO");
    if (TC) cout << '\n';
  }
  return 0;
}
