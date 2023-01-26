#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) {
  if (a[0] != b[0]) return a < b;
  return a > b;
}
int main() {
  long long n, m;
  cin >> n >> m;
  string arr[n], arr2[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    arr2[i] = arr[i];
  }
  sort(arr, arr + n, cmp);
  for (long long i = 0; i < n; i++) {
    long long x = 0;
    while (arr2[x] != arr[i]) x++;
    cout << x + 1 << " ";
  }
}
