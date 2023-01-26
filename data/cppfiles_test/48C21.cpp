#include <bits/stdc++.h>
using namespace std;
int n, arr[500005], brr[500005], cnt[500005], pos[500005];
void reset() {
  for (int i = 0; i < n; i++) cnt[arr[i]] = 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    bool flag = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      brr[i] = arr[i];
      pos[arr[i]] = i;
      if (cnt[arr[i]]) flag = 1;
      cnt[arr[i]] = 1;
    }
    if (flag)
      cout << "YES" << endl;
    else {
      sort(brr, brr + n);
      int swapp = 0;
      for (int i = 0; i < n; i++) {
        if (arr[i] != brr[i]) {
          int idx = pos[brr[i]];
          pos[brr[i]] = i;
          pos[arr[i]] = idx;
          swap(arr[i], arr[idx]);
          swapp++;
        }
      }
      if (swapp % 2)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
    reset();
  }
  return 0;
}
