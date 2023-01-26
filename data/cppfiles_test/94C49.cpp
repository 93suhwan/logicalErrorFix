#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> dp;
int count(int n) {
  int c = 0;
  if (n < 0) return 0;
  for (int i = 0; i <= n; i++) {
    if (i <= 9 && n - i <= 9) c++;
  }
  return c;
}
int fun(vector<int> arr, int i) {
  if (i >= 12) return 1;
  int v = count(arr[i]) * fun(arr, i + 1);
  if (i + 2 <= 11) {
    arr[i + 2]--;
    int v1 = count(10 + arr[i]);
    v += (v1 * fun(arr, i + 1));
    return v;
  }
  return v;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(12, 0);
    int i = 0;
    while (n != 0) {
      arr[i] = n % 10;
      n = n / 10;
      i++;
    }
    cout << fun(arr, 0) - 2 << endl;
  }
  return 0;
}
