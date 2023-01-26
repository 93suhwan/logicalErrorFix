#include <bits/stdc++.h>
using namespace std;
long long getPairsCount(int arr[], int n, long long sum) {
  map<int, int> m;
  for (int i = 0; i < n; i++) m[arr[i]]++;
  long long twice_count = 0;
  for (int i = 0; i < n; i++) {
    twice_count += m[sum - arr[i]];
    if (sum - arr[i] == arr[i]) twice_count--;
  }
  return twice_count / 2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ara[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> ara[i];
      sum += ara[i];
    }
    sum *= 2;
    if (sum % n) {
      cout << "0\n";
      continue;
    }
    cout << getPairsCount(ara, n, sum / n) << endl;
  }
}
