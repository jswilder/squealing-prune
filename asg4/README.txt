Jeremy Wilder
Asg 4

Running times -

	Constructor - O( n^2 )

		because the largest amount of work was finding the smallest value, where
		it searches through the entire array, almost everything else seems to be a
		constant time. The one part that isn't is where I manipulate the array, but
		I think that takes time O( n ) and therefore wouldn't affect the overall runtime
		in the grand scheme of things

	Dump - O( n )

		it is proportional to the number of nodes stored, which is size-1 

	Compare - O( n^2 )

		it compares every node against each other, n nodes compared against n nodes
		= n*n or n^2

	Destructor - O( n )

		because it would take time proportional to the number of nodes in the vector
		to delete the memory.
