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
    vector<int> arr(n);
    string str;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cin >> str;
    multiset<int> red;
    multiset<int> blue;
    for (int i = 0; i < n; i++) {
      if (str[i] == 'R') {
        red.insert(arr[i]);
      } else {
        blue.insert(arr[i]);
      }
    }
    bool flag = true;
    int start = 1;
    while (start <= n) {
      int blueAvail = -1e9;
      int redAvail = -1e9;
      if (blue.size() != 0) {
        auto bElement = blue.lower_bound(start);
        if (bElement != blue.end()) {
          blueAvail = *bElement;
        }
      }
      if (red.size() != 0 && *red.begin() <= start) {
        redAvail = *red.begin();
      }
      if (redAvail != -1e9 && blueAvail != -1e9) {
        blue.erase(blue.find(blueAvail));
      } else if (redAvail != -1e9) {
        red.erase(red.find(redAvail));
      } else if (blueAvail != -1e9) {
        blue.erase(blue.find(blueAvail));
      } else {
        flag = false;
        break;
      }
      start++;
    }
    if (!flag) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }
}
