#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr, l, r;
bool solve(int a, int b, int prev, bool player) {
  if (arr[a] <= prev && arr[b] <= prev)
    return !player;
  else if (arr[a] <= prev) {
    return solve(a, b - 1, arr[b], !player);
  } else if (arr[b] <= prev) {
    return solve(a + 1, b, arr[a], !player);
  } else if (arr[b] > arr[a] && r[b] % 2 == 1) {
    return player;
  } else if (arr[a] > arr[b] && l[a] % 2 == 1) {
    return player;
  } else if (arr[a] == arr[b] && (l[a] % 2 == 1 || r[b] % 2 == 1)) {
    return player;
  } else {
    if (arr[a] < arr[b]) {
      return solve(a + 1, b, arr[a], !player);
    } else {
      return solve(a, b - 1, arr[b], !player);
    }
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
  if (solve(0, n - 1, -1, true))
    cout << "Alice";
  else
    cout << "Bob";
}
