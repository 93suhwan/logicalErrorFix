#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    int changes = 0;
    for (int a = 1; a <= n; a++) {
      if (arr[a] > a + changes) {
        changes += arr[a] - a - changes;
      }
    }
    cout << changes << "\n";
  }
}
