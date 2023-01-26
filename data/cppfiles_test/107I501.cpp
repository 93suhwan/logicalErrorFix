#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 998244353;
long long INF = 1000000000000000000;
struct mycmp {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return (a.first < b.first) || (a.first == b.first && a.second > b.second);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    vector<long long> arr(n + 1, 0);
    int diff = abs(a - b);
    int p = max(a, b);
    if (diff > 1 || p > (n - 1) / 2)
      cout << -1 << "\n";
    else if (a == 0 && b == 0) {
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << "\n";
    } else if (diff == 0) {
      int y = 1;
      for (int i = 2; i <= n; i = i + 2) {
        arr[i] = y;
        ++y;
      }
      int p = n;
      for (int i = 1; i <= n; i = i + 2) {
        arr[i] = p;
        --p;
      }
      for (int i = 2; i < n; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
          --a;
        }
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
          --b;
        }
        if (a == 0 && b == 0) {
          sort(arr.begin() + i + 1, arr.end());
          reverse(arr.begin() + 1 + i, arr.end());
          break;
        }
      }
      for (long long i = 1; i <= n; i++) cout << arr[i] << " ";
      cout << "\n";
    } else if (a > b) {
      int y = n;
      for (int i = 2; i <= n; i = i + 2) {
        arr[i] = y;
        --y;
      }
      int p = 1;
      for (int i = 1; i <= n; i = i + 2) {
        arr[i] = p;
        ++p;
      }
      for (int i = 2; i < n; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
          --a;
        }
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
          --b;
        }
        if (a == 0 && b == 0) {
          sort(arr.begin() + i, arr.end());
          reverse(arr.begin() + i, arr.end());
          break;
        }
      }
      for (long long i = 1; i <= n; i++) cout << arr[i] << " ";
      cout << "\n";
    } else {
      int y = 1;
      for (int i = 2; i <= n; i = i + 2) {
        arr[i] = y;
        ++y;
      }
      int p = n;
      for (int i = 1; i <= n; i = i + 2) {
        arr[i] = p;
        --p;
      }
      for (int i = 2; i < n; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
          --a;
        }
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
          --b;
        }
        if (a == 0 && b == 0) {
          sort(arr.begin() + i, arr.end());
          break;
        }
      }
      for (long long i = 1; i <= n; i++) cout << arr[i] << " ";
      cout << "\n";
    }
  }
}
