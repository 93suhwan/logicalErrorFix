#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int w, h;
    cin >> w >> h;
    long long int mati[4] = {0};
    for (int i = 0; i < 4; i++) {
      int k;
      cin >> k;
      int arr[k];
      for (int j = 0; j < k; j++) {
        cin >> arr[j];
      }
      sort(arr, arr + k);
      mati[i] = arr[k - 1] - arr[0];
    }
    mati[0] *= h;
    mati[1] *= h;
    mati[2] *= w;
    mati[3] *= w;
    sort(mati, mati + 4);
    cout << mati[3] << endl;
  }
  return 0;
}
