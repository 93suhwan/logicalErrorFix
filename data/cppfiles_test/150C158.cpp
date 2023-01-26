#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto x = (0) - ((0) > (n)); x != (n) - ((0) > (n));
       ((0) < (n) ? x++ : x--))
    cin >> arr[x];
  sort(arr.begin(), arr.end());
  bool zero = false;
  bool one = false;
  bool two = false;
  vector<int> val(3);
  long long ans = arr[n - 1] / 3;
  set<int> s;
  for (auto x = (0) - ((0) > (n)); x != (n) - ((0) > (n));
       ((0) < (n) ? x++ : x--)) {
    if (arr[x] % 3 == 0) {
      zero = true;
      if (s.find(arr[x]) == s.end()) {
        val[0]++;
        s.insert(arr[x]);
      }
    } else if (arr[x] % 3 == 1) {
      one = true;
      if (s.find(arr[x]) == s.end()) {
        val[1]++;
        s.insert(arr[x]);
      }
    } else {
      two = true;
      if (s.find(arr[x]) == s.end()) {
        val[2]++;
        s.insert(arr[x]);
      }
    }
  }
  if (one) ans++;
  if (two) ans++;
  if (one && two && zero) {
    int k = arr[n - 1];
    if (k % 3 == 0) {
      ans -= 1;
    } else if (k % 3 == 1) {
      if (s.find(1) == s.end()) {
        if (s.find(k - 1) == s.end()) {
          ans--;
        }
      }
    }
  } else if (zero == false && one && two) {
    int k = arr[n - 1];
    if (k % 3 == 1 && s.find(1) == s.end()) {
      ans--;
    }
  } else {
    ans = ans;
  }
  cout << ans << "\n";
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
