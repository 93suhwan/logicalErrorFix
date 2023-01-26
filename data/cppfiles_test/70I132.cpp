#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
#define kuramaa ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
#define br break
#define pb push_back
#define pf push_front
#define len length()
#define ins insert
#define ff first
#define ss second
#define setpr(pr) fixed<<setprecision(pr)
#define cyes cout<<"Yes\n"
#define cno cout<<"No\n"
#define ndl cout<<"\n"
#define ctmp cout<<"Naruto\n"
#define mod 1000000009
#define M 1073741824
#define pr pair<int,int>
#define endl "\n"
 
int gcd(int a, int b)
{
    if(b==0)    return a;
    else        return gcd(b,a%b);
}
 
void show_vec(vector<int> &v ,int n)
{
    for(int i=0;i<n;i++)  cout<<v[i]<<" ";ndl;
}
 
void inp_vec(vector<int> &v,int n)
{
    for(int i=0;i<n;i++)     cin>>v[i];    
}
 
bool check_prime(int n)
{
    if(n<=1)    return false;
    if(n<4)     return true;
    
    if(n%2==0 || n%3==0)    return false;
    
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n%(i+2)==0)    return false;
    }
    
    return true;
}

void solve()
{
    string s,t="";cin>>s;
    unordered_map<char,int> m,mp;
    int i,j,n=s.len,k;
    
    for(i=s.len-1;i>=0;i--)
    {
        if(m.count(s[i]))       continue;
        m[s[i]]=i;
        t+=s[i];
    }
    
    reverse(t.begin(),t.end());
    string ans="";
    // cout<<t<<endl;
    
    i=0;
    while(i<s.len && mp.size()<m.size())
    {
        ans+=s[i];
        mp[s[i]]++;
        i++;
    }
    
    int y=i;
    
    string temp="";
    for(i=0;i<ans.len;i++)
    {
        if(ans[i]==t[0])    continue;
        temp+=ans[i];
    }
    
    // cout<<temp<<" "<<ans<<endl;
    
    if(temp.len==0)
    {
        cout<<s<<" "<<t[0]<<endl;
        return;
    }
    
    int low=y;
    // cout<<low<<endl;
    vector<int> v;
    while(low<s.len)
    {
        j=0;k=low;
        for(j=0;j<temp.len;j++)
        {
            if(k==s.len || temp[j]!=s[k])   break;
            k++;
        }
        
        if(j==temp.len)    v.pb(low);
        if(s[low]!=t[0])
        temp+=s[low];
        low++;
    }
    
    if(v.size()==0)
    {
        cout<<"-1\n";
        return;
    }
    
    ans="";low=0;
    for(j=0;j<v.size();j++)
    {
        while(low<v[j])
        {
            ans+=s[low];
            low++;
        }
        
        string com=ans,tans=ans;
        i=0;
        
        for(i=0;i<t.len;i++)
        {
            string tt="";
            for(j=0;j<tans.len;j++)
            {
                if(tans[j]==t[i])   continue;
                tt+=tans[j];
            }
            com+=tt;tans=tt;
        }
        
        if(com==s)
        {
            cout<<ans<<" "<<t<<endl;
            return;
        }
    }
    cout<<"-1\n";
    
}
 
signed main() 
{    
    kuramaa;
    int t=1;cin>>t;
    while(t--)  solve();
    return 0;
}