#include <bits/stdc++.h> 

// Utitlity function
void sortInsert(stack<int> &stack,int key)
{
	if(stack.empty() || stack.top()<=key)
	{
		stack.push(key);		// Position to insert 'key' found
	}
	else // (stack.top()>key)
	{
		// Save and pop out stack 'top'
		int temp=stack.top();
		stack.pop();

		sortInsert(stack,key);	// Explore rest of the stack for 
								// position of insertion
		
		stack.push(temp);		// Place back popped stack 'top'
	}
}

// Parent function
void sortStack(stack<int> &stack)
{
	// Base case(Stack bottom reached)
	if(stack.empty())
	{
		return;
	}
	
	// Save and pop out stack 'top' and,
	// recursively go to stack bottom
	int temp=stack.top();
	stack.pop();
	sortStack(stack);

	// Insert popped out stack 'top' at appropriate position
	// in sorted bottom stack
	sortInsert(stack,temp);
}


// T.C=O(N^2)	;	S.C=O(N)(RECURSION STACK)
