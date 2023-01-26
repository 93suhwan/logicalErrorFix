#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  for (long long testcase_no = 0; testcase_no < tt; testcase_no++) {
    int n;
    cin >> n;
    if (n % 10 == 9) {
      cout << n / 10 + 1 << "\n";
    } else {
      cout << n / 10 << "\n";
    }
  }
  return 0;
}
