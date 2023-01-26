#include <bits/stdc++.h>
using namespace std;
const int siz1 = 1e5, siz2 = 512, siz3 = 1e6, mod = 998244353;
int n, minidx[siz2 + 5];
pair<int, int> arr[siz1 + 5];
bool ans[siz2 + 5];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i].first);
    arr[i].second = i;
  }
  for (int i = 0; i < siz2; ++i) {
    minidx[i] = INT_MAX;
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; ++i) {
    ans[arr[i].first] = 1;
    minidx[arr[i].first] = min(minidx[arr[i].first], arr[i].second);
    for (int j = 0; j < siz2; ++j) {
      if (minidx[j] < arr[i].second) {
        int val = j ^ arr[i].first;
        ans[val] = 1;
        minidx[val] = min(minidx[val], arr[i].second);
      }
    }
  }
  int ans_sz = 0;
  for (int i = 0; i < siz2; ++i) {
    if (ans[i]) {
      ++ans_sz;
    }
  }
  ans[0] = 1;
  printf("%d\n", ans_sz);
  for (int i = 0; i < siz2; ++i) {
    if (ans[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
