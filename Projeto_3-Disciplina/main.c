#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//registro aluno.
typedef struct Aluno{
    char nome[200];//
    long int ra;
    int idade;
    float CR;
} Aluno;

typedef struct Disciplina{
    char nome[200];
    char professor[200];
    Aluno v[200];
    int top;//numero de alunos. começa com zero.
} Disciplina;

Aluno le(){
    //le um aluno do teclado e faz um return.
    Aluno A;
    printf("Nome: ");
    getchar();
    fgets(A.nome,200,stdin);
    //printf("Nome armazenado: %s",A.nome);

    printf("RA: ");
    scanf("%ld",&A.ra);
    //printf("RA armazenado: %ld\n",A.ra);

    printf("Idade: ");
    scanf("%d",&A.idade);
    //printf("Idade armazenada: %d\n",A.idade);

    printf("CR: ");
    scanf("%f",&A.CR);
    //printf("CR armazenado: %f\n",A.CR);
    return A;
}

void imprimeA(Aluno a1){
    //imprime o aluno no terminal
    printf("Nome: %s",a1.nome);
    printf("RA: %ld\n",a1.ra);
    printf("Idade: %d\n",a1.idade);
    printf("CR: %f\n",a1.CR );
}

void imprimeD(Disciplina d){
    //imprime a disciplina.
    //primeiro o nome e o professor.
    //finalmente, a lista de alunos.
    // você deve chamar o método imprimeA()
    //... seu codigo vem aqui.
    int i;

    printf("[Disciplina]: %s",d.nome);
    printf("[Professor]: %s",d.professor);

    for(i = 0; i<d.top; i++){
        printf("\n[Aluno %d]:\n",i+1);
        imprimeA(d.v[i]);
    }

    if(i==0)
        printf("Nenhum aluno cadastrado!\n");

    printf("\n");

}

void persisteD(Disciplina d){
    //salva a disciplina num arquivo.
    //deve ser um único arquivo com toda a informaçao.
    FILE* fp;

    fp = fopen("dados.txt","w");

    fprintf(fp,"%s", d.nome);
    fprintf(fp,"%s", d.professor);

    for(int i = 0; i<d.top; i++){
        fprintf(fp,"%s",d.v[i].nome);
        fprintf(fp,"%ld\n",d.v[i].ra);
        fprintf(fp,"%d\n",d.v[i].idade);
        fprintf(fp,"%f\n",d.v[i].CR);
    }

    fclose(fp);

}

Disciplina carregaD(){
    //carrega a disciplina do arquivo para a memória.
    FILE* fp;
    Disciplina x;
    int i;
    char c[2];
    int contador = 0;

    x.top = 0;

    fp = fopen("dados.txt","r");

    fgets(x.nome,200,fp);
    fgets(x.professor,200,fp);

    while(!feof(fp)){
        if(fgets(x.v[x.top].nome, 200, fp)==NULL)
            break;
        fscanf(fp,"%ld",&x.v[x.top].ra);
        fscanf(fp,"%d",&x.v[x.top].idade);
        fscanf(fp,"%f",&x.v[x.top].CR);
        if(fgets(c,2,fp)==NULL)
            break;
        x.top++;
    }

    fclose(fp);

    return x;
}

Disciplina removeA(Disciplina d){
    int i, aux;
    long int ra;

    printf("Digite o RA do aluno que voce deseja remover: ");

    scanf("%ld",&ra);

    for(i=0;i<d.top;i++){
        if(ra==d.v[i].ra){
            break;
        }
        else if(i==d.top-1){
            printf("RA nao encontrado!\n");
            return;
        }
    }

    printf("Aluno encontrado! \n");

    printf("Removendo aluno...\n");

    aux = i +1;

    for(;aux<d.top;aux++, i++){
        strcpy(d.v[i].nome, d.v[aux].nome);
        d.v[i].ra = d.v[aux].ra;
        d.v[i].idade = d.v[aux].idade;
        d.v[i].CR = d.v[aux].CR;
    }

    d.top-=1;

    return d;

}

int main(){
    Disciplina x;
    FILE* fp;
    int menu;
    x.top = 0;

    fp = fopen("dados.txt","r");

    if(fp==NULL){
        fp = fopen("dados.txt","w");
        printf("Nenhuma disciplina encontrada.\nInsira o nome de uma disciplina: ");
        fgets(x.nome,200,stdin);
        fprintf(fp,"%s",x.nome);

        printf("Insira o nome do professor: ");
        fgets(x.professor,200,stdin);
        fprintf(fp,"%s",x.professor);

        fclose(fp);
    }
    else{
        x = carregaD();
    }

    while(1){
        printf("****MENU****\n1: Adicionar aluno\n2: Remover aluno\n3: Listar alunos\n4: Salvar\n5: Sair!\n"); //imprime o menu
        scanf("%d",&menu);
        switch (menu){
            case 1:
                printf("****ADICIONAR ALUNO****\n");
                x.v[x.top] = le();
                x.top++;
                break;
            case 2:
                printf("****REMOVER ALUNO****\n");
                x = removeA(x);
                break;
            case 3:
                printf("****LISTAR ALUNOS****\n");
                imprimeD(x);
                break;
            case 4:
                printf("Salvando arquivo...\n");
                persisteD(x);
                break;
            case 5:
                return 0;
            default:
                printf("****Opcao Invalida, tente novamente****\n");
                break;
        }
    }

    printf("tamanho registro %lu\n",sizeof(Aluno));
    printf("tamanho long int %lu\n",sizeof(long int));
    printf("tamanho int %lu\n",sizeof(int));
    printf("tamanho float %lu\n",sizeof(float));
    printf("tamanho char 200*%lu\n",sizeof(char));
}
