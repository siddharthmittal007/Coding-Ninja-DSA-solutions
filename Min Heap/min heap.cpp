#include <bits/stdc++.h> 

void push_to_minheap(vector<int> &A,int key)
{
    A.push_back(key);   // Adding element at end of heap
    
    // Sifting up 
    int i=A.size()-1;
    while(i>0)
    {
        int parent=(i-1)/2;
        if(A[i]<A[parent])
        {
            swap(A[i],A[parent]);
            i=parent;
        }
        else
        {
            break;
        }
    }
}

void min_heapify(vector<int> &A,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    
    int smallest=i;
    if(left<A.size() && A[left]<A[smallest])
    {
        smallest=left;
    }
    if(right<A.size() && A[right]<A[smallest])
    {
        smallest=right;
    }

    if(i!=smallest)
    {
        swap(A[i],A[smallest]);
        min_heapify(A,smallest);
    }   
}

int pop_from_minheap(vector<int> &A)
{
    if(A.size()==0)
    {
        return(-1);     // Heap empty
    }

    int temp=A[0];      // Storing copy of 'min' element
    
    A[0]=A[A.size()-1]; // Rreplacing by last element
    A.pop_back();       // and popping last element

    min_heapify(A,0);   // Restore heap
    
    return(temp);       // Return 'min'
}


vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;    // Vector storing answer to queries
    
    vector<int> heap;   // Vector to hold min heap
    
    // Processing queries
    for(int i=0;i<q.size();i++)
    {
        if(q[i][0]==0)  // Push
        {
            push_to_minheap(heap,q[i][1]);
        }
        else            // Pop
        {
            ans.push_back(pop_from_minheap(heap));
        }
    }

    return(ans);
}

