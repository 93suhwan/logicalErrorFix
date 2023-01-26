#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int z;
  cin >> z;
  string x, xx, xxx;
  while (z--) {
    int count = 0, arr[55];
    cin >> x >> xx;
    for (int i = 0; i < xx.size(); i++) {
      for (int j = 0; j < x.size(); ++j) {
        if (xx[i] == x[j]) {
          arr[i] = j + 1;
          break;
        }
      }
    }
    for (int i = 0; i < xx.length() - 1; i++) {
      count += abs(arr[i] - arr[i + 1]);
    }
    cout << count << '\n';
  }
  return 0;
}
