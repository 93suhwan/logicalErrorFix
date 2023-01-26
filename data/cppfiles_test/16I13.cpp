#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x;
  cin >> x;
  while (x--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int arr[n];
    int z = 0;
    int y;
    for (int i = 0; i < n; i++) {
      arr[i] = s[i] - 'a';
    }
    for (int i = 0; i < n - 1; i++) {
      if (z == 0) {
        if (arr[i + 1] - arr[i] < 0) {
          z = 2;
        }
        y = arr[i];
      } else if (arr[i + 1] - y < 0) {
        z++;
      }
    }
    cout << z << "\n";
  }
}
