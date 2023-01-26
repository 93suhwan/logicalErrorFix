#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long M = 1e9 + 7;
template <typename T>
void print(string text, vector<T> const &v = {}) {
  cout << text << ": ";
  for (const auto &e : v) cout << e << ' ';
  cout << '\n';
}
long long find_index(long long p, long long j, vector<long long> &a) {
  long long n = a.size();
  while ((j < n) && (a[j] <= p)) j++;
  return j - 1;
}
long long summation(long long n) { return (n * (n + 1)) / 2; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long long n;
    cin >> n;
    if (n == 0) {
      cout << -1 << " " << 1 << endl;
    } else {
      cout << -(n - 1) << " " << n << endl;
    }
  }
  return 0;
}
