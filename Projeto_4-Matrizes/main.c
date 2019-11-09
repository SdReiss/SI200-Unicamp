#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matriz {
    int li, co, **m;
}Matriz;

Matriz* criaMatriz(int li, int co){
    Matriz* ma = (Matriz*)malloc(sizeof(Matriz));
    ma->li = li;
    ma->co = co;
    ma->m = (int**)malloc(sizeof(int*)*li);

    for(int i = 0; i<li; i++){
        ma->m[i] = (int*)malloc(sizeof(int)*co);
    }

    for(int i = 0; i<li; i++){
        for(int j = 0; j<co; j++){
            ma->m[i][j] = 0;
        }
    }

    return ma;
}

void freeMatriz(Matriz *m){
    for(int i = 0; i < m->li; i++){
        free(m->m[i]);
    }
    free(m->m);
}

void imprime(Matriz *m){
    for(int i = 0; i < m->li; i++){
        for(int j = 0; j < m->co; j++){
            printf("%d ", m->m[i][j]);
        }
        printf("\n");
    }
}

Matriz* multiplica(Matriz *a, Matriz *b){
    int li = a->li;
    int co = b->co;

    Matriz *c = criaMatriz(li,co);

    if(a->co!=b->li){
        printf("Impossivel multiplicar as matrizes.\n");
        return 1;
    } else{

        int soma = 0;
        for(int i=0;i<a->li;i++){
            for(int j=0;j<b->co;j++){
                for(int k=0;k<b->li;k++){
                    soma+= a->m[i][k]*b->m[k][j];
                }
                c->m[i][j]=soma;
                soma=0;
            }
        }
    }

    return c;

}

Matriz* criaMatrizUns(int li, int co){
    Matriz* ma = (Matriz*)malloc(sizeof(Matriz));
    ma->li = li;
    ma->co = co;
    ma->m = (int**)malloc(sizeof(int*)*li);

    for(int i = 0; i<li; i++){
        ma->m[i] = (int*)malloc(sizeof(int)*co);
    }

    for(int i = 0; i<li; i++){
        for(int j = 0; j<co; j++){
            ma->m[i][j] = 1;
        }
    }

    return ma;
}

void persiste(Matriz *m, char *fname){
    FILE* fp;
    fp = fopen(fname,"w");

    fprintf(fp, "%d %d\n",m->li,m->co);

    for(int i = 0; i<m->li; i++){
        for(int j = 0; j<m->co; j++){
            fprintf(fp,"%d ",m->m[i][j]);
        }
        fprintf(fp,"\n");
    }

    fclose(fp);
}

Matriz *carrega(char *fname){
    FILE* fp;
    fp = fopen(fname,"r");
    int li, co;
    fscanf(fp,"%d %d",&li, &co);

    Matriz *m = criaMatriz(li,co);

    for(int i=0;i<m->li;i++){
        for(int j=0;j<m->co;j++){
            fscanf(fp,"%d",&m->m[i][j]);
        }
    }

    fclose(fp);

    return m;
}


int main(){
    Matriz *m = criaMatriz(4,2);
    m->m[0][0] = 7;
    m->m[1][0] = m->m[2][0] = m->m[3][0] = 5;

    printf("--m--\n");
    imprime(m);

    Matriz *a = criaMatrizUns(3,3);
    Matriz *b = criaMatrizUns(3,3);

    a->m[0][1] = 7;
    a->m[0][2] = 5;

    printf("--a--\n");
    imprime(a);

    printf("--b--\n");
    imprime(b);

    printf("--a*a--\n");


    imprime(multiplica(a,a));

    persiste(a,"a.txt");

    printf("--a.txt--\n");
    imprime(carrega("a.txt"));
}
