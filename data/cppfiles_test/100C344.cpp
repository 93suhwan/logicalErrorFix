#include <bits/stdc++.h>
using namespace std;
int minimum() {
  long long n, min, integer;
  cin >> n;
  vector<long long> arr;
  for (int i = 0; i < n; i++) {
    cin >> integer;
    arr.push_back(integer);
  }
  if (n == 1)
    return arr[0];
  else {
    sort(arr.begin(), arr.end());
    long long min = arr[0];
    for (int i = 1; i < n; i++) {
      min = max(min, arr[i] - arr[i - 1]);
    }
    return min;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cout << minimum() << endl;
  }
  return 0;
}
