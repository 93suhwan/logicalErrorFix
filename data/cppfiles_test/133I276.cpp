#include <bits/stdc++.h>
using namespace std;
struct sides {
  long long a;
  long long b;
  long long c;
};
struct Query {};
void printVec(vector<int> vec) {
  cout << '[';
  int n = vec.size();
  for (int i = 0; i < n - 1; i++) {
    cout << vec[i] << ",";
  }
  cout << vec[n - 1] << "]"
       << "\n";
}
vector<vector<int>> subArray(vector<int> A) {
  int n = A.size();
  int tot = 0;
  for (int i = 0; i < n; i++) {
    tot += A[i];
  }
  vector<vector<int>> subs;
  for (int i = 0; i < n; i++) {
    int pref = 0;
    for (int j = i; j < n; j++) {
      pref += A[j];
      int currSum = pref;
      int rest = tot - currSum;
      int count = n - (j - i + 1);
      if (currSum * count > rest * (j - i + 1)) {
        subs.push_back({i + 1, j + 1});
      }
    }
  }
  subs.push_back({1, n});
  sort(subs.begin(), subs.end());
  return subs;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n - 2; i++) {
      cin >> a[i];
    }
    if (n == 3) {
      cout << a[0] + "a"
           << "\n";
      continue;
    }
    string ans = "";
    ans += a[0][0];
    bool found = false;
    for (int i = 1; i < n - 2; i++) {
      string temp = a[i];
      string prev = a[i - 1];
      string missing;
      if (temp[0] != prev[1]) {
        ans += prev[1];
        found = true;
        continue;
      }
      ans += prev[1];
    }
    ans += a[n - 3];
    if (!found) {
      ans += 'a';
    }
    cout << ans << "\n";
  }
}
