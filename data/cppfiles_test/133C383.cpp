#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool isvowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  else
    return false;
}
void solve() {
  int n;
  cin >> n;
  vector<string> arr(n - 2);
  for (int i = 0; i < n - 2; i++) {
    cin >> arr[i];
  }
  string ans = "";
  int cnt = 0;
  ans += arr[0];
  if (n == 3) {
    ans += 'b';
    cout << ans << endl;
    return;
  }
  for (int i = 1; i < n - 2; i++) {
    if (arr[i - 1][1] == arr[i][0]) {
      ans += arr[i][1];
    } else {
      cnt = 1;
      ans += arr[i];
    }
  }
  if (ans.length() == n) {
    cout << ans << endl;
    return;
  } else
    ans += 'a';
  cout << ans << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
