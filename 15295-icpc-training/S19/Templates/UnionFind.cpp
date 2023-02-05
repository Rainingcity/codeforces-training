/* UnionFind */
/* Path Compress */
/* REQUIRES: undirected graph */

/* fa[]: parent node in current union find tree */
/* void push (x, y): add an edge to the graph if possible, do nothing if not */
/* bool find (x, y): return true if x and y are in the same component */

int fa[];

int find_root(int x){
	if (fa[x]==x) return x;
	return (fa[x]=find_root(fa[x]));
}

void push (int x, int y){
	int fx = find_root(x);
	int fy = find_root(y);
	if (fx==fy) return;
	fa[fx] = fy;
	return;
}

bool find (int x, int y){
	return (find_root(x)==find_root(y));
}
