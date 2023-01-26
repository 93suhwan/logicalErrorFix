#include <bits/stdc++.h>
using namespace std;
void cyclicSort(int arr[], int n) {
  int k = 0;
  vector<int> v[2];
  for (int i = 1; i < n; i++) {
    bool b = false;
    int current = arr[i];
    int j = i - 1;
    while (arr[j] > current && j >= 0) {
      arr[j + 1] = arr[j];
      j--;
      b = true;
    }
    if (b) {
      v[0].push_back(j + 2);
      v[1].push_back(i + 1);
      k++;
    }
    arr[j + 1] = current;
  }
  cout << k << endl;
  for (int i = 0; i < k; i++) {
    cout << v[0][i] << " " << v[1][i] << " " << v[1][i] - v[0][i] << endl;
  }
}
int main() {
  int n = 0, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    int arr[n];
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    cyclicSort(arr, n);
  }
  return 0;
}
