#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    int n, j;
    scanf("%d", &n);
    int arr[n];
    for (j = 0; j < n; j++) scanf("%d", &arr[j]);
    sort(arr, arr + n);
    for (j = 0; j < n / 2; j++) printf("%d %d\n", arr[j + 1], arr[0]);
  }
}
