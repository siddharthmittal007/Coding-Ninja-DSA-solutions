vector<int> Solution::prevSmaller(vector<int> &A) {
    // Monotonic increasing stack
    stack<int> s;
    
    // To store answer i.e. previous smaller elements
    vector<int> G(A.size(),-1);
    
    // Evaluating previous smaller element for each element
    for(int i=0;i<A.size();i++)
    {
        // Popping stack until 'top' lesser than current element
        while(!s.empty() && s.top()>=A[i])
        {
            s.pop();
        }
        
        //' Previous smaller element' at stack 'top'
        if(!s.empty())
        {
            G[i]=s.top();
        }
        
        s.push(A[i]);       // Pushing element to stack 'top'
    }
    
    return(G);          // Return list of previous smaller elements   
}

// T.C=O(N)  ;  S.C=O(N)
