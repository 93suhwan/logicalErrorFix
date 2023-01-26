#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    int maxx = INT_MIN, index;
    long long int arr[a];
    for (int i = 0; i < a; i++) {
      cin >> arr[i];
      if (arr[i] > maxx) {
        maxx = arr[i];
        index = i;
      }
    }
    cout << max(arr[index] * arr[index - 1], arr[index] * arr[index + 1])
         << endl;
  }
}
