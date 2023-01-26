#include<bits/stdc++.h>
// data types definition
#define int long long
#define pb push_back 
#define vi vector<int>
#define pq priority_queue<int>
#define minpq priority_queue<int,vector<int>,greater<int>>

// other useful defintions
const int MAX =1e9+7;
#define sp " "
#define all(x) x.begin(),x.end()
/* end of definition */

using namespace std;
int lcm(int a,int b)
{
    return a*b/(__gcd(a,b));
}

// function to check whether a given int is prime or not
bool is_prime(int n)
{   if(n==1||n==0)
    {
        return false;
    }
    if(n==2)
    {
        return true;
    }
    if(n%2==0)
    {
        return false;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

//function to check palindrome
// bool is_palindrome(string s)
// {
//     int l=0;
//     int r= (int )s.size()-1;
//     while(l<=r && s[l]==s[r])
//     {
//         l++;r--;
//     }
//     return l>r;
// }

int power(int a,int p)
{
    if(p==0)
    {
        return 1;
    }
    if(p%2!=0)
    {
        int z=power(a,p/2);
        int f= ((z%MAX)*(z%MAX))%MAX;
        return (f*(a%MAX))%MAX;
    }
    else
    {
        int z=power(a,p/2);
        int f= ((z%MAX)*(z%MAX))%MAX;
        return f;
 
    }
}


void func()
{
    int n;cin>>n;
    vi a(n);
    int sum=0;
    for(auto &i:a)
    {
        cin>>i;
        sum+=i;
    }
    int f= (n*(n+1))/2;
    if(sum%f!=0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        sum= sum/f;
        vi ans(n,0);
        for(int i=0;i+1<n;i++)
        {
            int dif= a[i+1]-a[i];
            int z= sum-dif;
            if(z>0 and z%n==0)
            {
                ans[i+1]=z/n;
            }
            else
            {
                cout<<"NO"<<endl;return;
            }
        }
        int val=0;
        for(auto &i:ans)
        {
            val+=i;
        }
        if(val==sum)
        {
            cout<<"NO"<<endl;return;
        }
        ans[0]=sum-val;
        cout<<"YES"<<endl;
        for(auto &i:ans)
        {
            cout<<i<<sp;
        }
        cout<<endl;
    }
    

}

int32_t  main()
{   
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
	    cin.tie(NULL);
	    cout.tie(0);
        
        int t=1;
        cin>>t;
        while(t--)
        {
            func();
            
            
        }
    
    return 0;
}