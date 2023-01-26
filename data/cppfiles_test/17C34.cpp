#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> arr[i][j];
    }
    int best = 0;
    for (int i = 1; i < n; i++) {
      int first = 0;
      for (int j = 0; j < 5; j++) {
        if (arr[i][j] > arr[best][j]) first++;
      }
      if (first < 3) best = i;
    }
    int ans = best;
    bool temp = true;
    for (int i = 0; i < n; i++) {
      if (i == ans) continue;
      int first = 0;
      for (int j = 0; j < 5; j++) {
        if (arr[i][j] > arr[ans][j]) first++;
      }
      if (first < 3) {
        temp = false;
        break;
      }
    }
    if (!temp)
      cout << -1 << "\n";
    else
      cout << ans + 1 << "\n";
  }
  return 0;
}
