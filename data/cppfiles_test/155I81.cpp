#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    int mn = INT_MAX;
    int mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      mx = max(mx, arr[i]);
      mn = min(mn, arr[i]);
    }
    string s;
    cin >> s;
    vector<int> ans(n);
    int tmp = mn;
    int mine, maxi;
    if (s[0] == '1') {
      maxi = arr[0];
    } else {
      mine = arr[0];
    }
    bool flag = true;
    for (int i = 1; i < n; ++i) {
      if (s[i] == '1' && s[i - 1] == '0' && maxi > mine) {
        continue;
      } else if (s[i] == '0' && s[i - 1] == '1' && maxi > mine) {
        continue;
      } else if (s[i] == '1' && s[i - 1] == '1') {
        maxi = arr[i];
      } else if (s[i] == '0' && s[i - 1] == '0') {
        mine = arr[i];
      } else {
        flag = false;
        break;
      }
    }
    if (!flag) {
      for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
          arr[i] = tmp;
          ++tmp;
        }
      }
      for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
          arr[i] = tmp;
          ++tmp;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
