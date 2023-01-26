#include <bits/stdc++.h>
using namespace std;
long long arr[10000];
int main() {
  cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long c = 1;
    for (int i = 1; i < n + 1; ++i) {
      cin >> arr[i];
    }
    for (int i = 1; i < n + 1; ++i) {
      if (arr[i] == 1 && arr[i - 1] == 1)
        c += 5;
      else if (arr[i] == 1 && arr[i - 1] == 0)
        c += 1;
      else if (arr[i] == 0 && arr[i - 1] == 0 && i > 1) {
        c = -1;
        i = 1e9;
      } else
        continue;
    }
    cout << c << endl;
  }
  return 0;
}
