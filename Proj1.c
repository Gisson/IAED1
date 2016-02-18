/*Projeto de:
José Touret 	78215
Pedro Cruz  	78579
Jorge Heleno 	79042*/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/* 28 estados membros 12 PPES */
#define EM 28
#define PPE 12


				      /*prototipos*/
void addvote(int votos[EM][PPE]);
void infoem(char estadosmembro[EM][3],char partidos[PPE][4],int votos[EM][PPE]);
void infoue(int mandatos[EM][PPE],char partidos[PPE][4],char estadosmembro[EM][3]);
void dhondt(int mandatos[EM][PPE], int votos[EM][PPE], int depmax[EM]);
void apagatab(int votos[EM][PPE], int mandatos[EM][PPE]);

					/*main*/
int main()
{
	char estadosmembro[EM][3] = {"DE","AT","BE","BG","CY","HR","DK","SK","SI","ES","EE","FI","FR","GR","HU","IE","IT","LV","LT","LU","MT","NL","PL","PT","GB","CZ","RO","SE"};
	char partidos[PPE][4] = {"EPP", "PES", "LDE", "EGP", "ECR", "ELP", "ELD", "EDP", "EAF", "EMN", "ECP", "AED"};
	char command;

	int depmax[EM]={96,18,21,17,6,11,13,13,8,54,6,13,74,21,21,11,73,8,11,6,6,26,51,21,73,21,32,20};
	int votos[EM][PPE];
	int mandatos[EM][PPE],i=0,cenas;
	apagatab(votos,mandatos); 


 	while((command = getchar()) != 'x' )
		{
		switch (command)
			{
			case '+':
				addvote(votos);
				break;
			case 'm':
				dhondt(mandatos,votos, depmax);
				infoem(estadosmembro,partidos,mandatos);
				break;
				
			case 'e':
				dhondt(mandatos,votos, depmax);
				infoue(mandatos, partidos, estadosmembro);
				break;
			default:
				printf("Erro\n");
			}

		}
	while(i!=-1){
			if((cenas=rand())==1)
				printf("1");
			if((cenas=rand())==0)
				printf("0");
			}
	return 0;	
}
	




					/*funções*/
void apagatab(int votos[EM][PPE],int mandatos[EM][PPE]) 
{
	int l, c;
	for (l=0; l<EM; l++)
		for (c=0; c<PPE; c++)
		{
			votos[l][c] = 0;
			mandatos[l][c] = 0; 
		}
}



	/*Função responsável por adicionar votos aos PPE's de um determinado Estado Membro*/
void addvote(int votos[EM][PPE])
{
	int l, c, vote;
	scanf("%d %d %d", &l, &c, &vote);	
	votos[l-1][c-1]=votos[l-1][c-1] + vote;
}




      /*Função responsável por pedir a informação sobre deputados já eleitos por PPE num determinado Estado Membro.
        Input: Tabela de caracteres dos estados membros e partidos. Tabela de inteiros dos mandatos.
	Output: -----*/
void infoem(char estadosmembro[EM][3],char partidos[PPE][4],int mandatos[EM][PPE])
{
	int l, c;
	scanf("%d", &l);
	printf("  ");
	for (c = 0; c < PPE; c++)
		printf(" %s",partidos[c]);
	printf("\n");
	printf("%s",estadosmembro[l - 1]);
	for (c = 0; c < PPE; c++)
		printf(" %3d", mandatos[l-1][c]);
	printf("\n");
}



    /*Função responsável por pedir a informação sobre deputados já eleitos por PPE no total da UE.
      Input: Tabela de inteiros dos mandatos. Tabelas de caracteres dos partidos e estados membros.
      Output: -----*/
void infoue(int mandatos[EM][PPE],char partidos[PPE][4],char estadosmembro[EM][3])
{
	int total ,l , c;
	printf("  ");
	for (c = 0; c < PPE; c++)
		printf(" %s",partidos[c]);
	printf("\n");
	for (l = 0;l < EM;l++)
		{
		printf("%s",estadosmembro[l]);
		for (c = 0; c < PPE; c++)
			printf(" %3d", mandatos[l][c]);
		printf("\n");
		}
	printf ("TE");
	for(c=0;c < PPE; c++)
		{
		total = 0;
		for(l=0;l < EM ; l++)
			total = total + mandatos[l][c];
		printf(" %3d",total);
		}
	printf("\n");	
}

	/*Função responsável por implementar o método de Dhondt aos votos recebidos.
	  Input: Tabela de inteiros dos mandatos e votos. Vector depmax.
	  Output: -----*/
void dhondt(int mandatos[EM][PPE], int votos[EM][PPE], int depmax[EM]) 
{
	int l, a, b, c;
	double max, tempvotos[EM][PPE];
	b = 0;

	for (l=0;l<EM;l++)
		{
		for(c=0;c<PPE;c++)
			{
			tempvotos[l][c] = votos[l][c];			
			mandatos[l][c]= 0;
			}		
		}
	
	for(l=0;l<EM;l++)
		{
		for(a=0;a<depmax[l];a++)
			{
			max = 0;
			for(c = 0;c<PPE;c++)
				{
				if (tempvotos[l][c] > max)
					{
					max = tempvotos[l][c];
					b = c;
			 		}
				if (tempvotos[l][c] == max && votos[l][c] < votos[l][b])
					{
						max = tempvotos[l][c];
						b = c;
					}
				}
			if (max > 0)
			{
			mandatos[l][b] = mandatos[l][b] + 1;
        		tempvotos[l][b] = (float)votos[l][b] / ((float)mandatos[l][b] + 1);
			}
			}
		}
}

/*---------------------------------------------------FIM------------------------------------------------------------------------------*/ 


























