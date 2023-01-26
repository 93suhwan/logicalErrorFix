#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = int(0); i < int(t); i++) {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int j = int(0); j < int(n); j++) cin >> arr[j];
    int sumA = 0;
    for (int j = int(0); j < int(n); j++) sumA += arr[j];
    int temp = n * (n + 1) / 2;
    if (sumA % temp != 0) {
      cout << "NO" << endl;
      continue;
    }
    sumA = sumA / temp;
    vector<int> diff(n, 0);
    diff[0] = arr[0] - arr[n - 1];
    for (int j = int(1); j < int(n); j++) diff[j] = arr[j] - arr[j - 1];
    vector<int> a(n, 0);
    bool flag = 0;
    for (int j = int(0); j < int(n); j++) {
      int temp = (sumA - diff[j]) / n;
      if (temp <= 0) {
        flag = 1;
        cout << "NO" << endl;
        break;
      }
      a[j] = temp;
    }
    if (flag == 1) continue;
    cout << "YES" << endl;
    for (int j = int(0); j < int(n); j++) cout << a[j] << " ";
    cout << endl;
  }
  return 0;
}
