#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REL_SIZE 1000
#define MAX_RANGE 1000

typedef struct {
	int first;
	int second;
} pair;
int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}
int get_domain(pair* t, int n , int* p)
{
    int x,y,f;
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        x = t[i].first;
        y = t[i].second;
        f = 0;
        for(int j = 0; j < m; j++)
            if(p[j] == x)
                f = 1;
        if(f == 0)
            p[m++] = x;
        f = 0;
        for(int j = 0; j < m; j++)
            if(p[j] == y)
                f = 1;
        if(f == 0)
            p[m++] = y;
    }
    qsort(p,m,sizeof(int),compare);
    return m;
};
// Add pair to existing relation if not already there
int add_relation (pair* t, int n, pair x)
{
    for(int i = 0; i < n; i++)
    {
        if( t[i].first == x.first && t[i].second == x.second)
            return 0;
    }
    t[n] = x;
    return 1;
};

// Case 1:
// The relation R is reflexive if xRx for every x in X
int is_reflexive(pair* t, int n)
{
    int p[2*n];
    int np = get_domain(t,n,p);
    int p2[np][2];
    for(int i = 0; i < np; i++)
    {
        p2[i][0] = p[i];
        p2[i][1] = 0;
    }
    for(int i = 0; i < np; i++)
        for(int j = 0; j < n; j++)
            if(t[j].first==p2[i][0] && t[j].second == p2[i][0])
                p2[i][1] = 1;
    for(int i = 0; i < np; i++)
        if(p2[i][1]==0)
            return 0;
    return 1;
};
// The relation R on the set X is called irreflexive
// if xRx is false for every x in X
int is_irreflexive(pair* t, int n)
{
    for(int i = 0; i < n; i++)
        if (t[i].first == t[i].second)
            return 0;
    return 1;
};
// A binary relation R over a set X is symmetric if:
// for all x, y in X xRy <=> yRx
int is_symmetric(pair* t, int n)
{
    int flag;
    for(int i = 0; i < n; i++)
    {
        flag = 0;
        for(int j = 0; j < n; j++)
            if(t[i].first == t[j].second && t[i].second == t[j].first)
                flag = 1;
        if (flag == 0)
            return 0;
    }
    return 1;
};
// A binary relation R over a set X is antisymmetric if:
// for all x,y in X if xRy and yRx then x=y
int is_antisymmetric(pair* t, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(t[i].first == t[j].second && t[i].second == t[j].first && t[i].first != t[i].second)
                return 0;
    return 1;
};
// A binary relation R over a set X is asymmetric if:
// for all x,y in X if at least one of xRy and yRx is false
int is_asymmetric(pair* t, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            if(t[i].first == t[j].second && t[i].second == t[j].first)
                return 0;
    }
    return 1;
};
// A homogeneous relation R on the set X is a transitive relation if:
// for all x, y, z in X, if xRy and yRz, then xRz
int is_transitive(pair* t, int n)
{
    int x,y,z,flag;
    for(int i = 0; i < n; i++)
    {
        x = t[i].first;
        y = t[i].second;
        for(int j = 0; j < n; j++)
        {
            if(t[j].first == y)
            {
                z = t[j].second;
                flag = 0;
                for(int k = 0; k < n; k++)
                    if(t[k].first == x && t[k].second == z)
                        flag = 1;
                if (flag == 0)
                    return 0;
            }
        }
    }
    return 1;
};

// Case 2:
// A partial order relation is a homogeneous relation that is
// reflexive, transitive, and antisymmetric
int is_partial_order(pair* t, int n)
{
    if ((is_reflexive(t,n) + is_transitive(t,n) + is_antisymmetric(t,n))==3)
        return 1;
    return 0;
};

