#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      v.push_back(num);
    }
    int cnt = 1;
    bool flag = false;
    for (int i = 1; i < n; i++) {
      if (v[i] == 0 && v[i - 1] == 0) {
        flag = true;
        break;
      } else if (v[i] == 1 && v[i - 1] == 0) {
        cnt++;
      } else if (v[i] == 1 && v[i - 1] == 1) {
        cnt += 5;
      }
    }
    if (flag) {
      cout << -1 << "\n";
      continue;
    }
    if (v[0] == 1) {
      cnt += 1;
    }
    cout << cnt << "\n";
  }
}
