class Solution 
{
public:
    int f(vector<int> &v)
    {
        int ans=2, cnt=2, n=v.size();
        sort(v.begin(),v.end());
        for(int x=1; x<n; x++)
        {
            if(v[x]==v[x-1]+1) cnt++;
            else
            {
                ans=max(ans,cnt);
                cnt=2;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) 
    {
        int a=min(f(hBars),f(vBars));
        return a*a;
    }
};
