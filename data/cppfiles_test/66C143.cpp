#include <bits/stdc++.h>
using namespace std;
int fr[4];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int arr[1000];
  int x = 1;
  for (int i = 0; i < 1000; i++) {
    if (x <= 9) {
      if (x % 3 != 0)
        arr[i] = x;
      else {
        i--;
      }
    } else {
      int d = x % 10;
      if (d != 3 && x % 3 != 0)
        arr[i] = x;
      else
        i--;
    }
    x++;
  }
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    cout << arr[n - 1] << '\n';
  }
}
