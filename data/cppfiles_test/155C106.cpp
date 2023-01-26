#include <bits/stdc++.h>
using namespace std;
void changeArr(vector<int> &input, int N, int x) {
  int newArray[N];
  copy(input.begin(), input.end(), newArray);
  sort(newArray, newArray + N);
  int i;
  map<int, int> ranks;
  int rank = x;
  for (int index = 0; index < N; index++) {
    int element = newArray[index];
    if (ranks[element] == 0) {
      ranks[element] = rank;
      rank++;
    }
  }
  for (int index = 0; index < N; index++) {
    int element = input[index];
    input[index] = ranks[input[index]];
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], ans[n];
    string s;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cin >> s;
    vector<int> v0, v1, c0, c1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        v0.push_back(i), c0.push_back(a[i]);
      else
        v1.push_back(i), c1.push_back(a[i]);
    }
    if (v1.size() != 0 && v0.size() != 0) {
      changeArr(c1, v1.size(), 1);
      changeArr(c0, v0.size(), 1);
      for (int i = 0; i < v0.size(); i++) {
        a[v0[i]] = c0[i];
      }
      for (int i = 0; i < v1.size(); i++) {
        a[v1[i]] = c1[i] + v0.size();
      }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
