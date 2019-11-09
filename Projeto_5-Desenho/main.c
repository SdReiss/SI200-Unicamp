#include <stdio.h>
#include <stdlib.h>

#define quad(x) ((x)*(x))
#define PI 3.14159265359

int AZUL[3] = {0, 0, 255};
int VERDE[3] = {0, 255, 0};
int BRANCO[3]= {255, 255, 255};

typedef struct Circulo {
    /** raio do circulo    */
    double raio;
    /** centro do circulo */
    int xc,yc;
}Circulo;

typedef struct Reta {
    int x,y, n;
    float m;
}Reta;

typedef struct Imagem{
    int LI; /** numero de linhas da imagem */
    int CO; /** numero de colunas da imagem */
    int **m; /** matriz que guarda a imagem, 1 int para cada pixel */
}Imagem;

Circulo * newCirculo(double raio,int xc, int yc){
    Circulo * c = (Circulo *)malloc(sizeof(Circulo));
    c->xc=xc;
    c->yc=yc;
    c->raio=raio;
    return c;
}

int dentroCirculo(Circulo *c, int x,int y){

    return quad(x-c->xc)/9+quad(y-c->yc) <= quad(c->raio);

}

Reta* newReta(float m,int x, int y){
    Reta* r = (Reta*)malloc(sizeof(Reta));
    r->x=x;
    r->y=y;
    r->m=m;

    return r;
}

int dentroReta(Reta* r, int x, int y, char v){
    if(v=='-')
        return y-r->y<=r->m*(x-r->x);
    if(v=='+')
        return y-r->y>=r->m*(x-r->x);
}

int ** allocaMatriz(int LI,int CO){
    int ** m;
    m =(int **)malloc(sizeof(int *)*LI);
    for(int i=0;i<LI;i++){
        m[i] = (int *)malloc(sizeof(int)*CO);
    }
    return m;
}

Imagem * newImagem(int LI,int CO){
    Imagem *x = (Imagem *)malloc(sizeof(Imagem));
    x->LI=LI;
    x->CO=CO/3;
    x->m=allocaMatriz(LI,CO);
    for(int li=0;li<LI;li++){
        for(int col=0;col<CO;col+=3){
            x->m[li][col]=255;
            x->m[li][col+1]=255;
            x->m[li][col+2]=0;
        }
    }
    return x;
}

void setColor(Imagem *x,int li,int col,int* cor){
    if(li>=0&&li<x->LI&&col>0&&col<x->CO*3){
        x->m[li][col]=cor[0];
        x->m[li][col+1]=cor[1];
        x->m[li][col+2]=cor[2];
    }
}

void salvaImagem(Imagem *x, char * fname){
    FILE *f;
    int li,col;
    f = fopen(fname,"w");
    fprintf(f,"P3\n");
    fprintf(f,"%d %d\n",x->CO,x->LI);
    fprintf(f, "255\n");
    for (li=x->LI-1; li>=0;li--) {
        for (col=0; col<x->CO*3;col+=3) {
            fprintf(f,"%d ",x->m[li][col]);
            fprintf(f,"%d ",x->m[li][col+1]);
            fprintf(f,"%d ",x->m[li][col+2]);
        }
        fprintf(f,"\n");
    }
    fclose(f);

}

void desenhaCirculo(Imagem *x,Circulo *c,int* cor){
    for(int li=0;li<x->LI;li++){
        for(int col=0;col<x->CO*3;col+=3){
            if(dentroCirculo(c,col,li)){
                setColor(x,li,col,cor);
            }
        }
    }
}

void desenhaReta(char v, Imagem *x, Reta *r, int* cor){
    for(int li=0;li<x->LI;li++){
        for(int col=0;col<x->CO*3;col+=3){
            if(dentroReta(r,col,li,v)){
                setColor(x,li,col,cor);
            }
        }
    }
}

void desenhaFaixa(Imagem* x, Reta *r1, char v1, Reta* r2, char v2, Circulo *c, int* cor){
    for(int li=0;li<x->LI;li++){
        for(int col=0;col<x->CO*3;col+=3){
            if(dentroReta(r1,col,li,v1)&&dentroReta(r2,col,li,v2)&&dentroCirculo(c,col,li)){
                setColor(x,li,col,cor);
            }
        }
    }
}


int main(){
    int largura = 2000;
    int altura = 1400;
    Imagem* img = newImagem(altura,3*largura);

    double raio = 225;
    int centro_x=1000;
    int centro_y=700;
    Circulo* c = newCirculo(raio,3*centro_x,centro_y);
    desenhaCirculo(img,c,AZUL);

    Reta* r1=newReta(-0.212851405,0,870);
    desenhaReta('-',img,r1,VERDE);

    Reta* r2=newReta(0.212851405,0,530);
    desenhaReta('+',img,r2,VERDE);

    Reta* r3=newReta(-0.212851405,0,1805);
    desenhaReta('+',img,r3,VERDE);

    Reta* r4=newReta(0.212851405,0,-400);
    desenhaReta('-',img,r4,VERDE);

    Reta* faixa1=newReta(0,0,720);
    Reta* faixa2=newReta(0,0,680);
    desenhaFaixa(img,faixa1,'-',faixa2,'+',c,BRANCO);

    salvaImagem(img,"img.ppm");

}
