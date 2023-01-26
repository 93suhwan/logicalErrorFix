#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  int t1 = t;
  while (t1--) {
    int n, m;
    cin >> n;
    cin >> m;
    int sum = 0;
    int arr[m];
    for (int i = 0; i < m; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) {
      int cur = 0;
      for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i]) cur++;
      }
      sum += cur;
    }
    cout << sum << endl;
  }
  return 0;
}
