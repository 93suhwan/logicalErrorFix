#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  long arr[10000];
  cin >> n;
  for (long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long polycrap[10000];
  long j = 1;
  for (long i = 0; i <= 10000; i++) {
    if (i % 3 != 0 && i % 10 != 3) {
      polycrap[j] = {i};
      j++;
    } else if (i % 3 == 0 && i % 10 == 3)
      continue;
  }
  for (long j = 0; j < n; j++) {
    cout << polycrap[arr[j]] << endl;
  }
  return 0;
}
