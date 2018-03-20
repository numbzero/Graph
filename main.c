// Graphs - M.A , M.I, L.A

#include "graph.h"

int	main()
{
	int	vertice;
	int	edge;
	int	**AdjM;
	int	**IncM;

	AdjM = NULL;
	IncM = NULL;

	printf("[+]Number of vertiges - ");
	scanf("%d", &vertice);
	printf("\nNumber of edges - ");
	scanf("%d", &edge);
	
	// Adjacency matrix 
	// Allocate mem for adjacency matrix 
	printf("[+]Allocating memory\n");
	allocate_mem(&AdjM, vertice, vertice);
	printf("[+]Memory allocated!\n");
	
	// Introducing A.M. 
	printf("[*]Introducing Adjency Matrix\n");
	for (int i = 0; i < vertice; i++)
		for (int j = 0; j < vertice; j++) {
			printf("[%d][%d] = ", i + 1, j + 1);
			scanf("%d", &AdjM[i][j]);
			printf("\n");
		}
	// Printing A.M. 
	adjMatPrint(AdjM, vertice);
	printf("\n[!]Edges are %d\n", countEdges(AdjM, vertice));

	// Try to transform from A.M to I.M
	printf("[!]\nTransforming from A.M to I.M.\n");
	fromAdjMtoIncM(AdjM,vertice);

	// Try to transform from A.M to A.L.
	printf("\n[!]Transforming from A.M. to A.L.\n");
	fromAdjMtoAdjL(AdjM, vertice);
 

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
	printf("\n[!]Transforming from I.M to A.M\n");
	fromIncMtoAdjM(IncM,vertice,edge);

	//Try to transform from M.I to L.A.
	printf("\n[!]Transforming from M.I to L.A\n");
	fromIncMtoAdjL(IncM, vertice, edge);


	deallocate_mem(&AdjM, vertice);
	deallocate_mem(&IncM, edge);
	return (0);
}