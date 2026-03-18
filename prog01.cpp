//abaixo estamos carregando a biblioteca Standard Input Output para usarmos 
//os comandos de entrada (scanf) e saida (printf) de dados do usuario 

#include <stdio.h>
/*Escreva um programa que solicite ao usuario um nome, sexo, idade e tres notas dos N alunos em uma turma, e ao final, apresente:
1)Quantidade de alunos cadastrados na turma.................................ok
2)A quantidade de alunos e alunas (%) aprovados/reprovados na turma
3)A media de idade dos alunos aprovados/reprovados
4)Gerar relatorio alunos aprovados/reprovados 
5)Tornar configuaravel:
5.1) A media de aprovacao;..........................ok
5.2) A quantidade de provas a serem realizadas pelo aluno..........................ok
6) fazer tratamento de dados na entrada do usuario(notas, idade, media, sexo)...................ok
6.1) notas ( o < nota < 10)..........................ok
6.2)idade ( 16 < idade < 90 ).....................ok
6.3) media ( 5 < media < 8 )..........................ok
6.4) sexo ( M/m/F/f)...................ok  */

#include<stdio.h>

struct Aluno {
	char Nome[30];
	char Sexo;
	int Idade;
	float Notas[10];
	bool Aprovado;
};

//a seguir temos a função principal do programa 

int main () {
	
	int QtdAlunos, QtdProvas, QtdAlunosM= 0,QtdAlunasF= 0;
	int QtdAprovM= 0, QtdAprovF= 0, QtdReprovM= 0, QtdReprovF= 0;
	
	int SomaIdadeAprov = 0, SomaIdadeReprov = 0;
    int ContAprov = 0, ContReprov = 0;
    
	float Media, MediaAprov;
	float PercAprovM, PercReprovM, PercAprovF, PercReprovF;
	
	float MediaIdadeAprov, MediaIdadeReprov; 
	struct Aluno Alunos[100];
	
	//solicita ao usuario a quantidade de alunos e provas
	printf("Informe a quantidade de alunos: ");
	scanf("%i",&QtdAlunos);
	printf("Informe a quantidade de provas: ");
	scanf("%i",&QtdProvas);
	
	do {
		printf("Informe a media de aprovacao: ");
	scanf("%f",&MediaAprov);
	} while (MediaAprov < 5 or MediaAprov > 8);
	
	for (int i=1; i<=QtdAlunos; i++) {
		printf("Informe o nome do %d. aluno: ", i);
	scanf("%s",&Alunos[i].Nome);
	
	do {
	    printf("Informe a idade de %s: ", Alunos[i].Nome);
	scanf("%i",&Alunos[i].Idade);
	} while (Alunos[i].Idade < 16 || Alunos[i].Idade > 90);
	
	do {
		printf("Informe o sexo de %s (F- Feminino, M- Masculino ): ", Alunos[i].Nome);
	scanf("%s",&Alunos[i].Sexo);
	} while (Alunos[i].Sexo != 'M' and Alunos[i].Sexo != 'm' &&
	         Alunos[i].Sexo != 'F' and Alunos[i].Sexo != 'f');
	
	if (Alunos[i].Sexo == 'M' or Alunos[i].Sexo == 'm')
		QtdAlunosM++;
	else 
	   QtdAlunasF++;
	 
	 
	 
	 //solicita ao usuario as notas os alunos e exibe as aprovações/reprovações
	 Media = 0;
	 
	for (int n=0; n<QtdProvas; n++) {  //Este codigo nao esta Hardcoded
	
	do {
	  printf ("      Informe a nota %d. de %s: ", n+1, Alunos[i].Nome);
	  scanf("%f", &Alunos[i].Notas[n]);
	} while (Alunos[i].Notas[n] < 0 || Alunos[i].Notas[n] > 10);
		Media = Media + Alunos[i].Notas[n];
	}
	
	Media = Media / QtdProvas; //Este codigo nao esta Hardcoded
		
	Alunos[i].Aprovado = Media >= MediaAprov;  //Este codigo nao esta Hardcoded
	if (Alunos[i].Aprovado and (Alunos[i].Sexo == 'F' or Alunos[i].Sexo == 'f'))
	QtdAprovF++;
	
	else if(Alunos[i].Aprovado and (Alunos[i].Sexo == 'M' or Alunos[i].Sexo == 'm'))
	QtdAprovM++;
	
	else if(!Alunos[i].Aprovado and (Alunos[i].Sexo == 'M' or Alunos[i].Sexo == 'm'))
	QtdReprovM++;
	
	else if(!Alunos[i].Aprovado and (Alunos[i].Sexo == 'F' or Alunos[i].Sexo == 'f'))
	QtdReprovF++;
	
	if (Alunos[i].Aprovado) {
            SomaIdadeAprov += Alunos[i].Idade;
            ContAprov++;
        }
        else {
            SomaIdadeReprov += Alunos[i].Idade;
            ContReprov++;
        }
}

   //Exibe o percentual dos alunos e alunas aprovados/reprovados
    PercAprovM = (float)QtdAprovM / QtdAlunos * 100;
    PercAprovF = (float)QtdAprovF / QtdAlunos * 100;
    PercReprovM = (float)QtdReprovM / QtdAlunos * 100;
    PercReprovF = (float)QtdReprovF / QtdAlunos * 100;

    printf("\n Percentual de alunos(M) aprovados: %.2f%%", PercAprovM);
    printf("\n Percentual de alunas(F) aprovadas: %.2f%%", PercAprovF);
    printf("\n Percentual de alunos(M) reprovados: %.2f%%", PercReprovM);
    printf("\n Percentual de alunas(F) reprovadas: %.2f%%", PercReprovF);
    
    //Exibe a media de idade dos alunos aprovados/reprovados
    MediaIdadeAprov = (float)SomaIdadeAprov / ContAprov;
    MediaIdadeReprov = (float)SomaIdadeReprov / ContReprov;

    printf("\n Media de idade dos aprovados: %.2f", MediaIdadeAprov);
    printf("\n Media de idade dos reprovados: %.2f \n", MediaIdadeReprov);


    //relatoro final do projeto
	printf("\n Quantidade de alunos matriculados na turma :%i ", QtdAlunos);
	
	printf("\n\n RELATORIO DOS ALUNOS \n");

   for(int i=1; i<=QtdAlunos; i++) {
    printf("\n Aluno: %s", Alunos[i].Nome);
    if(Alunos[i].Aprovado)
        printf("  APROVADO! ");
    else
        printf("  REPROVADO! ");
}

} 
