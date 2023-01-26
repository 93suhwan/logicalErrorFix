#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, count = 0;
    string str, rts;
    cin >> n >> str;
    rts = str;
    sort(rts.begin(), rts.end());
    for (long long i = 0; i < str.size(); i++) {
      if (str[i] != rts[i]) {
        count++;
      }
    }
    cout << count << "\n";
  }
  return 0;
}
