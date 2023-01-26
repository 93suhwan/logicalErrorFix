#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int checkPrime(int n) {
  int c = 0;
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) c++;
    if (c == 1) return 0;
  }
  if (c == 0) return 1;
  return 0;
}
void solve() {
  long long T = 1;
  cin >> T;
  while (T--) {
    long long k;
    cin >> k;
    string n, n1;
    cin >> n;
    n1 = n;
    long long flag = 0, n2 = 0;
    while (n2 < k) {
      char d = n[n2];
      if (d == '1' || checkPrime((int)(d - 48)) == 0) {
        cout << "1\n" << (int)(d - 48) << "\n";
        flag = 1;
        break;
      }
      n2++;
    }
    if (flag == 1) {
      continue;
    }
    long long arr[] = {22, 25, 27, 32, 33, 35, 39, 52,
                       55, 57, 72, 75, 77, 92, 95, 99};
    for (long long int i = 0; i < (long long int)(k - 1); i++) {
      for (long long int ii = i + 1; ii < (long long int)(k); ii++) {
        int t1 = int(n[i] - 48);
        int t2 = int(n[ii] - 48);
        int t3 = t1 * 10 + t2;
        for (long long int j = 0; j < (long long int)(15); j++) {
          if (t3 == arr[j]) {
            cout << "2\n" << t3 << "\n";
            flag = 1;
            break;
          }
        }
        if (flag == 1) break;
      }
      if (flag == 1) break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
