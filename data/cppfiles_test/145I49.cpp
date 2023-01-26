#include<stdio.h>
#include<stdlib.h>

/*------------------General Sort---------------*/
#define MYCOPY(a,b,size) do { size_t __size = (size); char * __a = (a), *__b = (b); do { *__a = *__b; __a++; __b++; } while(--__size > 0); }while(0)

//extern void gip_merge_sort(void* p, size_t n, size_t size,int (*compar) (const void*, const void*));

void gip_merge_sort(void* p, size_t n, size_t size,int (*compar) (const void*, const void*)) {
	void internal_sorting(size_t l, size_t r) {
		if(r-l == 1 || r-l==0)
			return;

		size_t s,m,f,i;
		void* temp;

		s=l;m=(l+r)/2;f=r;

		internal_sorting(s, m);
		internal_sorting(m, r);

		temp = malloc((r-l)*size);

		for(i=l;i<r;i++) {
			if(s == (l+r)/2) {
				MYCOPY(temp+(i-l)*size, p+m*size, size);
				m++;
			}
			else if(m == r) {
				MYCOPY(temp+(i-l)*size, p+s*size, size);
				s++;
			}
			else if((*compar) (p+s*size, p+m*size) <= 0) {
				MYCOPY(temp+(i-l)*size, p+s*size, size);
				s++;
			}
			else {
				MYCOPY(temp+(i-l)*size, p+m*size, size);
				m++;
			}
		}
		for(i=l;i<r;i++)
			MYCOPY(p+i*size, temp+(i-l)*size, size);
		free(temp);
		return;
	}
	internal_sorting(0, n);
}
/*----------------END--------END-----END----*/

/*-----------------General Graph------------*/
struct connected_component {
	int id;
	int size;
};

struct Node {
	char state;
	int id;
	int children_size;
	int* children;
	struct Node* master;
	struct connected_component* cc;
};

struct Graph {
	int size;
	struct Node* verticies;
};

/*-------------------Helper Functions-----Declarations----------*/
struct Graph* get_new_graph(int n);
struct Node* master_recurse(struct Node* node);
struct Node* get_true_master_vertex(int i, struct Graph* g);
struct Node* get_true_master(struct Node* node);
void add_undir_edge(int l, int r, struct Graph* g);
void add_dir_edge(int parent, int child, struct Graph* g);
void connect_two_verticies(int a, int b, struct Graph* g);
void connect_two_nodes(struct Node* a, struct Node* b);
void destroy_graph(struct Graph** g_pointer);
void print_graph_cc(struct Graph* g);
void dsu_print(int root, struct Graph* g);
/**--------------------------------------------Implementations---*/

struct Graph* get_new_graph(int n) {
	int i;
	struct Graph* g = malloc(sizeof(struct Graph));
	g->size = n;
	g->verticies = malloc(g->size*sizeof(struct Node));
	for(i=0;i<g->size;i++) {
		g->verticies[i].id = i;
		g->verticies[i].children_size = 0;
		g->verticies[i].children = malloc(0);
		g->verticies[i].master = &(g->verticies[i]);
		g->verticies[i].cc = malloc(sizeof(struct connected_component));
		g->verticies[i].cc->id = i;
		g->verticies[i].cc->size = 1;
		g->verticies[i].state = 'n';
	}
	return g;
}

void dsu_print(int root, struct Graph* g) {
	if(g->verticies[root].state == 'v')
		return;
	printf("%d ", root);
	g->verticies[root].state = 'v';
	int i;
	for(i=0;i<g->verticies[root].children_size;i++)
		dsu_print(g->verticies[root].children[i], g);
}

void print_graph_cc(struct Graph* g) {
	printf("Printing Connected Components of Graph\n");
	int i;
	for(i=0;i<g->size;i++) {
		if(get_true_master_vertex(i,g) == &(g->verticies[i])) {
			printf("Connected Component Id :%d\t", g->verticies[i].cc->id);
			dsu_print(i, g);
			printf("\n");
		}
	}
	for(i=0;i<g->size;i++)
		g->verticies[i].state = 'n';
}

struct Node* get_true_master_vertex(int i, struct Graph* g) {
	return get_true_master(&(g->verticies[i]));
}

struct Node* get_true_master(struct Node* node) {
	// Sort of Dynamic memorization... To reduce time on search for masters.
	node->master = master_recurse(node);
	return node->master;
}

struct Node* master_recurse(struct Node* node) {
	if(node->master == node)
		return node;
	else
		return master_recurse(node->master);
}

void add_undir_edge(int l, int r, struct Graph* g) {
	add_dir_edge(l, r, g);
	add_dir_edge(r, l, g);
}

