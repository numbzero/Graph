// Graphs - M.A , M.I, L.A

#include "graph.h"

int	main()
{
	int	vertice;
	int	edge;
	int	**IncM;

	IncM = NULL;

	printf("[+]Number of vertiges - ");
	scanf("%d", &vertice);
	printf("\nNumber of edges - ");
	scanf("%d", &edge);

	// Incidense matrix 
	// Allocate mem for incidense matrix 
	printf("\n[+]Allocating memory\n");
	allocate_mem(&IncM, edge, vertice);
	printf("\n[+]Memory allocated\n");
	
	// Introducing I.M. 
	printf("[*Introducing Incidense Matrix\n");
	for (int i = 0; i < edge; i++) 
		for (int j = 0; j < vertice; j++) {
			printf("[%d][%d] = ", i + 1, j + 1);
			scanf("%d", &IncM[i][j]);
			printf("\n");
		}
	
	// Printing I.M 
	printf("[*]Printing Incidense Matrix\n");
	for (int i = 0; i < edge; i++) {
		for (int j = 0; j < vertice; j++)
			printf(" %d ", IncM[i][j]);
		printf("\n");
	}

	// Try to transforme from M.I. to M.A.
	printf("[!]Transforming from I.M to A.M\n");
	fromIncMtoAdjM(IncM,vertice,edge);

	//Try to transform from M.I to L.A.
	printf("[!]Transforming from M.I to L.A\n");
	fromIncMtoAdjL(IncM, vertice, edge);

	deallocate_mem(&IncM, edge);
	return (0);
}