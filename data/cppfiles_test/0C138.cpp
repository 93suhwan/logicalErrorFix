#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  pair<string, int>* arr = new pair<string, int>[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  bool flag1 = 1, flag2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j % 2) {
        arr[i].first[j] = 'Z' - arr[i].first[j] + 'A';
      }
    }
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) {
    cout << arr[i].second + 1 << " ";
  }
}
