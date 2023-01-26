#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    long long int a;
    cin >> a;
    long long int arr[a];
    for (int i = 0; i < a; i++) cin >> arr[i];
    long long int b;
    cin >> b;
    long long int brr[b];
    for (int i = 0; i < b; i++) cin >> brr[i];
    long long int c;
    cin >> c;
    long long int crr[c];
    for (int i = 0; i < c; i++) cin >> crr[i];
    long long int d;
    cin >> d;
    long long int drr[d];
    for (int i = 0; i < d; i++) cin >> drr[i];
    sort(arr, arr + a);
    long long int ans = 0;
    long long int dif1 = arr[a - 1] - arr[0];
    dif1 = dif1 * h;
    ans = dif1;
    sort(crr, crr + c);
    long long int dif2 = crr[c - 1] - crr[0];
    dif2 = dif2 * w;
    if (ans <= dif2) {
      ans = dif2;
    }
    sort(drr, drr + d);
    long long int dif3 = drr[d - 1] - drr[0];
    dif3 = dif3 * w;
    if (ans <= dif3) {
      ans = dif3;
    }
    sort(brr, brr + b);
    long long int dif4 = brr[b - 1] - brr[0];
    dif4 = dif4 * h;
    if (ans <= dif4) {
      ans = dif4;
    }
    cout << ans << endl;
  }
}
