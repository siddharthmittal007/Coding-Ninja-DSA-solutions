#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> prev_smaller(n,-1);
    vector<int> next_smaller(n,n);

    // Obtaining previous smaller element indices
    stack<int> s1;
    for(int i=0;i<n;i++)
    {
        while(!s1.empty() && a[s1.top()]>=a[i])
        {
            s1.pop();
        }
        if(!s1.empty())
        {
            prev_smaller[i]=s1.top();
        }
        s1.push(i);
    }

    // Obtaining next smaller element indices
    stack<int> s2;
    for(int i=n-1;i>=0;i--)
    {
        while(!s2.empty() && a[s2.top()]>=a[i])
        {
            s2.pop();
        }
        if(!s2.empty())
        {
            next_smaller[i]=s2.top();
        }
        s2.push(i);
    }

    vector<int> ans(n,INT_MIN);     // Maximum of minimum of every window size

    // Updating for each element 'maximum of largest window it is minimum of'
    for(int i=0;i<n;i++)
    {
        int range=next_smaller[i]-prev_smaller[i]-1;
        ans[range-1]=max(ans[range-1],a[i]);
    }

    // Updating max of min of window sizes incase max of min of larger size
    // not represented in smaller window
    for(int i=n-1;i>0;i--)
    {
        ans[i-1]=max(ans[i-1],ans[i]);
    }

    return(ans);
}

// T.C=O(4*N)   ;   S.C=O(N)
// CONCEPT- PREVIOUS SMALLER AND NEXT SMALLER ELEMENT
