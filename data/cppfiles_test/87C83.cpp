#include <bits/stdc++.h>
using namespace std;
void Function() {
  long long n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long sum = 0, prev = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= prev) {
      prev++;
      continue;
    }
    sum += arr[i] - prev - 1;
    prev = arr[i];
  }
  cout << sum << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    Function();
  }
  return 0;
}
