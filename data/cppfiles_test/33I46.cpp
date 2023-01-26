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
    long long sol = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] > maxe) {
        maxe = arr[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (arr[i] == maxe) {
        if (i != 0 && i != n - 1 && maxe * max(arr[i + 1], arr[i - 1]) >= sol) {
          sol = maxe * max(arr[i + 1], arr[i - 1]);
          continue;
        }
        if (i == 0 && maxe * arr[i + 1] >= sol) {
          sol = maxe * arr[i + 1];
        }
        if (i == n - 1 && maxe * arr[i - 1] >= sol) {
          sol = maxe * arr[i - 1];
        }
      }
    }
    cout << sol << endl;
  }
}
