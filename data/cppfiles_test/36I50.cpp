#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  for (int i = 2; i * i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    int ans = n;
    while (isPrime(sum)) {
      int index, num, anothernum = -1;
      for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
          if (!isPrime(sum - arr[i])) {
            anothernum = arr[i];
            arr[i] = -1;
            break;
          }
          num = arr[i];
          index = i;
        }
      }
      if (anothernum == -1) {
        sum -= num;
        arr[index] = -1;
      } else {
        sum -= anothernum;
      }
      ans--;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
      if (arr[i] != -1) {
        cout << i + 1 << " ";
      }
    }
    cout << "\n";
  }
}
