#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int k;
    cin >> k;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long int count = 0;
    for (long long int i = 0; i < n - 2 * k; i++) {
      count += arr[i];
    }
    long long int j = 0;
    for (long long int i = n - 2 * k; j < k; i++) {
      long long int x = arr[i] / arr[i + k];
      count += x;
      j++;
    }
    cout << count << "\n";
  }
}
