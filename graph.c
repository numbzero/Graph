#include "graph.h"

void	allocate_mem(int ***arr, int n, int m)
{
	*arr = (int **)malloc(n * sizeof(int *));
	
	for(int i = 0; i < n; i++)
		(*arr)[i] = (int *)malloc(m * sizeof(int));
}

void	deallocate_mem(int ***arr, int n)
{
	for (int i = 0; i < n; i++)
		free((*arr)[i]);
	free(*arr);
}

int		countEdges(int	**AdjM, int vertice)
{
	int	Edge;

	Edge = 0;
	for (int i = 0; i < vertice; i++)
		for (int j = 0; j < vertice; j++)
			if (AdjM[i][j] > 0)
				Edge++;
	return (Edge);		
}

void	adjMatPrint(int **AdjM, int vertice)
{
	printf("[*]Printing Adjency Matrix\n");
	for (int i = 0; i < vertice; i++) {
		for (int j = 0; j < vertice; j++)
			printf(" %d ",AdjM[i][j]);
		printf("\n");
	}
}

void	fromAdjMtoIncM(int **AdjM, int vertice)
{
	for (int i = 0; i < vertice; i++)
	{
		for (int j = 0; j < vertice; j++)
		{
			/* Printing edge , how? somehow))*/
			if (AdjM[i][j] > 0)
			{
				int	v1 = i;
				int	v2 = j;
				for (int k = 0; k < vertice; k++)
				{
					if (k == v1)
						printf(" -1 ");
					else if (k == v2)
						printf(" 1 ");
					else
						printf(" 0 ");
				}
				printf("\n");
			}

		}
	}
}

void	fromIncMtoAdjM(int **IncM, int vertice, int edge)
{
	int *tmpM;

	tmpM = (int *)malloc(vertice * sizeof(int));

	for (int j = 0; j < vertice; j++)
	{
		memset(tmpM, 0, vertice * sizeof(int));
		for (int i = 0; i < edge; i++)
		{
			if (IncM[i][j] == -1)
			{
				int k = i;
				for (int l = 0; l < vertice; l++)
				{
					if (IncM[k][l] > 0)
						tmpM[l] = IncM[k][l];
				}
			}
			
		}
		for (int x = 0; x < vertice; x++)
			printf(" %d ", tmpM[x]);
		printf("\n");
	}
	free(tmpM);
}

void	fromAdjMtoAdjL(int **AdjM, int vertice)
{
	for (int i = 0; i < vertice; i++)
	{
		printf("%d |", i + 1);
		for (int j = 0; j < vertice; j++)
		{
			if (*(*(AdjM + i) + j) == 1)
				printf(" %d ", j + 1);
		}
		printf(" 0\n");
	}
}

void	fromIncMtoAdjL(int **IncM, int vertice, int edge)
{
	for (int j = 0; j < vertice; j++)
	{
		printf("%d | ", j + 1);
		for (int i = 0; i < edge; i++)
		{
			if (IncM[i][j] == -1)
			{
				int k = i;
				for (int l = 0; l < vertice; l++)
				{
					if (IncM[k][l] > 0)
						printf(" %d ", l + 1);
				}
			}
			
		}
		printf(" 0\n");
	}
}