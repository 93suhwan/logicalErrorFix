#include <bits/stdc++.h>
using namespace std;
int n, x;
long long m = 1;
long long arr[200005];
int main() {
  arr[2] = 1;
  for (long long i = 3; i <= 200001; i++) {
    m *= i;
    m %= 1000000007;
    arr[i] = m;
  }
  cin >> n;
  while (n--) {
    cin >> x;
    cout << arr[x * 2] << '\n';
  }
}
