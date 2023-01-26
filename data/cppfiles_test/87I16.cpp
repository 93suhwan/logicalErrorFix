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
    long long max_index = 0;
    for (long long i = 1; i < n; ++i) {
      if (arr[i] > arr[max_index]) max_index = i;
    }
    cout << arr[max_index] - max_index - 1 << endl;
  }
}
