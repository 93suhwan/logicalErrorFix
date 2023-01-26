#include <bits/stdc++.h>
using namespace std;
void solve(long long t) {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  long long res = 0;
  for (int i = 0; i < n; i++) {
    while (arr[i] == i + 1) i++;
    long long check1 = arr[i] + i + 1;
    long long check2 = arr[i] - i - 1;
    if (arr[i] % check1 == i + 1)
      res++;
    else if (check2 > 0 && arr[i] % check2 == i + 1)
      res++;
    else {
      cout << -1 << endl;
      return;
    }
  }
  cout << res << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve(t);
  }
}
