#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long arr[3];
    for (int i = 0; i < 3; i++) {
      cin >> arr[i];
    }
    int cnt = 0;
    int cnt1 = 0;
    for (int i = 0; i < 3; i++) {
      if (arr[i] % 2 == 0)
        cnt++;
      else
        cnt1++;
    }
    sort(arr, arr + 3);
    if (arr[0] + arr[1] == arr[2])
      cout << "YES" << '\n';
    else if (cnt == 1 && cnt1 == 2)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
