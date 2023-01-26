#include <bits/stdc++.h>
using namespace std;
void sol() {
  long long n;
  cin >> n;
  long long count = 1;
  long long mxn = 31623;
  for (long long i = 2; i < mxn; i++) {
    if ((i * i) <= n) count++;
    long long temp = i * i * i;
    long long temp2 = sqrt(temp);
    if (temp <= n && temp != (temp2 * temp2)) count++;
  }
  cout << count << "\n";
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    sol();
  }
}
