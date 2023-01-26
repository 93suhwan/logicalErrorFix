#include <bits/stdc++.h>
using namespace std;
void solve(long long n, long long k) {
  long long have = 1;
  long long hour = 0;
  while (n - have > 0) {
    long long cable = min(k, have);
    have += min(n - have, cable);
    hour++;
    if (k == cable) {
      hour += (n - have + k - 1) / k;
      break;
    }
  }
  cout << hour << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    solve(n, k);
  }
}
