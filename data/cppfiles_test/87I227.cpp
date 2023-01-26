#include <bits/stdc++.h>
using namespace std;
bool cmp(int &a, int &b) { return a > b; }
void solve() {
  int n;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long int ct = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= i + 1)
      continue;
    else
      ct++;
  }
  if (ct == 0) {
    cout << ct;
  } else {
    ct = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] > i + 1 && i + 1 == 1) {
        ct += abs(arr[i] - 1);
      } else if (arr[i] > i + 1 && i + 1 != 1) {
        ct += abs(arr[i] - arr[i - 1] - 1);
      }
    }
    cout << ct;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int l;
  cin >> l;
  while (l--) {
    solve();
    cout << endl;
  }
  return 0;
}
