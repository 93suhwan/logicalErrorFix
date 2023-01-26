#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    long long int maxx = INT_MIN, index;
    long long int arr[a];
    for (int i = 0; i < a; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < a - 1; i++) {
      if (arr[i] * arr[i + 1] > maxx) {
        maxx = arr[i] * arr[i + 1];
      }
    }
    cout << maxx << endl;
  }
}
