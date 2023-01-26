#include <bits/stdc++.h>
using namespace std;
void print(long long int* a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%lld ", a[i]);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  vector<pair<int, int>> v_p = {{1, 2}, {2, 3}};
  vector<pair<int, int>>::iterator it;
  for (it = v_p.begin(); it != v_p.end(); ++it) {
    cout << (*it).first << " " << (*it).second << endl;
  }
  return 0;
}
