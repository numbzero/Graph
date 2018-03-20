#ifndef GRAPH_H
# define GRAPH_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	allocate_mem(int ***arr, int n, int m);
void	deallocate_mem(int ***arr, int n);
int		countEdges(int	**AdjM, int vertice);
void	adjMatPrint(int **AdjM, int vertice);
void	fromAdjMtoIncM(int **AdjM, int vertice);
void	fromIncMtoAdjM(int **IncM, int vertice, int edge);
void	fromAdjMtoAdjL(int **AdjM, int vertice);
void	fromIncMtoAdjL(int **IncM, int vertice, int edge);

#endif