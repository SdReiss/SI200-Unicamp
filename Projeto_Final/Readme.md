## Objetivo Geral:

Este projeto consiste na elaboração de um sistema responsável por gerenciar as matrículas dos alunos nas disciplinas de um determinado semestre. Além disso, o sistema será responsável por gerenciar as notas dos alunos, os pré-requisitos necessários para cursar uma dada disciplina, e também a geração de coeficientes, como rendimento e padrão.

# Passos para elaboração do Sistema

## Entrega 1 (25/10)
O objetivo da Entrega: Adaptar os alunos ao contexto do problema, e realizar a leitura de todas as informações núcleo para a execução do programa.

1- Leitura das Disciplinas: Antes de tudo, é necessário gravar todas as disciplinas do curso obtidas diretamente no site da DAC (https://www.dac.unicamp.br/sistemas/catalogos/grad/catalogo2018/curriculoPleno/cp36.html) em um arquivo chamado Disciplinas.txt, seguindo o formato apresentado no item Tabelas (OBS: A quantidade de créditos pode ser obtida através do parâmetro C, quando consultado a disciplina.
•	Além disso, é necessário a criação da Tabela Prerequisitos.txt, a qual será responsável por armazenar os pré-requisitos para um aluno cursar uma determinada disciplina. OBS: Essa informação está contida dentro de cada disciplina na DAC e também deverá ser lida na inicialização do programa. Em casos de disciplinas que necessitam de mais de um pré-requisito, colocar todos.

Dica: A cada passo solicitado acima, verifique se a informação foi lida corretamente, evite fazer todos os passos para ao fim testar todos de uma vez.

Ambos os arquivos (Disciplinas.txt e Prerequisitos.txt) deverão ser gerados manualmente pelo grupo, o sistema apenas realizará a leitura dos itens.

2- Cadastro de Alunos: O sistema deverá conter as informações dos alunos que estão vinculados em cada matéria. Portanto, será necessária a geração de um txt Alunos.txt contendo as informações de todos os alunos que utilizam o sistema. Para facilitar, gere o arquivo já inicializado, ou seja, com Ra,Nome,login e senha (todos fictícios) de um aluno.

<b>Menu Cadastro de Alunos (Modelo):</b>\
Digite o RA do Aluno:\
Digite o Nome do Aluno:\
Digite o login:\
Digite a senha:

3- Login: Esta etapa é responsável por ler os alunos contidos na tabela Alunos.txt
Inicialmente, o sistema deverá solicitar o login e senha de um aluno, sem estes dados, o programa não pode continuar rodando.
Menu Inicial (Modelo):\
Usuário:\
Senha:

O menu inicial basicamente será composto por Usuário e Senha, podendo ter duas ações:
Caso o aluno digite informações que estejam contidas na tabela Aluno.txt, o sistema será iniciado, dando acesso ao Menu de Opções.
Caso contrário, o programa irá repetir o passo, apresentando a mensagem: “Usuário ou Senha inválidos.”.


4- Consulta de Disciplinas: A consulta de disciplinas deve ser realizada olhando para as duas tabelas de disciplinas.  O campo que será lido será apenas o código da disciplina, que estará contida na Tabela Disciplinas.txt. Logo após a consulta, os dados referentes a disciplina devem ser retornados, conforme o exemplo abaixo:

Digite a disciplina: SI201 (usuário digita)\
Nome: Estrutura de Dados I\
Quantidade de Créditos: 4\
Pré-requisito: SI100 - Algoritmos e Programação de Computadores I

Dica: o arquivo Disciplina.txt será acessado uma vez, para pesquisar os detalhes da disciplina, e uma segunda, juntamente com a abertura do arquivo Prerequisitos.txt, para identificar o nome da disciplina. Nota-se que está a cargo dos alunos escolherem se preferem utilizar a struct como busca, ou a pesquisa interna no txt.

<b>Menu de Opções:</b>\
Cadastro de Alunos\
Consulta de Disciplinas

#### Tabelas do Sistema

<b>Alunos.txt</b>\
RA,Nome,login,senha

<b>Disciplinas.txt</b>\
Código,Nome,QtdCréditos

<b>Prerequisitos.txt</b>\
CódigoDaDisciplina,CódigoDaPrérequisito


## Entrega 2 (08/11)
Objetivo da Entrega: Realizar as associações que definem o sistema de gerencia de disciplinas, como alunos e disciplinas, verificação de pré-requisitos, e afins.

1- Realizar Matrícula: Este menu é responsável por vincular a grade de um semestre a um aluno.

<b>Tela de Realizar Matrícula (Modelo):</b>

Para sair, digite XX000\
Digite o semestre: 2\
Digite a disciplina: SI200\
Digite a disciplina: AA100\
Digite a disciplina: XX000\
Transação efetuada com sucesso

Entretanto, por ser um dos principais pontos do sistema, esta parte deve conter diversas verificações, conforme as identificadas abaixo. A nota e as faltas começarão vazios. Numa próxima etapa, as notas e faltas serão inseridas.

 * 1: O cadastro das disciplinas só pode ser feito para o aluno logado.
 * 2: Não é permitido mais do que 32 créditos. Caso ultrapasse, o sistema deve informar o erro e não computar nenhuma das disciplinas inseridas.
 * 3: Somente será possível cadastrar uma disciplina se, e somente se, o aluno já tiver cursado os pré-requisitos e tiver obtido, no mínimo, conceito igual a 5 e faltas menor que 25%.
 * 4: Caso não exista a disciplina no momento do cadastro, o sistema deve informar de imediato que a disciplina não existe, mas não apagar as outras que já foram digitadas.
 * 5: Não é permitido inserir um semestre que seja anterior ao semestre mais atual do aluno, caso isso ocorra, o sistema deverá informar de imediato o erro e pedir um novo semestre.
/*

3- Atualizar Nota e Falta: O sistema deve permitir que o aluno insira as notas e faltas obtidas nas disciplinas que já foram cursadas. A atualização é realizada por disciplina, ou seja, para atualizar três disciplinas, este menu deve ser executado três vezes. É recomendável que o sistema, após o aluno informar o semestre, exiba as disciplinas que o aluno está cursando naquele semestre, para facilitar que o aluno modifique as informações.

<b>Menu de Realizar Matrícula (Modelo):</b>

Digite o semestre: 2\
Disciplinas:\
SI200 – Algoritmos – Nota: , Falta (%):\
AA100 – Estrutura – Nota: 5, Falta: 10.0

Digite o código da disciplina que deseja fazer a alteração: SI200\
Nota: 8.5\
Falta (%): 17.5\
Atualização realizada com sucesso

<b>Algumas validações devem ser realizadas neste menu. </b>

 * 1: O aluno pode alterar qualquer disciplina, mesmo as que já possuem nota.
 * 2: Só é permitido a inserção de valores entre 0-10 para nota, e porcentagem para faltas no intervalo (0-100).
 * 3: Caso o aluno digite XX000 na disciplina, o sistema deve encerrar o menu.
 * 4: Deve ser apresentado um erro caso o aluno tente alterar uma disciplina inexistente.
 * 5: As Tabelas AlunosDisciplinas e Disciplinas são as únicas tabelas a serem lidas.
 * 6: O grupo escolhe entre ler as informações dos arquivos e gravar em tempo de execução ou sempre realizar a leitura dos arquivos. Pode manter uma cópia na memória ou não.

<b>Menu de Opções:</b>\
Cadastro de Alunos\
Consultar de Disciplinas\
Realizar Matrícula\
Atualizar Nota e Falta


#### Novas Tabelas do Sistema

<b>AlunosDisciplinas.txt</b>\
RA,CódigodaDisciplina,Semestre,Nota,Faltas


## Entrega 3 (22/11): Geração de Informações para impressão

Objetivo da Entrega: Esta parte será responsável pela geração dos dados para impressão, no mesmo formato apresentado pela DAC. Ou seja, com informações como coeficiente de rendimento e classificação do aluno na turma.

1- Consultar Histórico do Aluno: Este menu é utilizado apenas para exportação dos dados do aluno logado no sistema. Nenhuma informação deve ser mostrada na tela, apenas que o arquivo (RAdoAluno.txt) foi gerado com sucesso. Dentro do txt, espera-se que os dados estejam organizados e tabulados, assim como no site da DAC.

<b>Modelo do TXT</b>\
Faculdade de Tecnologia – UNICAMP
  
Relatório de Matrícula
  
Nome Completo: Kauê . . . Duarte  
RA: 117524  
Coeficiente de Rendimento: 0.71  
Classificação do aluno na turma : 3 de 15  
  
  
Disciplina | Nota |	Faltas (%) |	Situação
-----------|------|------------|--------------------------------
SI200		   | 7.1 	|  10.4		   | Aprovado por Nota e Frequência
AA201		   | 4.2	|  10.4		   | Reprovado por Nota
BB213		   | 9.0  |  30.2		   | Reprovado por Faltas


 * 1: O coeficiente de rendimento é calculado na execução do programa, e nunca armazenado. Este deve seguir a seguinte fórmula:
        CR = (C1*v1+C2*v2+...+Cn*vn)/(C1+C2+...+Cn)
No qual C é a quantidade de créditos e v é a nota do aluno.
 * 2: A classificação do aluno na turma é calculado da seguinte maneira: É necessário calcular o CR de todos os alunos, ordenar e ver a posição relativa do aluno frente a todos os alunos do sistema. Uma posição 3 de 10 significa possuir o terceiro melhor CR num conjunto de 10 alunos.
 * 3: Caso o número de faltas seja igual ou superior a 25%, o aluno deve ser reprovado por falta
 * 4: Caso o aluno possua nota abaixo de 5, o mesmo deve ser considerado reprovado por nota
 * 5: Todas as disciplinas que o aluno cursou devem aparecer em ordem semestral

<b>Menu de Opções:</b>\
Cadastro de Alunos\
Consultar de Disciplinas\
Realizar Matrícula\
Atualizar Nota e Falta\
Consultar Histórico do Aluno

#### Novas Tabelas do Sistema
Nenhuma nova tabela
