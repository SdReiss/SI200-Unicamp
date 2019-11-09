# Projeto Disciplina

/** * Atividade * * Tarefa em dupla. Pl´agios ser~ao penalizados * de maneira severa e exemplar. * * Prazo: ver no moodle * * Nesta tarefa voc^e deve criar um registro Disciplina. * O nome da discplina e do professor devem ser digitados * pelo usu´ario na primeira execu¸c~ao do programa. * * Os dados ser~ao salvos em arquivo. Na segunda vez que * for executado, o nome da disciplina e do professor * vir~ao diretamente do arquivo. * * Voc^e deve fazer um menu com op¸c~oes. * 1 - adicionar aluno. * 2 - remover aluno. * 3 - Listar alunos. * 4 - salvar (salva todos os dados em arquivo)
4
* 5 - sair. * * Ao abrir, os dados ser~ao carregados do arquivo. * * * * */
//registro aluno. typedef struct Aluno{ char nome[200];// long int ra; int idade; float CR; }Aluno;
typedef struct Disciplina{ char nome[200]; char professor[200]; Aluno v[200]; int top;//numero de alunos. come¸ca com zero. }Disciplina;
Aluno le(){
//le um aluno do teclado e faz um return. //... seu codigo vem aqui. return 0;
} void imprimeA(Aluno a1){ //imprime o aluno no terminal //... seu codigo vem aqui. } void imprimeD(Disciplina d){ //imprime a disciplina. //primeiro o nome e o professor. //finalmente, a lista de alunos. // voc^e deve chamar o m´etodo imprimeA() //... seu codigo vem aqui.
} void persisteD(Disciplina d){
5
//salva a disciplina num arquivo. //deve ser um ´unico arquivo com toda a informa¸c~ao.
}
/*Disciplina carregaD(){ //carrega a disciplina do arquivo para a mem´oria. return NULL; }*/
int main(){
Disciplina x;
/** * seu c´odigo vem aqui. * */
printf("tamanho registro %lu\n",sizeof(Aluno)); printf("tamanho long int %lu\n",sizeof(long int)); printf("tamanho int %lu\n",sizeof(int)); printf("tamanho float %lu\n",sizeof(float)); printf("tamanho char 200*%lu\n",sizeof(char));
}
