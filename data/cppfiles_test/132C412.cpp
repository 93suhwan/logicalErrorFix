#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1;
  cin >> tt;
  int T = 1;
outer:
  while (tt--) {
    int arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 7; j++) {
      that:
        for (int k = 0; k < 7; k++) {
          bool is = true;
          map<int, int> mp;
          mp[arr[i]]++;
          mp[arr[j]]++;
          mp[arr[k]]++;
          mp[arr[i] + arr[j]]++;
          mp[arr[i] + arr[k]]++;
          mp[arr[j] + arr[k]]++;
          mp[arr[i] + arr[j] + arr[k]]++;
          for (int l = 0; l < 7; l++) {
            if (mp.find(arr[l]) == mp.end() || mp[arr[l]] == 0)
              is = false;
            else
              mp[arr[l]]--;
          }
          if (is) {
            cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
            goto outer;
          }
        }
      }
    }
  }
}
