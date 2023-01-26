#include <bits/stdc++.h>
using namespace std;
void Ashfaque() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
}
int main() {
  Ashfaque();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 2];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    int pairs = n / 2;
    sort(arr, arr + n);
    for (int i = 1; i <= pairs; ++i) {
      cout << arr[i] << " " << arr[0] << "\n";
    }
  }
  return 0;
}
