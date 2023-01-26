#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long maxe = arr[0];
    long long maxadj = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] > maxe) maxe = arr[i];
    }
    for (int i = 0; i < n; i++) {
      if (arr[i] == maxe) {
        if (i == 0) {
          maxadj = arr[i + 1];
        } else if (i == n - 1) {
          maxadj = arr[i - 1];
        } else {
          maxadj = max(arr[i - 1], arr[i + 1]);
        }
        break;
      }
    }
    cout << maxe * maxadj << endl;
  }
}
