#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    long long num1 = 1, num2 = 2;
    while (num1 * num1 <= n) {
      num1++;
      ans++;
    }
    while (num2 * num2 * num2 <= n) {
      num2++;
      ans++;
    }
    cout << ans << "\n";
  }
}
