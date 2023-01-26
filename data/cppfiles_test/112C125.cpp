#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int test;
  cin >> test;
  while (test--) {
    long long int ar[3], m;
    for (int i = 0; i < 3; i++) cin >> ar[i];
    cin >> m;
    sort(ar, ar + 3);
    if ((ar[0] + ar[1] < ar[2] - 1) && (m < (ar[2] - ar[1] - ar[0]) - 1))
      cout << "NO";
    else if (m > (ar[0] - 1 + ar[1] - 1 + ar[2] - 1))
      cout << "NO";
    else
      cout << "YES";
    cout << endl;
  }
  return 0;
}
