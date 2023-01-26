#include <bits/stdc++.h>
using namespace std;
void usefile() {}
int main() {
  usefile();
  int cas;
  cin >> cas;
  while (cas--) {
    int n;
    cin >> n;
    int arr[n];
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == (i + 1)) {
        cnt++;
      } else if ((arr[i]) / 2 < (i + 1)) {
        ok = false;
      }
    }
    if (ok) {
      cout << n - cnt << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
