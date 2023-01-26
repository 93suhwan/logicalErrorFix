#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
using namespace std;
template <typename val1>
void __f(const char* name, val1&& value) {
  cout << name << " = " << value << endl;
}
template <typename val1, typename... values>
void __f(const char* names, val1&& value, values&&... multiplevalue) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " = " << value << " ";
  __f(comma + 1, multiplevalue...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int f = 1;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (i) {
        if (arr[i] < arr[i - 1]) f = 0;
      }
    }
    if (f) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j + 1 < n and arr[j] > arr[j + 1]) {
          int k = j;
          while (k < n) {
            if (k + 1 < n and arr[k + 1] < arr[k]) swap(arr[k], arr[k + 1]);
            k += 2;
          }
          break;
        }
      }
      int can = 1;
      for (int j = 1; j < n; j++) {
        if (arr[j] < arr[j - 1]) can = 0;
      }
      if (can) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
