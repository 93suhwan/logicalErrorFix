#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int A[n + 1];
    for (int i = 1; i <= n; i++) cin >> A[i];
    int m = 0;
    for (int i = 1; i <= n; i++) m = max(m, A[i] - i);
    cout << m << '\n';
  }
  return 0;
}
