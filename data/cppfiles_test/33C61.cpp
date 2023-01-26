#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int T;
  cin >> T;
  while (T--) {
    long long int ans = 0;
    int N;
    cin >> N;
    long long int arr[N + 1];
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 1; i < N; i++) ans = max(ans, arr[i] * arr[i - 1]);
    cout << ans << endl;
  }
  return 0;
}
