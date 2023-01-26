#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  fast();
  int t;
  cin >> t;
  int sum = 0;
  while (t--) {
    int arr[8];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    sum = arr[0] + arr[1];
    int d = 0;
    for (int i = 2; i < 7; i++) {
      if (sum + arr[i] == arr[6]) {
        d = arr[i];
        break;
      }
    }
    cout << arr[0] << " " << arr[1] << " " << d << endl;
  }
  return 0;
}
