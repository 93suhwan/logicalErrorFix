#include <bits/stdc++.h>
using namespace std;
void run_case() {
  int l, r;
  cin >> l >> r;
  if ((r - l) == 0)
    cout << ("0") << "\n";
  else if ((r - l) == 1)
    cout << ("1") << "\n";
  else {
    int x = r / 2 + 1;
    cout << r % (max(l, x)) << "\n";
  }
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
