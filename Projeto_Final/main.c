#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"

int menu_2(){
    int menu_op;
    do{
        printf("\n[Menu de Opções]:\n1. Consulta de Disciplinas\n0. Voltar!\n\nInsira a opção desejada: ");
        scanf("%d", &menu_op);

        switch (menu_op){
            case 1:
                break;
            case 0:
                return 0;
            default:
                printf("Opção inválida!");
                break;
        }
        }while (menu_op!=0);
}

int main(){
    FILE* fp;
    int menu_ini, RA;
    char nome[200];
    char login[100];
    char senha[100];

    setlocale(LC_ALL,"");

    do{
        printf("\n[Menu Inicial]\n1. Logar\n2. Cadastrar\n0. Sair!\n\nInsira a opção desejada: ");
        scanf("%d",&menu_ini);

        switch(menu_ini){
            case 1:
                fp=fopen("Alunos.txt","r");
                if(fp==NULL){
                    printf("Não há alunos cadastrados! Cadastre-se antes de logar.\n");
                    fclose(fp);
                    break;
                }else{
                    getchar();
                    printf("\nUsuário: ");
                    fgets(login,100,stdin);

                    printf("Senha: ");
                    fgets(senha,100,stdin);

                    if(logar(login,senha)==1){
                        printf("\nLogin realizado com sucesso!\n");
                        menu_2();
                    }else{
                        printf("\nUsuário ou Senha inválidos.\n");
                    }
                }
                break;
            case 2:
                printf("Digite o RA do Aluno: ");
                scanf("%d",&RA);
                getchar();

                printf("Digite o Nome do Aluno: ");
                fgets(nome,200,stdin);

                printf("Digite o login: ");
                fgets(login,100,stdin);

                printf("Digite a senha: ");
                fgets(senha,100,stdin);

                cadastraAluno(newAluno(RA,nome,login,senha));

                break;
            case 0:
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }while(menu_ini!=0);



        return 0;

}
