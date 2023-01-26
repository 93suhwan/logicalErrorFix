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
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] > maxe) {
        maxe = arr[i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (arr[i] == maxe) {
        c++;
      }
    }
    long long maxar[c];
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == maxe) {
        if (i == 0) {
          maxar[j] = maxe * arr[i + 1];
        } else if (i == n - 1) {
          maxar[j] = maxe * arr[i - 1];
        } else {
          maxar[j] = maxe * max(arr[i + 1], arr[i - 1]);
        }
        j++;
      }
    }
    long long sol = maxar[0];
    for (int i = 0; i < c; i++) {
      if (maxar[i] > sol) sol = maxar[i];
    }
    cout << sol << endl;
  }
}
