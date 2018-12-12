
#include <stdio.h>

#define MAX_N 300000
#define MAX_R 1000000000
#define MAX_X 1000000000

int solve();
int N, Q;   // N : # of circle , Q : # of disc 
//int R[MAX_N];
int X[MAX_N];

typedef struct _{
    int r;  /* Radius */
    int p;  /* Position */ 
    int f;     
} Hole;

Hole H[MAX_N];


int main(void)
{
	int test_case;
	int T;
        int r;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= 3; ++test_case)
	{
            scanf("%d %d", &N, &Q);
            
            for (int i = 0; i < N; i ++) {
                scanf("%d", &(H[i].r));                
                H[i].p = i + 1;
            }
            for (int i = 0; i < Q; i++) {
                scanf("%d", &X[i]);             
            }
            r = solve();
            printf("#%d %d\n", test_case, r);
	}
	return 0; 
}

int solve() 
{
    quicksort(0, N -1);
    
    printData();    
    
}


void swap(int x,int y)
{
    Hole temp;
    
    temp.r  = H[x].r;
    temp.p  = H[x].p;
    temp.f  = H[x].f;
    
    H[x].r = H[y].r;
    H[x].p = H[y].p;
    H[x].f = H[y].f;
    
    H[y].r = temp.r;
    H[y].p = temp.p;
    H[y].f = temp.f;   
    
}
 
int choose_pivot(int i,int j )
{
    return((i+j) /2);
}
 
void quicksort(int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(m,k);
        key = H[m].r;
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (H[i].r <= key))
                i++;
            while((j >= m) && (H[j].r > key))
                j--;
            if( i < j)
                swap(i,j);
        }
        /* swap two elements */
        swap(m,j);
 
        /* recursively sort the lesser list */
        quicksort(m,j-1);
        quicksort(j+1,n);
    }
}


void printData()
{
    for (int i = 0; i < N; i ++) {
        printf("%d r:%d p:%d \n", i, H[i].r, H[i].p);        
        
    }
    
    
    
}


#if 0
int solve()
{
    int i = 0; 
    int j = 0;
    int Fill[MAX_N] = { 0, };   
    
    
    sort(0, N - 1);
    
    for (i = 0; i < Q; i++) { /* disc */
        for (j = 0; j < N ; j ++) {   /* Hole */
            
            if (Fill[j] == 1) {
                if (j > 0) {
                    Fill[j - 1] =1;
                    break;
                }
                else  /* when top is occupied */ 
                    return 0;                
            }
            else if(X[i] > H[j].r ) {
                //printf("%dth disc[%d] stop at %d [%d]\n", i, X[i], j, R[j]);
                Fill[j] = 1; 
                break; 
            }            
        } 
        if (j == N)
            Fill[j - 1] = 1;        
    }   
    
    if (Fill[0] == 1)
        return 0; 
    
    for (i = 0; i < N; i++)
        if (Fill[i] == 1)
            return (i + 1);
    
}
#endif 

