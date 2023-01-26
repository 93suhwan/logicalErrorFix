#include <bits/stdc++.h>
using namespace std;
void cyclicSort(int arr[], vector<int> v[], int n, int K[], int i) {
  int k = 0;
  for (int i = n - 2; i >= 0; i--) {
    bool b = false;
    int current = arr[i];
    int j = i + 1;
    while (arr[j] > current && j < n) {
      arr[j - 1] = arr[j];
      j++;
      b = true;
    }
    if (b) {
      v[0].push_back(i + 1);
      v[1].push_back(j);
      k++;
    }
    arr[j - 1] = current;
  }
  K[i] = k;
}
int main() {
  int n, t;
  cin >> t;
  int K[t];
  vector<int> v[2];
  for (int i = 0; i < t; i++) {
    cin >> n;
    int arr[n];
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    cyclicSort(arr, v, n, K, i);
  }
  int p = 0;
  for (int i = 1; i < t; i++) {
    cout << K[i] << endl;
    for (int j = 0; j < K[i]; j++) {
      cout << v[0][j + p] << " " << v[1][j + p] << " " << 1 << endl;
    }
    p += K[i];
  }
  return 0;
}
