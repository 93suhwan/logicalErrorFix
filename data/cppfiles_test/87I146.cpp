#include <bits/stdc++.h>
using namespace std;
vector<string> tokenizer(string str, char ch) {
  std::istringstream var((str));
  vector<string> v;
  string t;
  while (getline((var), t, (ch))) {
    v.push_back(t);
  }
  return v;
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}
void fastInOut() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void setInOut() {}
void showTime(clock_t &startTime, clock_t &endTime) {}
void myCode() {
  long long int testCases;
  cin >> testCases;
  for (long long int tc = (1); tc < (testCases + 1); tc++) {
    long long int res = 0;
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (int z = (0); z < (arr.size()); z++) cin >> arr[z];
    res = *max_element(arr.begin(), arr.end()) -
          (max_element(arr.begin(), arr.end()) - arr.begin() + 1);
    cout << res << "\n";
  }
}
int main(int argc, char const *argv[]) {
  clock_t startTime = clock();
  fastInOut();
  setInOut();
  myCode();
  clock_t endTime = clock();
  showTime(startTime, endTime);
  return 0;
}
