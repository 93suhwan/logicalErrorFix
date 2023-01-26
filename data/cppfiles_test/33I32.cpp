#include <bits/stdc++.h>
using namespace std;
void debug(int arr[], int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "\n";
}
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  clock_t begin = clock();
  file_i_o();
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[100029];
    long long mul[100029] = {0};
    int j = 0;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] > 0) mul[j++] = arr[i] * arr[i - 1];
    }
    long long mx = -1;
    for (long long i = 0; i < j; i++) {
      if (mx < mul[i]) mx = mul[i];
    }
    cout << mx << "\n";
  }
  return 0;
}
