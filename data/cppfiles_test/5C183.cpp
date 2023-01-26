#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int Tt = 1;
  cin >> Tt;
  while (Tt--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < b.size(); i++) {
      if (b[i] == '1') {
        if (a[i] == '0') {
          ans++;
          a[i] = '2';
        } else if (a[i] == '2' || a[i] == '1') {
          if (i - 1 >= 0 && a[i - 1] == '1') {
            a[i - 1] = '2';
            ans++;
          } else if (i + 1 < a.size() && a[i + 1] == '1') {
            ans++;
            a[i + 1] = '2';
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
