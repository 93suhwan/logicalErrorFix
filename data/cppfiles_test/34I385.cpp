#include <bits/stdc++.h>
long long mod = 1e9 + 7;
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k, mx_first = -1e9, place_first = 0, mx_sec = -1e9, place_sec = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if ((i + 1) - arr[i] >= mx_first && i >= place_first) {
        mx_first = max((i + 1) - arr[i], mx_first);
        place_first = i + 1;
      }
    }
    mx_first = arr[place_first - 1];
    arr.erase(arr.begin() + (place_first - 1));
    for (int i = 0; i < arr.size(); i++) {
      if ((i + 1) - arr[i] >= mx_sec && i >= place_sec) {
        mx_sec = max((i + 1) - arr[i], mx_sec);
        place_sec = i + 1;
      }
    }
    mx_sec = arr[place_sec - 1];
    long long res = (place_first * place_sec) + (-k * (mx_first | mx_sec));
    cout << res << endl;
  }
}
