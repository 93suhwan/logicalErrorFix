#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Os")
void f(int i, vector<int>& vec) {
  if (vec[i] > vec[i + 1]) swap(vec[i], vec[i + 1]);
}
bool issorted(vector<int> vec) {
  int furtherst = 0;
  for (int i = 0; i < vec.size(); i++) {
    furtherst = max(furtherst, vec[i] - i - 1);
  }
  return (furtherst == 0);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& t : vec) cin >> t;
    int i = 0;
    for (; !issorted(vec);) {
      i++;
      if (i % 2)
        for (int j = 0; j < n - 1; j += 2) f(j, vec);
      else
        for (int j = 1; j < n; j += 2) f(j, vec);
    }
    cout << i << '\n';
  }
}
