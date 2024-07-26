#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	// Finding the possible celebrity
        int person=0;
        for(int i=1;i<n;i++)
        {
            if(knows(person,i))
            {
                person=i;
            }
        }
        
        // Verifying if person found is a celebrity
        for(int i=0;i<n;i++)
        {
            if(person!=i)
            {
                if(knows(person,i) || !knows(i,person))
                {
                    return(-1);
                }    
            }
        }
        
        return(person);
}

// T.C=O(N)	;	S.C=O(1)
// CALLS TO KNOWS() ARE 3*N
