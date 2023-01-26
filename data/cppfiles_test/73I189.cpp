#include <bits/stdc++.h>
using namespace std;
void solve(int z) {
  long long int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int maxi = 0;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, abs(arr[i] - i));
  }
  if (maxi == 0)
    cout << maxi << "\n";
  else
    cout << maxi + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int c = 1;
  while (t--) {
    solve(c);
    c++;
  }
  return 0;
}
