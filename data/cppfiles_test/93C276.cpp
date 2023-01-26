#include <bits/stdc++.h>
using namespace std;
int t, a, b, ans, tmp;
int arr[300003];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  arr[0] = 0;
  for (int i = 1; i <= 300000; i++) {
    arr[i] = arr[i - 1] ^ i;
  }
  cin >> t;
  while (t--) {
    tmp = 0;
    cin >> a >> b;
    ans = a;
    tmp = arr[a - 1];
    if (tmp == b) {
    } else {
      if ((tmp ^ b) == a)
        ans += 2;
      else
        ans += 1;
    }
    cout << ans << endl;
  }
}
