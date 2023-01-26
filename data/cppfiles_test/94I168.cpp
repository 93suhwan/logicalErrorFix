#include <bits/stdc++.h>
using namespace std;
int long long power(int long long n) {
  string s = "1";
  for (int i = 0; i < n; i++) {
    s += "0";
  }
  return stoll(s);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int long long n, k;
    cin >> n >> k;
    k++;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (k <= 9) {
      cout << k << endl;
    }
    int idx = -1;
    int long long result = 0;
    for (int i = 1; i < n; i++) {
      if (k + 1 > power(arr[i]) / power(arr[i - 1])) {
        k -= (power(arr[i]) / power(arr[i - 1]) - 1);
        result += ((power(arr[i]) / power(arr[i - 1]) - 1) * power(arr[i - 1]));
      } else {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      result += (k * power(arr[n - 1]));
    } else {
      result += (k * power(arr[idx - 1]));
    }
    cout << result << endl;
  }
  return 0;
}
