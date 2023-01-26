#include <bits/stdc++.h>
using namespace std;
int toBinary(long long int n) {
  int Binary[64];
  int i = 0;
  while (n > 0) {
    Binary[i] = n % 2;
    i++;
    n = n / 2;
  }
  int count = 0;
  for (int j = i - 1; j >= 0; j--) {
    if (Binary[j] != 0) {
      count += 1;
    }
  }
  return count;
}
bool isSorted(long long int arr[], int n) {
  bool result = true;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      result = false;
      break;
    }
  }
  return result;
}
int main() {
  long long int t;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    cout << n << "\n";
    for (long long int p = n - 1; p >= 0; p--) {
      long long int max_index = 0;
      for (long long int j = 0; j <= p; j++) {
        if (arr[j] > arr[max_index]) {
          max_index = j;
        }
      }
      long long int d = (max_index + 1) % (p + 1);
      cout << "1 " << p + 1 << " " << d << "\n";
    }
  }
}
