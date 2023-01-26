#include <bits/stdc++.h>
using namespace std;
int selectionSort(string arr, int n) {
  int i, j, min_idx;
  int op = 0;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
        op++;
      }
    char temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
  return op;
}
void solution() {
  int n;
  string s;
  cin >> n >> s;
  int count = selectionSort(s, n);
  if (count == 1) count++;
  cout << count << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
