#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, count = 0;
  cin >> n;
  string arr;
  cin >> arr;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]), count++;
  }
  if (count == 0)
    cout << count << endl;
  else
    cout << count + 1 << endl;
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
