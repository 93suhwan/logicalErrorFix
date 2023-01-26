#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tc;
  cin >> tc;
  while (tc--) {
    long long int num, sum;
    cin >> num, sum;
    long long int check = (num / 2) + 1;
    long long int ans = floor(sum / check);
    cout << ans << endl;
  }
  return 0;
}
