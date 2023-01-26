#include <bits/stdc++.h>
using namespace std;
auto start = std::chrono::system_clock::now();
inline void time() {
  std::chrono::time_point<std::chrono::system_clock> end;
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  cerr << "Time taken " << elapsed_seconds.count() * 1000 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long int tc = 1;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << endl;
    } else {
      if (n % 3 == 1)
        cout << n / 3 + 1 << " " << n / 3 << endl;
      else
        cout << n / 3 << " " << n / 3 + 1 << endl;
    }
  }
  time();
  return 0;
}
