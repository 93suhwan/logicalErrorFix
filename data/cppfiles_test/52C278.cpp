#include <bits/stdc++.h>
using namespace std;
double largest(long long int arr[], int n) {
  int i;
  int max = arr[0];
  for (i = 1; i < n; i++)
    if (arr[i] > max) max = arr[i];
  return max;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t) {
    int n;
    cin >> n;
    long long int arr[n];
    double temp, max, sum = 0, ans;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    max = largest(arr, n);
    temp = (sum - max) / (n - 1);
    ans = max + temp;
    cout << fixed << setprecision(7) << ans << endl;
    t--;
  }
  return 0;
}
