#include <bits/stdc++.h>
using namespace std;
void Ashfaque() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
}
int isAvailable[1000000 + 10];
int main() {
  Ashfaque();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 2];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      isAvailable[arr[i]] = 1;
    }
    int pairs = n / 2, count = 0;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (count == pairs) {
          ok = true;
          break;
        } else if (arr[i] == arr[j])
          continue;
        else {
          int num = arr[j] % arr[i];
          if (isAvailable[num] == 0) {
            count++;
            cout << arr[j] << " " << arr[i] << endl;
          }
        }
      }
      if (ok) break;
    }
  }
  return 0;
}
