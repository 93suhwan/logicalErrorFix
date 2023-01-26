#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
const int32_t mod = 1e9 + 7;
const int N = 5e5 + 5;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  string second, t;
  cin >> second >> t;
  sort(second.begin(), second.end());
  if (t != "abc")
    cout << second << endl;
  else {
    vector<int> arr(26, 0);
    for (int i = 0; i < second.size(); i++) {
      arr[second[i] - 'a']++;
    }
    if (arr[0] == 0 || arr[1] == 0 || arr[2] == 0) {
      cout << second << endl;
      return;
    }
    string ans = "";
    while (arr[0]--) ans += 'a';
    while (arr[2]--) ans += 'c';
    while (arr[1]--) ans += 'b';
    for (int i = 3; i < 26; i++) {
      while (arr[i]--) ans += (i + 'a');
    }
    cout << ans << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
