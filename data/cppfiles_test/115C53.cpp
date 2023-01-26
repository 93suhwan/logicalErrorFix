#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, h, arr[100], sum, left, right, tek;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> h;
    for (int j = 0; j < n; j++) cin >> arr[j];
    left = 0;
    right = h;
    while (right - left > 1) {
      sum = 0;
      tek = (right + left) / 2;
      for (int j = 1; j < n; j++)
        if (arr[j] - arr[j - 1] > tek)
          sum += tek;
        else
          sum += arr[j] - arr[j - 1];
      sum += tek;
      if (sum >= h)
        right = tek;
      else
        left = tek;
    }
    cout << right << endl;
  }
}
