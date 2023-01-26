#include <bits/stdc++.h>
using namespace std;
const double EPS = (double)1e-9;
const double pi = acos(-1);
const int mod = 1000000007;
const int N = (int)1e2;
long long arr[N + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int test;
  cin >> test;
  for (int t = 1; t < test + 1; t++) {
    int n;
    long long cnt = 0, in = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
      if (arr[i] > (i + 1 + in)) {
        long long x = arr[i] - (i + 1 + in);
        cnt += x;
        in += x;
      }
    }
    cout << cnt << "\n";
  }
}
