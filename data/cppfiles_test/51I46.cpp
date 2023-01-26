#include <bits/stdc++.h>
using namespace std;
void printSums(long long N) {
  long long start = 1, end = 1;
  long long sum = 1;
  while (start <= N / 2) {
    if (sum < N) {
      end += 1;
      sum += end;
    } else if (sum > N) {
      sum -= start;
      start += 1;
    } else if (sum == N) {
      cout << start << " " << end;
      cout << "\n";
      return;
    }
  }
}
const long long N = 2e6 + 20, M2 = 1e18 + 1, M1 = -1e18 - 1;
long long a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1)
      cout << 0 << ' ' << 1 << '\n';
    else
      printSums(n);
  }
  return 0;
}
