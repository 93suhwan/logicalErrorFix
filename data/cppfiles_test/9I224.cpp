#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define  fast()      ios :: sync_with_stdio(false); cin.tie(0);
#define  ll             long long int
#define  ull            unsigned long long int
#define vl              vector<long long>
#define vc              vector<char>
#define vs              vector<string>
#define vp              vector< pair<ll,ll> >
#define sl              set<long long>
#define sc              set<char>
#define sts             stack<string>
#define max_3(a,b,c)    max(a, max(b,c))
#define max_4(a,b,c,d)  max(a,max(b,max(c,d)))
#define min_3(a,b,c)    min(a, min(b,c))
#define min_4(a,b,c,d)  min(a,min(b,min(c,d)))
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a*b)/gcd(a,b)
#define pi              2*acos(0.0)
#define N               900006
#define      mnn                 10000000000000
#define      mxx                 -10000000000000
#define in              1234567890;
int M=1000000007;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

map<char,ll>mp,mk;
set<char> s1,s2;
//vector<string> v,w;
vl w1,w2,w3,v,w;
ll m,n,d,i,j,k,l,r,x,t,y,u,e,g,mn,mx,z,c,f;
string s,q,p;
char ch,ck;
/*int check_prime(int a)
{
   int c;

   for ( c = 2 ; c <= a - 1 ; c++ )
   {
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}*/
int main()
{
    fast()
    cin>>t;
    ll h;
    while(t--)
    {
        c=0,d=0,e=0,f=0,x=0;
        cin>>s;
        n=s.size();
        e=n;
        p="";
        q="";
        for(i=0; i<n; i++)
        {
            mp[s[i]]++;
            s1.insert(s[i]);
            f=max(f,mp[s[i]]);
        }
        for(auto i:s1){
            v.push_back(mp[i]);
        }
        sort(v.rbegin(),v.rend());
        for(i=0;i<v.size();i++){
            if(e>0)
            {d=min(v[i],max(e-v[i],0ll));
            c+=d;
            e-=2*d;}
            else break;
        }
        if(c==0&&n>1) c=1;
        cout<<c;
        cout<<"\n";
        mp.clear();
        s1.clear();
        v.clear();
    }
}
