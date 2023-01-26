#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    int final = 1e9 + 7;
    long long n, m;
    cin >> n >> m;
    int peep = 0;
    for (int i = 30; i >= 0; i--) {
      if (((m & (1 << i))) && ((n & (1 << i)))) {
        continue;
      } else if ((n & (1 << i))) {
        final = min(peep, final);
        break;
      } else if ((m & (1 << i))) {
        peep += (1 << i);
        continue;
      } else {
        final = min(peep + (1 << i), final);
        continue;
      }
    }
    cout << final << endl;
  }
  return 0;
}