// Relation R is connected if for each x, y in X:
// xRy or yRx (or both)
int is_connected(pair* t, int n)
{
    int p[2*n];
    int np = get_domain(t,n,p);
    int p2[np][2];
    int f,x,y,z;
    for(int i = 0; i < np; i++)
        p2[i][0] = p[i];
    for(int i = 0; i < np; i++)
    {
        for(int j = 0; j< np;j++)
            p2[j][1] = 0;
        x = p2[i][0];
        p2[i][1] = 1;
        for(int j = 0; j < np; j++)
        {
            y = p2[j][0];
            for(int k = 0; k < n; k++)
            {
                if((t[k].first == x && t[k].second == y)||(t[k].first == y && t[k].second == x))
                    p2[j][1] = 1;
            }
            if(p2[j][1]==0)
                return 0;
        }
    }
    return 1;
};
// A total order relation is a partial order relation that is connected
int is_total_order(pair* t, int n)
{
    if((is_partial_order(t,n)+is_connected(t,n))==2)
        return 1;
    return 0;
};
int find_max_elements(pair* t, int n, int* t2)
{
    int t3[2*n];
    int m = 0;
    int x,f;
    int np = get_domain(t,n,t3);
    for(int i = 0; i < np; i++)
    {
        x = t3[i];
        f = 0;
        for(int j = 0; j< n; j++)
            if(t[j].first == x && t[j].second != x)
                f = 1;
        if (f == 0)
            t2[m++]=x;
    }
    return m;
};
int find_min_elements(pair* t, int n, int* t2)
{
    int t3[2*n];
    int m = 0;
    int x,f;
    int np = get_domain(t,n,t3);
    for(int i = 0; i < np; i++)
    {
        x = t3[i];
        f = 0;
        for(int j = 0; j< n; j++)
            if((t[j].second == x) && (t[j].first != x))
                f = 1;
        if (f == 0)
            t2[m++]=x;
    }
    return m;
};


// Case 3:
int composition (pair* t, int n , pair* t1, int n1, pair* t2)
{
    int x,y,z;
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        x = t[i].first;
        y = t[i].second;
        for(int j = 0; j < n1; j++)
        {
            if(t1[j].first == y)
            {
                z = t1[j].second;
                pair nowapara;
                nowapara.first = x;
                nowapara.second = z;
                m+=add_relation(t2,m,nowapara);
            }
        }
    }
    return m;
};

int cmp (pair p1, pair p2) {
	if (p1.first == p2.first) return p1.second - p2.second;
	return p1.first - p2.first;
}

// Read number of pairs, n, and then n pairs of ints
int read_relation(pair* t)
{
    int a,b,n;
    scanf("%d",&n);
    pair nowapara;
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d",&a,&b);
        nowapara.first = a;
        nowapara.second = b;
        m+=add_relation(t,m,nowapara);
    }
    return m;
};

void print_int_array(int *array, int n) {
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(void) {
	int to_do;
	pair relation[MAX_REL_SIZE];
	pair relation_2[MAX_REL_SIZE];
	pair comp_relation[MAX_REL_SIZE];
	int domain[MAX_REL_SIZE];

	scanf("%d",&to_do);
	int size = read_relation(relation);
	int ordered, size_2, n_domain;

	switch (to_do) {
		case 1:
			printf("%d ", is_reflexive(relation, size));
			printf("%d ", is_irreflexive(relation, size));
			printf("%d ", is_symmetric(relation, size));
			printf("%d ", is_antisymmetric(relation, size));
			printf("%d ", is_asymmetric(relation, size));
			printf("%d\n", is_transitive(relation, size));
			break;
		case 2:
			ordered = is_partial_order(relation, size);
			n_domain = get_domain(relation, size, domain);
			printf("%d %d\n", ordered, is_total_order(relation, size));
			print_int_array(domain, n_domain);
			if (!ordered) break;
			int max_elements[MAX_REL_SIZE];
			int min_elements[MAX_REL_SIZE];
			int no_max_elements = find_max_elements(relation, size, max_elements);
			int no_min_elements = find_min_elements(relation, size, min_elements);
			print_int_array(max_elements, no_max_elements);
			print_int_array(min_elements, no_min_elements);
			break;
		case 3:
			size_2 = read_relation(relation_2);
			printf("%d\n", composition(relation, size,
			   relation_2, size_2, comp_relation));
			break;
		default:
			printf("NOTHING TO DO FOR %d\n", to_do);
			break;
	}
	return 0;
}
