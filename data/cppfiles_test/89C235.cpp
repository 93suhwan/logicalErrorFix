#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, i;
    cin >> n;
    vector<long long> arr;
    int rem = n;
    int buffer = 0;
    for (i = 0; i < n; i++) {
      long long num;
      cin >> num;
      arr.push_back(num);
    }
    bool flag = true;
    for (i = 0; i < n; i++) {
      if (arr[i] < i + 2) continue;
      bool found = false;
      for (int j = i + 2; j >= 2; j--)
        if (arr[i] % j != 0) {
          found = true;
          break;
        }
      if (found)
        continue;
      else {
        flag = false;
        break;
      };
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
