#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; ++i) cin >> arr[i];
    long long max = 0, counter = 0, max_count = 0;
    for (long long i = 0; i < n; ++i) {
      counter++;
      if (arr[i] > max) {
        max = arr[i];
        max_count = counter;
      }
    }
    cout << max - max_count << endl;
  }
}
