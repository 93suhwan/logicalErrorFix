#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    long long l, r, k;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ct = 1;
    bool flag = true;
    if (arr[0] == 1) ct++;
    for (int i = 1; i < n; i++) {
      if (arr[i - 1] == 1 && arr[i] == 1) ct += 5;
      if (arr[i] == 0 && arr[i - 1] == 0) flag = false;
      if (arr[i - 1] == 0 && arr[i] == 1) ct++;
    }
    if (flag)
      cout << ct << '\n';
    else
      cout << -1 << "\n";
  }
  return 0;
}
