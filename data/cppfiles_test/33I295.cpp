#include <bits/stdc++.h>
const long long nint = 1e9 + 7;
const long long i1 = 1e6 + 5;
const long long num = 1e5 + 5;
using namespace std;
bool itsrt(string s, long long n) {
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      return false;
    }
  }
  return true;
}
void kkkuuu() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long maxi = max_element(arr, arr + n) - arr;
  long long maxel = *max_element(arr, arr + n);
  if (maxi == 0) {
    cout << maxel * arr[maxi + 1] << "\n";
    return;
  } else if (maxi == n - 1) {
    cout << maxel * arr[maxi - 1] << "\n";
    return;
  } else if (arr[maxi + 1] > arr[maxi - 1]) {
    cout << maxel * arr[maxi + 1] << "\n";
  } else {
    cout << maxel * arr[maxi - 1] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tct = 1;
  cin >> tct;
  while (tct--) {
    kkkuuu();
  }
}
