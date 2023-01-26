#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, count = 0;
  cin >> n;
  string arr, res;
  cin >> arr;
  res += arr;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (res[i] != arr[i]) count++;
  }
  cout << count << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
