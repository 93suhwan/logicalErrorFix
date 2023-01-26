#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, count = 0;
  cin >> n;
  string arr, res;
  cin >> arr;
  res += arr;
  sort(arr.begin(), arr.end());
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
