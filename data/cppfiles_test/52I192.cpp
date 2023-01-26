#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long N;
    cin >> N;
    long long arr[N];
    for (long long i = 0; i < N; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + N);
    double sum = 0;
    for (long long i = 0; i < N - 1; i++) {
      sum += arr[i];
    }
    sum = sum / (N - 1);
    sum += arr[N - 1];
    cout << sum << endl;
  }
  return 0;
}
