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
          for (int l = 0; l < 7; l++) {
            if (arr[l] != arr[i] && arr[l] != arr[j] && arr[l] != arr[k] &&
                arr[l] != arr[i] + arr[j] && arr[l] != arr[j] + arr[k] &&
                arr[l] != arr[i] + arr[k] &&
                arr[l] != arr[i] + arr[j] + arr[k]) {
              is = false;
            }
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
