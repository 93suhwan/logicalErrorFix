#include <bits/stdc++.h>
using namespace std;
using lld = signed long long int;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ' ';
  err(++it, args...);
}
bool solve() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  int l = 0, r = n - 1, L, R, prev = -1;
  for (L = 1; L < n; L++)
    if (arr[L - 1] >= arr[L]) break;
  for (R = n - 2; R >= 0; R--)
    if (arr[R] <= arr[R + 1]) break;
  bool flag = true;
  while (l < r) {
    if (prev >= arr[l] && prev >= arr[r]) {
      return !flag;
    } else if (prev >= arr[l]) {
      if ((r - R) % 2 == 0) return !flag;
      return flag;
    } else if (prev >= arr[r]) {
      if ((L - l) % 2 == 0) return !flag;
      return flag;
    }
    if (arr[l] == arr[r]) {
      if ((L - l) % 2 == 0 && (r - R) % 2 == 0) return !flag;
      return flag;
    } else if (arr[l] < arr[r]) {
      if ((r - R) % 2 != 0)
        prev = arr[r--];
      else
        prev = arr[l++];
    } else {
      if ((L - l) % 2 != 0)
        prev = arr[l++];
      else
        prev = arr[r--];
    }
    flag = !flag;
  }
  return flag;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    if (solve())
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
  return 0;
}
