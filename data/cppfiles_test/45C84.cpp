#include <bits/stdc++.h>
using namespace std;
long long getMin(vector<int>& required, vector<int>& zeroIndices, int n) {
  int j = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (required[i] == 0) {
      ans += abs(zeroIndices[j++] - i);
    }
  }
  return ans;
}
void solve(long long arr[], int n) {
  int countZero = 0, countOne = 0;
  for (int i = 0; i < n; i++) {
    arr[i] %= 2;
    if (arr[i] == 0) {
      countZero++;
    } else {
      countOne++;
    }
  }
  if (n % 2 == 0 && countZero != countOne) {
    cout << -1 << endl;
    return;
  }
  if (n % 2 != 0 && abs(countOne - countZero) != 1) {
    cout << -1 << endl;
    return;
  }
  vector<int> oneIndices, zeroIndices;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      zeroIndices.push_back(i);
    } else {
      oneIndices.push_back(i);
    }
  }
  long long ans = LLONG_MAX;
  vector<int> required(n, 0);
  for (int i = 0; i < n; i++) {
    required[i] = (i % 2 == 0 ? 1 : 0);
  }
  if (countZero <= countOne) ans = min(ans, getMin(required, zeroIndices, n));
  for (int i = 0; i < n; i++) {
    required[i] = (i % 2 != 0 ? 1 : 0);
  }
  if (countOne <= countZero) ans = min(ans, getMin(required, zeroIndices, n));
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    solve(arr, n);
  }
}
