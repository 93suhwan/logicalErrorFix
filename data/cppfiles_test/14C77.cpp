#include <bits/stdc++.h>
using namespace std;
int isSorted(long long int arr[], int n) {
  for (int(i) = (0); (i) < (n - 1); (i)++) {
    if (arr[i] > arr[i + 1]) return 0;
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  for (int(_) = (0); (_) < (t); (_)++) {
    int n;
    cin >> n;
    long long int arr[n];
    for (int(i) = (0); (i) < (n); (i)++) {
      cin >> arr[i];
    }
    pair<int, int> dr[n];
    int count = 0;
    for (int(i) = (0); (i) < (n); (i)++) {
      if (isSorted(arr, n)) break;
      int j = 0, r = n - i;
      for (int(k) = (1); (k) < (r); (k)++) {
        if (arr[k] > arr[j]) j = k;
      }
      if (j == r - 1) {
        continue;
      }
      long long int temp[j + 1];
      for (int(k) = (0); (k) < (j + 1); (k)++) temp[k] = arr[k];
      for (int(k) = (j + 1); (k) < (r); (k)++) arr[k - j - 1] = arr[k];
      for (int(k) = (0); (k) < (j + 1); (k)++) arr[k + r - j - 1] = temp[k];
      dr[count].first = j + 1;
      dr[count].second = r;
      count++;
    }
    cout << count << endl;
    for (int(i) = (0); (i) < (count); (i)++) {
      cout << "1 " << dr[i].second << ' ' << dr[i].first << endl;
    }
  }
  return 0;
}
