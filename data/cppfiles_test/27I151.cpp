/**So..a**/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define long long long int
#define B_ begin()
#define E_ end()
#define all(a) a.begin(), a.end()
#define NL_ "\n"
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define __lcm(a, b) (a/__gcd(a, b)*b)
#define size size()
#define length length()
#define empty empty()
typedef tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;
/**
*find_by_order(val)-> 0 indexed
order_of_key(index)-> 0 indexed
**/
#define CASE "Case "<<++tc<<": "
#define PI acos(-1)
#define EXP 10e-9
#define what_is(x) cerr << #x << " is " << x << endl;

template<typename item>
item abs(item i)
{
    if(i < 0) i= -i;
    return i;
}
long mod1 = 1000000000+7;
long mod2 = 1000000000+9;
template<class typea>
typea POW(typea b, typea p)
{
    typea res = 1;
    while(p)
    {
        if(p&1)
        {
            res*=b;
            res%=mod1;
        }
        b*=b;
        b%=mod1;


        p/=2;
    }
    return res;
}

int  tc =0;
#define ull unsigned long long int

#define maxn 2*100000+2


char s[100000+10];
char t[100000+10];

void solve()
{

   cin >> s+1>>t+1;
   string r;
   r +="#";
   int ss = strlen(s+1), tt = strlen(t+1);
   int par = 0;
   int last1=0;
   int id =1;
  for(int i=1; i<=ss; i++)
  {
      if(i%2==par)
      {
          if(id<=tt and t[id]==s[i])
          {
              id++, last1=i;
              par^=1;
          }
      }
  }
//  cout << id <<" "<<last1<<NL_;
  int last2 = 0;
  par = 1;
 int id2 = 1;
 for(int i=1; i<=ss; i++)
  {
      if(i%2==par)
      {
          if(id2<=tt and t[id2]==s[i])
          {
              id2++, last2=i;
              par^=1;
          }
      }
  }

  if(id>tt and (ss-last1)%2==0) cout <<"YES\n";
  else if(id2>tt and (ss-last2)%2==0) cout <<"NO\n";
  else cout <<"NO\n";



}
int main()
{
    FAST;
    int Test = 1;
    cin >> Test;
    while(Test--)
    {
        solve();
    }
    return 0;
}
