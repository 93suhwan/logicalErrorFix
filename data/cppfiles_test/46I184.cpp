#include <bits/stdc++.h>
using namespace std;
int add(int x, int y) { return (1ll * x + 1ll * y) % 1000000007; }
int del(int x, int y) {
  return ((1ll * x - 1ll * y) % 1000000007 + 1000000007) % 1000000007;
}
int mul(int x, int y) { return (1ll * x * 1ll * y) % 1000000007; }
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  set<long long int> st;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    st.insert(arr[i]);
  }
  long long int mn = *min_element(arr, arr + n);
  long long int mx = *max_element(arr, arr + n);
  if (mx == arr[n - 1] || st.size() == 1 || is_sorted(arr, arr + n))
    cout << 0 << "\n";
  else if (mx == arr[0] && mn == arr[n - 1])
    cout << 2 << "\n";
  else
    cout << 1 << "\n";
}
int main() {
  long long int t;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
