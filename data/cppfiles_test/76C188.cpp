#include <bits/stdc++.h>
using namespace std;
long long int bin(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b & 1) return (a * bin((a * a) % 1000000007, b / 2)) % 1000000007;
  return (1 * bin((a * a) % 1000000007, b / 2)) % 1000000007;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  long long int arr[n + 1];
  arr[0] = 0, arr[1] = 1, arr[2] = 2;
  if (n >= 3) arr[3] = 5;
  int cnt = 8;
  for (int i = 4; i <= n; i++) {
    arr[i] = cnt;
    int te = 0;
    int curr = i;
    int val;
    for (int j = 2; j * j <= i; j++) {
      val = i / j;
      te = (te + ((curr - val) * arr[j - 1]) % m) % m;
      curr = val;
    }
    arr[i] = (arr[i] + te) % m;
    for (int j = 2; j <= val; j++) {
      arr[i] = (arr[i] + arr[i / j]) % m;
    }
    cnt = (cnt + arr[i]) % m;
  }
  cout << arr[n] << endl;
}
