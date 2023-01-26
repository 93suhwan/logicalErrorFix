#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second 
#define pb push_back
#define mp make_pair
#define trash trash
#define ALL(x) x.begin(),x.end()
const int oo=1e9;
const int Mod=1e9+7;
const long long OO=1e18;
const int N=1e3+5;
void file()
{
    if(fopen("trash.inp", "r"))
        freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
      // else freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
}
int n, a[N];
int cal(int x)
{
  return x*(x-1)/2;
}
map<long long,int>num;
set<long long>S;
void in()
{
   cin >> n;
   int res = 0, count = 0;
   stack<int>s;
   for(int i=1; i<=n; i++)
    {
      cin >> a[i];
      if(i%2)s.push(a[i]), count += a[i];
      else
      {
        int dong = a[i];
        int adn = dong;
        int arn = count;
        while(s.size() && dong>0)
        {
          int x = s.top();s.pop();
          if(x < dong) 
          {
            res += x;
            vector<int>vc;
            vc.clear();
            for(auto it=S.begin(); it!=S.end(); it++)
            {
              int t = (*it);
              if(t>count-x+1)
              {
                res += cal(num[t]);
                num[t] = 0, vc.pb(t);
              }
            }
            for(int t:vc)S.erase(t);
            num[count-x+1]++;
            S.insert(count-x+1);
            count-=x;
            dong-=x;
          }
          else if(x>dong)
          {
            res += dong;
            x -= dong;
            vector<int>vc;
            vc.clear();
            for(auto it=S.begin(); it!=S.end(); it++)
            {
              int t = (*it);
              if(t>count-dong+1)res += cal(num[t]), num[t] = 0, vc.pb(t);
            }
            for(int t:vc)S.erase(t);
            num[count-dong+1]++;
            S.insert(count-dong+1);
            count-=dong;
            dong = 0;
            s.push(x);
          }
          else
          {
            res += x;
            num[max(1LL,count-x+1)]++;
            S.insert(max(1LL,count-x+1));
            count-=x;
            dong-=x;
          }
        }
        if(arn < adn)
        {
          for(auto it=S.begin(); it!=S.end(); it++)
            {
              int t = (*it);
              if(it == S.begin())res += cal(num[t]);
              num[t] = 0;
            }
          S.clear();
        }
      } 
    }
    for(auto it=S.begin(); it!=S.end(); it++)
            {
              int t = (*it);
              if(t>0)res += cal(num[t]);
            }
  cout << res ;
}
///////////////////1112<3/////////////////
void solve()
{

}
///////////////////1112<3/////////////////
 main()
{
    file();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
      in();
      solve();
}
