#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 40

#define TEST 0     // 1 - dla testow,  0 - dla oceny automatycznej

void read_vec(double x[], int n) {
  for(int i=0; i<n; ++i)  scanf("%lf",x++);
}

void print_vec(double x[], int n) {
  for(int i=0; i<n; ++i) printf("%.4f ",x[i]);
  printf("\n");
}

void read_mat(double A[][SIZE], int m, int n) {
  for(int i=0; i<m; ++i) {
    for(int j=0; j<n; ++j)  scanf("%lf",&A[i][j]);
  }
}

void print_mat(double A[][SIZE], int m, int n) {
  for(int i=0; i<m; ++i) {
    for(int j=0; j<n; ++j)  printf("%.4f ",A[i][j]);
    printf("\n");
  }
}

void print_mat_ind(double A[][SIZE], int m, int n,int indicies[]) {
  for(int i=0; i<m; ++i) {
    for(int j=0; j<n; ++j)  printf("%.4f ",A[indicies[i]][j]);
    printf("\n");
  }
  printf("\n");
}

// A mxp, B pxn
// definicja powinna byc juz napisana w zadaniu 5.1.1
void mat_product(const double A[][SIZE], const double B[][SIZE], double AB[][SIZE], const int m, const int p, const int n) {
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            AB[i][j] = 0;
            for(int k = 0; k<p;k++)
            {
                AB[i][j]+=A[i][k]*B[k][j];
            }
            
        }
    }
    
}

// Funkcja moze byc przydatna do sprawdzania poprawnosci rozwiazania Ax=b
void mat_vec_product(double A[][SIZE], double b[], double Ab[], int m, int n) {
  int i, k;
  double sum;
  for(i=0; i<m; ++i) {
    for(k=0, sum=0.0; k<n; ++k) sum += A[i][k] * b[k];
    Ab[i] = sum;
  }
  return;
}

// 5.2.1 Triangularyzacja, wyznacznik i rozwiazanie Ax=b dla  macierzy kwadratowej.
// Wersja rozszerzona: Wybor wiersza z maksymalna waroscia |elementu glownego|
// Przy wymianie wierszy nalezy zastosowac wetor permutacji indeksow wierszy.
// Jezeli maksymalna wartosc |elementu glownego| < eps, to wyznacznik = 0.
// Zwraca wyznacznik det. Jezeli =0,  to triangularyzacja moze byc niedokonczona.
// Jezeli wyznacznik != 0, i b,x != NULL,
// to w wektorze x umieszcza rozwiazanie ukladu rownan Ax=b.

double gauss(double A[][SIZE], const double b[], double x[], const int n, const double eps) {
    double fact;
    double wyzn = 0;
    int t[n];
    double pom[n];
    int tmp,max;
    int znak = 1;
    for(int i = 0; i < n; i++)
    {
        if(b!=NULL)
            pom[i]=b[i];
        t[i] = i;
    }
    for(int i = 0; i < n; i++)
    {
        max = i;
        for(int j = i+1; j < n; j++)
            if(fabs(A[t[j]][i]) > fabs(A[t[max]][i]))
                max = j;
        if(fabs(A[t[max]][i])<eps)
            return 0;
        if(max!= i)
        {
            tmp = t[i];
            t[i] = t[max];
            t[max] = tmp;
            znak *= -1;
        }
        for(int j = i+1; j < n; j++)
        {
            fact = A[t[j]][i] / A[t[i]][i];
            for(int k = i; k < n; k++)
                A[t[j]][k] -= A[t[i]][k]*fact;
            if(b != NULL)
                pom[t[j]]-=pom[t[i]]*fact;
        }
        
    }
    wyzn = znak;
    for(int i = 0; i < n; i++)
        wyzn*= A[t[i]][i];
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i-1; j >= 0; j--)
        {
            fact = A[t[j]][i] / A[t[i]][i];
            for(int k = i; k >= 0; k--)
                A[t[j]][k]-= A[t[i]][k]*fact;
            if(b != NULL)
                pom[t[j]]-=pom[t[i]]*fact;
        }
    }
    if(x == NULL || wyzn == 0 || b == NULL)
        return wyzn;
    for(int i = n-1; i >= 0; i--)
        pom[t[i]] = pom[t[i]]/A[t[i]][i];
    for(int i =0; i<n;i++)
        x[i] = pom[t[i]];
    return wyzn;
}

