#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  pair<int, int> arr[200000];
  int a[200000];
  int t;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> arr[i].first;
      arr[i].second = i;
    }
    sort(arr, arr + n);
    int color = 1;
    int count = 0;
    int prev = -1;
    int total = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i].first != prev) {
        prev = arr[i].first;
        count = 0;
      }
      if (count != k) {
        count++;
        total++;
      }
    }
    total = (total / k) * k;
    color = 1;
    count = 0;
    prev = -1;
    for (int i = 0; i < n; i++) {
      if (arr[i].first != prev) {
        prev = arr[i].first;
        count = 0;
      }
      if (count == k || total == 0) {
        a[arr[i].second] = 0;
      } else {
        a[arr[i].second] = color;
        color += 1;
        if (color == k + 1) {
          color = 1;
        }
        count++;
        total--;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
}
