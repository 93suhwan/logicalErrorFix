#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    long long arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long power = h;
    long long arr1[n - 1];
    for (int i = 0; i < n - 1; i++) {
      arr1[i] = arr[i + 1] - arr[i];
    }
    sort(arr1, arr1 + n - 1);
    long long numberofattacks = n;
    int index = -5;
    for (int i = 0; i < n - 1; i++) {
      if (power % numberofattacks == 0) {
        if (power / numberofattacks <= arr1[i]) {
          index = i;
          break;
        } else {
          power -= arr1[i];
          numberofattacks--;
        }
      } else {
        if (power / numberofattacks < arr1[i]) {
          index = i;
          break;
        } else {
          power -= arr1[i];
          numberofattacks--;
        }
      }
    }
    if (index == -5) {
      cout << power << endl;
    } else {
      if (power % numberofattacks == 0) {
        cout << power / numberofattacks << endl;
      } else {
        cout << power / numberofattacks + 1 << endl;
      }
    }
  }
  return 0;
}
