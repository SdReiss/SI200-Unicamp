#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct Aluno{
    int RA;
    char nome[200];
    char login[100];
    char senha[100];
} Aluno;

char* formataString(char* str);

Aluno* newAluno(int RA, char* nome, char* login, char* senha);

void cadastraAluno(Aluno* aluno);

int logar(char* user, char* senha);

#endif
