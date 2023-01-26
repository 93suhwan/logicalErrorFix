#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a - b > 1 || b - a > 1 || a + b > n - 2)
      cout << -1 << "\n";
    else {
      int arr[n];
      for (int i = 0; i < n; ++i) arr[i] = i + 1;
      if (b > a) {
        swap(arr[0], arr[1]);
        int rem = min(a, b);
        for (int i = 2; i < n - 2 && rem; i += 2) {
          swap(arr[i], arr[i + 1]);
          rem--;
        }
      } else if (a > b) {
        swap(arr[n - 1], arr[n - 2]);
        int rem = min(a, b);
        for (int i = n - 3; i > 1 && rem; i -= 2) {
          swap(arr[i], arr[i - 1]);
          rem--;
        }
      } else {
        int rem = min(a, b);
        for (int i = 1; i < n - 2 && rem; i += 2) {
          swap(arr[i], arr[i + 1]);
          rem--;
        }
      }
      for (auto x : arr) cout << x << " ";
      cout << "\n";
    }
  }
  return 0;
}
