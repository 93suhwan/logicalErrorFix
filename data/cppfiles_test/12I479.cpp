// دوام الحال من المحال
// They have knowledge ... But I have a beautiful mind
// Just a writer
// bleed on keyboard
/*
Don't stop when you are tired
.... Stop when you done.
*/
//make it sense
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double dbl;
#define sc(x)            scanf("%I64d",&x)
#define scc(x)           scanf("%c",&x)
ll n,m,t,a,b,x,y,k,c,z,d,e;
const int mod=1e9+7;
const int mxn=2e5+5;
const double by=3.141592653;
ll mn=1e18,mx=0;
ll arr[2000000],arr2[2000000];
ll finl[2000000];
string str,str2,str3;
string str4="abcdefghijklmnopqrstuvwxyz";
const double ebs=1e-8;
bool isprime(ll f)
{
    if(f%2==0&&f!=2||f<2)return 0;
    for(ll i=3;i*i<=f;i++)
    {
        if(f%i==0)return 0;
    }
    return 1;
}

ll fsp(ll fr, ll se) {
    if (se == 0)
        return 1;
    ll res = fsp(fr, se / 2);
    if (se & 1)
        return (res * res* fr);
        return (res * res);
}
/*
bool prime[(ll)1e7];
void seive()
{
   prime[0]=prime[1]=true;
   for(int i=2;i*i<=1e7;i++)
   {
       if(!prime[i])
       {
           for(int j=i*i;j<1e7;j+=i)
           {
             prime[j]=true;
           }
       }
   }

}
*/
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll max3(ll ma, ll mb ,ll mc)
{
    return max(ma,max(mc,mb));
}
ll min3(ll ma, ll mb ,ll mc)
{
    return min(ma,min(mc,mb));
}
bool valid(int r, int c)
{
    if(r>=0&&r<n&&c>=0&&c<n)return 1;
    return 0;
}
ll LCM(ll n1,ll n2)
{
    return (n1*n2)/__gcd(n1,n2);
}
/*
ll pcl[2000][2000];
void dopcl()
{
   pcl[0][0]=pcl[1][0]=pcl[1][1]=1;
   for(int i=2;i<=1000;i++)
   {
       for(int j=0;j<=i;j++)
       {
           if(j==0||j==i){pcl[i][j]=1;continue;}
           pcl[i][j]=(pcl[i-1][j-1]+pcl[i-1][j])%mod;
       }
   }
}
*/
char m1[200][200];
void clr()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)m1[i][j]='1';
    }
}
int main()
{
   ios_base::sync_with_stdio(0);
 //freopen("help.in","r", stdin);
	//freopen("output.txt","w", stdout);
    cin>>t;

   while(t--)
   {
       ll h;
        cin>>n>>m>>h;
        ll v=(n*m)/2-h;
        clr();
        int j=0;
        int cnt=0;
        while(v&&cnt<n/2)
        {
            for(int i=0;i<m;i++)
            {
                if(!v)break;
                v--;m1[j][i]='*';m1[j+1][i]='*';
            }
            j+=2;
            cnt++;
        }
        int r=0;
        while(h&&r<n)
        {
            for(int c=0;c<m;c++)
            {
                if(!h)break;
                if(m1[r][c]=='*')continue;
                if(c+1<=m-1){c++;h--;m1[r][c-1]='*';m1[r][c]='*';}
            }
            r++;
        }
        (!v&&!h)?cout<<"YES\n":cout<<"NO\n";

   }
   return 0;
}
