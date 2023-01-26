#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int t, n;
int arr[N];
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    for (int i = 2; i <= n + 1; i++) cout << i << " ";
    cout << endl;
  }
  return 0;
}
