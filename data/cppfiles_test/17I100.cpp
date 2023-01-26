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
    set<long long int> set, set2;
    for (int i = 0; i < n; i++) set.insert(i);
    long long int ans = -1;
    while (set.size() > 1) {
      int curr = *set.begin();
      set.erase(set.begin());
      set2 = set;
      for (auto itr = set.begin(); itr != set.end(); itr++) {
        int first = 0;
        for (int j = 0; j < 5; j++) {
          if (arr[curr][j] < arr[*itr][j]) first++;
        }
        if (first >= 3) set2.erase(*itr);
      }
      if (set2.size() == 0) {
        ans = curr;
        break;
      } else {
        set = set2;
      }
    }
    if (set.size() == 1) ans = *set.begin();
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
