#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define test(t)   \
int t;  \
cin>>t;  \
while(t--)  
int main()
{
    test(t)
    {
        ll in=0;int n,m;cin>>n>>m;
        ll a[n][m]={0};
        ll b[n][m]={0};
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                b[i][j]=2;
            }
        map<ll,ll>ma;map<ll,ll>mb,mc;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cin>>a[i][j],ma[a[i][j]]++,mb[a[i][j]]++;
        }
       // cout<<ma.size()<<endl;
        int left=m;
        //cout<<m<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   int s=0,range=0;
                //cout<<"loop"<<endl;
                int row=0,col=0,left=m;
                for(auto &v:ma)
                {
                   if(v.second>left)
                   {
                       if(v.first==a[i][j])
                       {
                          range=left;
                       }
                       if((v.second-left)>m)
                       row+=(v.second-left)/m;
                       else
                       row++;
                       left=m-(v.second-left)%m;
                   }
                   else if(v.second==left)
                   {
                       left=0;
                   }
                   else
                   {
                       left-=v.second;
                   }
                   if(v.first==a[i][j])
                   {
                       if(left==m)left=0;
                       col=m-left;
                       break;
                   }
                    
                }
                //cout<<left<<endl;  cout<<col<<endl;
                //col--;
                if(range>mc[a[i][j]]){
                ll temp=mb[a[i][j]];
                mb[a[i][j]]--;
                while(temp--)
                {
                    if(col==0)
                    {
                        row--;
                        col=m-1;
                    }
                    else
                    col--;
                }}
                else
                {
                     ll temp=mc[a[i][j]];
                
                while(temp--)
                {
                    if(col==0)
                    {
                        row--;
                        col=m-1;
                    }
                    else
                    col--;}
                    
                }
                mc[a[i][j]]++;
                //col--;
                cout<<"row "<<row<<" "<<"col "<<col<<endl;
                // cout<<b[row][col]<<endl;
                for(int k=0;k<col;k++)
                {
                    if(b[row][k]==1)in++;
                }
                //cout<<"in"<<in<<endl;
               
                b[row][col]=1;
                
                // for(int k=0;k<m;k++)
                // cout<<b[row][k]<<" ";
                //  cout<<endl;
            }}
        // cout<<n<<endl;
            // for(int i=0;i<n;i++)
            // {
            //     for(int j=0;j<m;j++)
            //     cout<<b[i][j]<<" ";
            //     cout<<endl;
            // }
        cout<<in<<endl;
    }
}

// cout<<row<<endl;
            //  int row=0;
            //     for(auto &v:ma)
            //     {
            //       if(v.second>left)
            //       {
            //           if((v.second-left)>m)
            //           row+=(v.second-left)/m;
            //           else
            //           row++;
            //           left=m-(v.second-left)%m;
            //       }
            //       else if(v.second==left)
            //       {
            //           left=0;
            //       }
            //       else
            //       {
            //           left-=v.second;
            //       }
            //     //   if(v.first==a[i][j])
            //     //   {
            //     //       if(left==m)col=0;
            //     //       else col=m-left;
            //     //       break;
            //     //   
            //     if(left==m) left=0;
            //     cout<<row<<" "<<m-left-1<<endl;
            //       // cout<<row<<endl;
            //             }
                //cout<<mb[a[i][j]]<<endl;