#include <bits/stdc++.h>
using namespace std;
int t;
int arr[300005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 1; i < 300000; i++) {
    arr[i + 1] = arr[i] ^ i;
  }
  cin >> t;
  for (int l = 1; l <= t; l++) {
    int a, b;
    cin >> a >> b;
    int ans = a;
    if (arr[a] == b) {
      cout << a << "\n";
    } else if ((arr[a] ^ a) == b) {
      cout << a + 2 << "\n";
    } else {
      cout << a + 1 << "\n";
    }
  }
  return 0;
}
