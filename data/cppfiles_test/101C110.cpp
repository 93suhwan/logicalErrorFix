#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    string str;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cin >> str;
    multiset<long long int> red;
    multiset<long long int> blue;
    for (long long int i = 0; i < n; i++) {
      if (str[i] == 'R') {
        red.insert(arr[i]);
      } else {
        blue.insert(arr[i]);
      }
    }
    bool flag = true;
    long long int start = 1;
    while (start <= n) {
      long long int blueAvail = -1e12;
      long long int redAvail = -1e12;
      if (blue.size() != 0) {
        auto bElement = blue.lower_bound(start);
        if (bElement != blue.end()) {
          blueAvail = *bElement;
        }
      }
      if (red.size() != 0 && *red.begin() <= start) {
        redAvail = *red.begin();
      }
      if (redAvail != -1e12 && blueAvail != -1e12) {
        blue.erase(blue.find(blueAvail));
      } else if (redAvail != -1e12) {
        red.erase(red.find(redAvail));
      } else if (blueAvail != -1e12) {
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
