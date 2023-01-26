#include <bits/stdc++.h>
using namespace std;
void test_case() {
  long long n, k;
  cin >> n >> k;
  long long comp = 1, count = 0;
  long long i = 1;
  while (comp < n) {
    if (i < k) {
      i = comp;
    }
    if (i >= k) {
      i = k;
      count += (n - comp) / k;
      if ((n - comp) % k != 0) count++;
      break;
    }
    comp += i;
    count++;
  }
  cout << count << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) test_case();
}
