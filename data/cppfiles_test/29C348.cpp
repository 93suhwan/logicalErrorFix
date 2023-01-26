#include <bits/stdc++.h>
using namespace std;
void play() {
  int n;
  cin >> n;
  vector<int> v(n);
  long long int one = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == 1) {
      one++;
    } else if (v[i] == 0) {
      zero++;
    }
  }
  long long int ans = 0;
  ans += (one * pow(2, zero));
  cout << ans << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    play();
  }
  return 0;
}
