#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, k, n, arr[200200], minhod, sum, sum1, tekhod;
  cin >> t;
  for (int j = 0; j < t; j++) {
    sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    sort(arr, arr + n);
    if (sum <= k)
      cout << 0;
    else {
      minhod = sum - k;
      for (int i = 1; i < n; i++) {
        sum -= arr[n - i];
        sum += arr[0];
        if (sum <= k)
          tekhod = i;
        else
          tekhod = i + (sum - k - 1) / (i + 1) + 1;
        minhod = min(minhod, tekhod);
      }
      cout << minhod;
    }
    cout << endl;
  }
}
