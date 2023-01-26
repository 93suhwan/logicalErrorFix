#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<int> arr(n + 3);
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt++;
      if (arr[i] % 2 == 0) {
        break;
      }
    }
    int i = 0;
    cnt++;
    while (cnt > 0 && i <= n) {
      i++;
      cnt = min(cnt, arr[i] + 1);
      if (arr[i] % (i + 1) != 0) {
        cnt++;
        continue;
      }
      while (cnt > 0 && arr[i] % cnt == 0) {
        cnt--;
      }
    }
    if (i > n) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
