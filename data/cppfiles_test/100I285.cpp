#include<bits/stdc++.h>
using namespace std;
long long modder = 998244353;
long long fermats_little_theorem(long long number, long long power)
{
  if(power == 0)
  {return 1;}
  long long out = fermats_little_theorem(number, power / 2);
  out = out * out % modder;
  if(power % 2 == 1)
  {out = out * number % modder;}
  return out;
}
void processor()
{
  int n; cin >> n;
  map<int, int> hmap;
  set<int, greater<int>> uniques;
  int arr[n] = {};
  for(int i = 0; i < n; i++)
  {cin >> arr[i]; hmap[arr[i]]++; uniques.insert(arr[i]);}
  int mini = *min_element(arr, arr + n);
  int maxi = *max_element(arr, arr + n);
  long long answer = 1, modder = 998244353;
  for(int val : uniques)
  {
    if(val != mini && hmap[val - 1] == 0)
    {cout << 0 << endl; return;}
  }
  if(uniques.size() == 1)
  {
    for(int i = hmap[*uniques.begin()]; i > 1; i--)
    {answer *= i; answer %= modder;}
    cout << answer << endl;
    return;
  }
  long long fact = 1;
  for(int i = n; i > 1; i--)
  {fact *= i; fact %= modder;}
  if(hmap[maxi] > 1)
  {cout << fact << endl; return;}
  long long subtractor = 0, intermediate = 1;
  for(int i = 2; i <= n - 1 - hmap[maxi - 1]; i++)
  {intermediate *= i; intermediate %= modder;}
  long long removal = 1, intermediate2 = 1;
  for(int i = hmap[maxi - 1]; i > 0; i--)
  {intermediate2 *= i; intermediate2 %= modder;}
  subtractor = intermediate * intermediate2 % modder;
  for(int i = hmap[maxi - 1] + 1; i < n; i++)
  {
    intermediate2 *= fermats_little_theorem(removal++, modder - 2);
    intermediate2 %= modder;
    intermediate2 *= i; intermediate2 %= modder;
    subtractor += intermediate2 * intermediate % modder;
    subtractor %= modder;
  }
  cout << (fact - subtractor + modder) % modder << endl;
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int count, counter = 0;
  cin >> count;
  while(counter++ < count)
  {processor();}
  return 0;
}
//Written by Namit Shah (Eclecticity).
//Hack/Challenge this if you wish to salvage a few points off a destined-to-sink ship.