// 5.2.2
// Zwraca wyznacznik i w tablicy B macierz odwrotna (jezlei wyznacznik != 0)
// Jezeli maksymalna bezwzgledna wartosc elementu glownego < eps,
// to funkcja zwraca wartosc wyznacznika det = 0.
// Funkcja zmienia wartosci takze w tablicy A.

double matrix_inv(double A[][SIZE], double B[][SIZE], const int n, const double eps) {
    double fact;
    double wyzn = 0;
    int t[n];
    double pom[n][n];
    int tmp,max;
    int znak = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j< n; j++)
        {
            if(j==i)
                B[i][j]=1;
            else
                B[i][j]=0;
        }
    for(int i = 0; i < n; i++)
        t[i] = i;
    for(int i = 0; i < n; i++)
    {
        max = i;
        for(int j = i+1; j < n; j++)
            if(fabs(A[t[j]][i]) > fabs(A[t[max]][i]))
                max = j;
        if(fabs(A[t[max]][i])<eps)
            return 0;
        if(max!= i)
        {
            tmp = t[i];
            t[i] = t[max];
            t[max] = tmp;
            znak *= -1;
        }
        for(int j = i+1; j < n; j++)
        {
            fact = A[t[j]][i] / A[t[i]][i];
            for(int k = 0; k < n; k++)
            {    
                A[t[j]][k] -= A[t[i]][k]*fact;
                B[t[j]][k] -= B[t[i]][k]*fact;
            }
        }
    }
    wyzn = znak;
    for(int i = 0; i < n; i++)
        wyzn*= A[t[i]][i];
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i-1; j >= 0; j--)
        {
            fact = A[t[j]][i] / A[t[i]][i];
            for(int k = n-1; k >= 0; k--)
            {
                A[t[j]][k] -= A[t[i]][k]*fact;
                B[t[j]][k] -= B[t[i]][k]*fact;
            }
        }
        fact = A[t[i]][i];
        for(int k = 0; k < n; k++)
        {
            A[t[i]][k] /= fact;
            B[t[i]][k] /= fact;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            pom[i][j] = B[t[i]][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            B[i][j] = pom[i][j];
    return wyzn;
}

int main(void) {

  double A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
  double b[SIZE], x[SIZE], det, eps = 1.e-13;

	int to_do;
	int m,n,p,q;
	if(TEST) printf("Wpisz nr zadania ");
	scanf ("%d", &to_do);

	switch (to_do) {
    case 1:
      if(TEST) printf("Wpisz liczbe wierszy i kolumn mac. kwadratowej: ");
      scanf("%d", &n);
      if(TEST) printf("Wpisz macierz A (wierszami): ");
      read_mat(A,n,n);
      if(TEST) printf("Wpisz wektor b: ");
      read_vec(b,n);
      det = gauss(A, b, x, n, eps);
      printf("%.4f\n",det);
      if(det) print_vec(x,n);
      break;
    case 2:
      if(TEST) printf("Wpisz rozmiar macierzy n = ");
      scanf("%d",&n);
      if(TEST) printf("Wpisz elementy macierzy (wierszami): ");
      read_mat(A,n,n);
      det = matrix_inv(A,B,n,eps);
      printf("%.4f\n",det);
      if(det) print_mat(B,n,n);
      break;
    default:
      printf("NOTHING TO DO FOR %d\n", to_do);
	}
	return 0;
}
