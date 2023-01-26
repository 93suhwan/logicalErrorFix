#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void solve() {
  long long int T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    long long ans = 0, arr[n];
    memset(arr, -1, sizeof(arr));
    for (long long int i = 0; i < (long long int)(n); i++) {
      if (s2[i] == '1') {
        if (s1[i] == '0')
          ans++;
        else if (i > 0 && s1[i - 1] == '1' && arr[i - 1] == -1) {
          ans++;
          arr[i - 1] = 0;
        } else if (i < n - 1 && s1[i + 1] == '1' && arr[i + 1] == -1) {
          ans++;
          arr[i + 1] = 0;
        }
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
