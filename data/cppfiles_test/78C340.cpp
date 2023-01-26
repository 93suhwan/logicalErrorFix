#include <bits/stdc++.h>
using namespace std;
void run_case() {
  int64_t l, r;
  cin >> l >> r;
  if ((r / 2 + 1) >= l)
    cout << r % (r / 2 + 1) << "\n";
  else
    cout << r % l << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int start = clock();
  int test_cases;
  test_cases = 1;
  cin >> test_cases;
  while (test_cases--) {
    run_case();
  }
  cerr << "[Finished in " << clock() - start << " ms]"
       << "\n";
  return 0;
}
