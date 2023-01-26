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
    long long current_max = 0;
    for (long long i = 1; i < n; ++i) {
      if (arr[i] > arr[current_max]) current_max = i;
    }
    cout << arr[current_max] - current_max - 1 << endl;
  }
}
