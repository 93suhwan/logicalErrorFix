#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr, l, r;
bool solve(int i, int j, int prev, bool cur) {
  if (i == j) return cur;
  if (arr[i] <= prev && arr[j] <= prev) {
    return !cur;
  }
  if (arr[i] <= prev) {
    int pp = min(r[j], j - i + 1);
    if (pp % 2 == 1) return cur;
    return !cur;
  }
  if (arr[j] <= prev) {
    int pp = min(l[i], j - i + 1);
    if (pp % 2 == 1) return cur;
    return !cur;
  }
  if (arr[i] < arr[j] && min(l[i], j - i + 1) % 2 == 1) {
    return cur;
  }
  if (arr[i] > arr[j] && min(r[j], j - i + 1) % 2 == 1) {
    return cur;
  }
  if (arr[i] < arr[j]) {
    return solve(i + 1, j, arr[i], !cur);
  } else {
    return solve(i, j - 1, arr[j], !cur);
  }
}
int main() {
  cin >> n;
  arr.resize(n);
  l.resize(n);
  r.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  l[n - 1] = 1;
  r[0] = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      r[i] = r[i - 1] + 1;
    else
      r[i] = 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1])
      l[i] = l[i + 1] + 1;
    else
      l[i] = 1;
  }
  if (solve(0, n - 1, -1, 0))
    cout << "Bob";
  else
    cout << "Alice";
}
