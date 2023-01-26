#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long w, h;
  cin >> w >> h;
  long long x1;
  cin >> x1;
  long long arr1[x1];
  for (long long i = 0; i < x1; i++) {
    cin >> arr1[i];
  }
  long long x2;
  cin >> x2;
  long long arr2[x2];
  for (long long i = 0; i < x2; i++) {
    cin >> arr2[i];
  }
  long long y1;
  cin >> y1;
  long long arr3[y1];
  for (long long i = 0; i < y1; i++) {
    cin >> arr3[i];
  }
  long long y2;
  cin >> y2;
  long long arr4[y2];
  for (long long i = 0; i < y2; i++) {
    cin >> arr4[i];
  }
  sort(arr1, arr1 + x1);
  sort(arr2, arr2 + x2);
  sort(arr3, arr3 + y1);
  sort(arr4, arr4 + y2);
  long long max1 = arr1[x1 - 1] - arr1[0];
  long long max2 = arr2[x2 - 1] - arr2[0];
  long long max3 = arr3[y1 - 1] - arr3[0];
  long long max4 = arr4[y2 - 1] - arr4[0];
  long long max5 = max(max1, max2);
  long long max6 = max(max3, max4);
  long long maxx = max(max5 * h, max6 * w);
  cout << maxx << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
