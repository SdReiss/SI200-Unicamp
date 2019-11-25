#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

char* formataString(char* str){
    int tam;
    tam = strlen(str);
    str[tam - 1] = '\0';

    return str;
}

Aluno* newAluno(int RA, char* nome, char* login, char* senha){
    Aluno* aux = malloc(sizeof(Aluno));
    int tam;

    aux->RA=RA;
    strcpy(aux->nome,nome);
    strcpy(aux->login,login);
    strcpy(aux->senha,senha);

    formataString(aux->nome);
    formataString(aux->login);
    formataString(aux->senha);

    return aux;
}

void cadastraAluno(Aluno* aluno){
    FILE* fp;
    fp = fopen("Alunos.txt","a+");
    fprintf(fp,"%d,%s,%s,%s\n",aluno->RA,aluno->nome,aluno->login,aluno->senha);
    fclose(fp);
}

int logar(char* username, char* password){
    FILE* fp;

    fp = fopen("Alunos.txt","r");

    formataString(username);

    char *user, *pass, aux;
    char info[100];

    do{
        fgets(info, 100, fp);
        strtok(info, ",");
        strtok(NULL, ",");
        user = strtok(NULL, ",");
        pass = strtok(NULL, ",");

        if(strcmp(user, username) == 0 && strcmp(pass, password) == 0){
            return 1;
        }
    }while(fscanf(fp, "%c", &aux) != EOF);

    return 0;
}