#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    vector<char> num;
    int cnt[4] = {0, 0, 0, 0};
    bool flag = false;
    for (int i = 0; i < k; i++) {
      char x;
      cin >> x;
      num.push_back(x);
      if (x == '1' || x == '4' || x == '6' || x == '8' || x == '9') {
        cout << 1 << '\n' << x - '0' << '\n';
        flag = true;
        break;
      } else {
        switch (x) {
          case '2':
            cnt[0]++;
            break;
          case '3':
            cnt[1]++;
            break;
          case '5':
            cnt[2]++;
            break;
          case '7':
            cnt[3]++;
            break;
        }
      }
    }
    if (flag == true) continue;
    if (cnt[0] >= 2) {
      cout << 2 << '\n' << 22 << '\n';
      continue;
    }
    if (cnt[1] >= 2) {
      cout << 2 << '\n' << 33 << '\n';
      continue;
    }
    if (cnt[2] >= 2) {
      cout << 2 << '\n' << 55 << '\n';
      continue;
    }
    if (cnt[3] >= 2) {
      cout << 2 << '\n' << 77 << '\n';
      continue;
    }
    if (cnt[2] && num[0] != '5') {
      cout << 2 << '\n' << num[0] - '0' << 5 << '\n';
      continue;
    }
    if (cnt[2] && cnt[0]) {
      cout << 2 << '\n' << 52 << '\n';
      continue;
    }
    if (cnt[2] && cnt[3]) {
      cout << 2 << '\n' << 57 << '\n';
      continue;
    }
    if (cnt[0] && num[0] != '2') {
      cout << 2 << '\n' << num[0] << 2 << '\n';
      continue;
    }
    cout << 2 << '\n' << 27 << '\n';
  }
}
