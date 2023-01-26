#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = int(0); i < int(t); i++) {
    int n;
    cin >> n;
    vector<long long> arr(n, 0);
    for (int j = int(0); j < int(n); j++) cin >> arr[j];
    long long sumA = 0;
    for (int j = int(0); j < int(n); j++) sumA += arr[j];
    long long temp = n * (n + 1) / 2;
    if (sumA % temp != 0) {
      cout << "NO" << endl;
      continue;
    }
    sumA = sumA / temp;
    vector<long long> diff(n, 0);
    diff[0] = arr[0] - arr[n - 1];
    for (int j = int(1); j < int(n); j++) diff[j] = arr[j] - arr[j - 1];
    vector<long long> a(n, 0);
    bool flag = 0;
    for (int j = int(0); j < int(n); j++) {
      long long temp = (sumA - diff[j]) / n;
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
