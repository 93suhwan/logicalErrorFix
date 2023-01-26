#include <bits/stdc++.h>
using namespace std;
int arr[7];
int main() {
  freopen("text.in", "r", stdin);
  freopen("text.out", "w+", stdout);
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> arr[j];
    }
    cout << arr[0] << " " << arr[1] << " "
         << ((arr[0] + arr[1] == arr[2]) ? arr[3] : arr[2]) << "\n";
  }
}
