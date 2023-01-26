#include <bits/stdc++.h>
using namespace std;
void _cout(int x) { cout << x; }
void _cout(char x) { cout << x; }
void _cout(long long int x) { cout << x; }
void _cout(string x) { cout << x; }
void _cout(bool x) { cout << x; }
template <class T>
void _cout(vector<T> &arr) {
  cout << "[ ";
  for (T item : arr) {
    _cout(item);
    cout << " ";
  }
  cout << "]";
}
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  int n;
  long long int k;
  cin >> n >> k;
  vector<int> arr(n);
  long long int sum = 0LL;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum <= k) {
    cout << 0 << "\n";
    return;
  }
  if (n == 1) {
    cout << (sum - k) << "\n";
    return;
  }
  if (k + 1 == sum) {
    cout << 1 << "\n";
    return;
  }
  sort(arr.begin(), arr.end());
  vector<long long int> sufSum(n);
  sufSum[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sufSum[i] = sufSum[i + 1] + arr[i];
  }
  long long int need = sum - k;
  long long int ans = INT_MAX;
  for (int i = n - 1; i > 0; i--) {
    long long int bSum = sufSum[i];
    long long int bC = n - i;
    long long int preX = bSum - (arr[0] * bC);
    if (preX >= need) {
      ans = min(ans, (bC * 1LL));
      continue;
    }
    long long int x =
        max((need - bSum + (arr[0] * bC) + (bC + 1) - 1) / (bC + 1), 0LL);
    ans = min(ans, (bC + x));
  }
  cout << ans << "\n";
}
int main(int argc, char const *argv[]) {
  init();
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
