#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int n1, long long int n2) {
  if (n2 != 0)
    return gcd(n2, n1 % n2);
  else
    return n1;
}
struct boom {
  int arr[5];
  int ind;
};
bool compare(boom a, boom b) {
  long long int j, c = 0;
  for (j = 0; j < 5; j++) {
    if (a.arr[j] > b.arr[j]) c++;
  }
  if (c >= 3) {
    return true;
  }
  return false;
}
const long long int bg = 998244353;
vector<vector<long long int> > master;
void gen(long long int i, vector<long long int> vec) {
  if (i == (10)) {
    master.push_back(vec);
    return;
  }
  vec.push_back(0);
  gen(i + 1, vec);
  vec[vec.size() - 1] = 1;
  gen(i + 1, vec);
  vec[vec.size() - 1] = 2;
  gen(i + 1, vec);
}
void solve() {
  long long int i, j, n;
  cin >> n;
  long long int arr[n];
  set<long long int> set1;
  vector<long long int> vec;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < 0) arr[i] = -arr[i];
    set1.insert(arr[i]);
    if (set1.find(arr[i]) != set1.end()) vec.push_back(arr[i]);
  }
  if ((n > (set1.size())) || (set1.size() == 1)) {
    cout << "YES" << endl;
    return;
  }
  if (n == 2) {
    if (set1.size() == 2) {
      cout << "NO" << endl;
      return;
    } else {
      cout << "YES" << endl;
      return;
    }
  }
  for (i = 0; i < (master.size()); i++) {
    for (long long int fin = 0; fin < (vec.size()); fin++) {
      long long int k = 0;
      for (j = 0; j < (vec.size()); j++) {
        if (j == fin) continue;
        if (master[i][j] == 1)
          k += vec[j];
        else if (master[i][j] == 2)
          k -= vec[j];
      }
      if (k == vec[fin]) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<long long int> emp;
  gen(0, emp);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
