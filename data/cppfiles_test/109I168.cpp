#include <bits/stdc++.h>
using namespace std;
void show(vector<int> A) {
  for (int i = 0; i < A.size(); i++) cout << A[i] << " ";
  cout << endl;
}
void input(vector<long long int> &A) {
  for (int i = 0; i < A.size(); i++) cin >> A[i];
}
int vectorSum(vector<int> A) {
  int sum = 0;
  for (int i = 0; i < A.size(); i++) sum += A[i];
  return sum;
}
void testCase() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1 || n == 2) {
    cout << s[0] - '0';
    if (n == 2) cout << s[1] - '0';
    return;
  }
  if (n == 3) {
    int temp = (s[n - 1] - '0') + (s[0] - '0');
    int temp2 = (s[1] - '0') * 10;
    temp = temp2 + temp;
    if (s[0] == '0')
      cout << temp;
    else
      cout << temp + 1;
    return;
  }
  int count = 0;
  for (int i = 0; i < n - 2; i++) {
    if (s[i] != '0') count++;
    count += s[i] - '0';
  }
  count += s[n - 1] - '0';
  if (s[n - 2] != '0') count += (s[n - 2] - '0' + 1);
  cout << count;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    testCase();
    cout << "\n";
  }
}
