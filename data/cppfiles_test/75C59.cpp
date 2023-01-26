#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i - 1])
        cnt1++;
      else
        break;
    }
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > a[i + 1])
        cnt2++;
      else
        break;
    }
    if ((cnt1 & 1) && (cnt2 & 1))
      cout << "Bob";
    else
      cout << "Alice";
  }
  return 0;
}