void add_dir_edge(int parent, int child, struct Graph* g) {
	g->verticies[parent].children_size++;
	g->verticies[parent].children = realloc(g->verticies[parent].children, g->verticies[parent].children_size*sizeof(int));
	g->verticies[parent].children[g->verticies[parent].children_size-1] = child;
	connect_two_verticies(parent, child, g);
}

void connect_two_verticies(int a, int b, struct Graph* g) {
	connect_two_nodes(&(g->verticies[a]), &(g->verticies[b]));
}

void connect_two_nodes(struct Node* a, struct Node* b) {
	struct Node* left = get_true_master(a);
	struct Node* right = get_true_master(b);
	if(left == right)
		return;
	left->cc->size = left->cc->size + right->cc->size;
	free(right->cc);
	right->cc=NULL;
	right->master = left;
	return;
}

void destroy_graph(struct Graph** g_pointer) {
	int i;
	for(i=0;i< (*g_pointer)->size;i++) {

		if ((*g_pointer)->verticies[i].children != NULL)
			free((*g_pointer)->verticies[i].children);

		if( (*g_pointer)->verticies[i].cc != NULL)
			free((*g_pointer)->verticies[i].cc);
	}

	free((*g_pointer)->verticies);
	free(*g_pointer);
	return;
}
/*------------END-----------END----------------END------------*/

struct mine {int id;int x;int y;int timer;};

/**----------------Sorting Helpers-----------------------**/
int compare_vals (int l, int r) {
	if(l<r)	return -1;
	else if(l>r) return 1;
	else return 0;
}

int int_compare(const void*a, const void* b) {
	const int* left = (int*)a;
	const int* right = (int*)b;
	return compare_vals(*left, *right);
}

int sort_mines_by_x (const void* a, const void* b) {
	int ans;
	const struct mine *left  = (struct mine*)a;
	const struct mine *right = (struct mine*)b;
	ans = compare_vals((*left).x, (*right).x);
	if(ans!=0)
		return ans;
	else
		return compare_vals((*left).y, (*right).y);
}

int sort_mines_by_y (const void* a, const void* b) {
	int ans;
	const struct mine *left  = (struct mine*)a;
	const struct mine *right = (struct mine*)b;
	ans = compare_vals((*left).y, (*right).y);
	if(ans!=0)
		return ans;
	else
		return compare_vals((*left).x, (*right).x);
}
/**------------------------------End------------------------**/
int abs(int x) {return x>=0? x : -1*x;}

void solve() {
	int n,k,i,j,st;
	int* sorted_times;
	struct mine *all_mines;
	struct Graph* g; struct Node* temp;
	
	scanf("%d %d", &n, &k);
	
	all_mines = malloc(n*sizeof(struct mine));
	g = get_new_graph(n);

	for(i=0;i<n;i++)
		scanf("%d %d %d", &all_mines[i].x, &all_mines[i].y, &all_mines[i].timer);
	for(i=0;i<n;i++) {
		all_mines[i].id = i;
		g->verticies[i].cc->id = all_mines[i].timer;
	}
	
	gip_merge_sort(all_mines, n, sizeof(struct mine), sort_mines_by_x);
	i=0;
	while(i<n) {
		j=i+1;
		while(j<n && all_mines[j].x == all_mines[i].x && (abs(all_mines[j].y - all_mines[i].y) <=k)) {
			add_undir_edge(all_mines[i].id, all_mines[j].id, g);
			i=j;
			j++;
		}
		i=j;
	}

	gip_merge_sort(all_mines, n, sizeof(struct mine),  sort_mines_by_y);
	i=0;
	while(i<n) {
		j=i+1;
		while(j<n && all_mines[j].y == all_mines[i].y && (abs(all_mines[j].x - all_mines[i].x) <=k)) {
			add_undir_edge(all_mines[i].id, all_mines[j].id, g);
			i=j;
			j++;
		}
		i=j;
	}

	for(i=0;i<n;i++) {
		temp = get_true_master_vertex(i,g);
		j = temp->cc->id;
		temp->cc->id = all_mines[i].timer < j ? all_mines[i].timer : j;
		temp=NULL;// Just in case.
	}

	free(all_mines);
	st = 0;
	sorted_times = malloc(0);
	for(i=0;i<n;i++) {
		if(g->verticies[i].master == &(g->verticies[i])) {
			st++;
			sorted_times = realloc(sorted_times, st*sizeof(int));
			sorted_times[st-1] = g->verticies[i].cc->id;
		}
	}
	destroy_graph(&g);

	gip_merge_sort(sorted_times, st, sizeof(int), int_compare);
	i=0;
	j=st-1;
	n=0;

	while(j>i) {
		while(i<st && sorted_times[i]<=n)
			i++;
		if(j>i) {
			if(sorted_times[j] <= n)
				break;
			else {
				j--;
				n++;
			}
		}
	}
	printf("%d\n", n);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}
