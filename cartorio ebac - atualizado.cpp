#include <stdio.h>  //biblioteca de comunica��o
#include <stdlib.h> //biblioteca de espa�o de mem�ria 
#include <locale.h> //biblioteca de localiza��o de texto 
#include <string.h> //biblioteca resons�vel por cuidar das strings 


int registro() //fun��o responsavel por cadastrar usuarios no sistema 
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
	//inicio da cria��o de variageis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis 
	
	printf("Digite o CPF a ser cadastrado:"); //coletando infroma��es do usuario 
	scanf("%s",cpf); //salvando strings 
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings 
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo 
	fprintf(file,cpf); //salva o valor da variavel 
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
    
	printf("Digite o nome a ser cadastrado: ");	
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o cargo a ser cadastrado");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf ("digite o cpf a ser consultado");
	scanf("%s" ,cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	
	{
		printf("N�o foi possivel abrir arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

 int deletar()
 {
    char cpf[40];
    
    printf ("Digite o CPF a ser deletado:");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
  
    if(file == NULL)
    {
    	printf("Usu�rio deletado do sistema!. \n");
    	system("pause");
	}
	

   }



int main() {

int  opcao=0; //Definindo vari�veis
int  x=1;
	
for (x=1; x=1;)
 {
	 system("cls"); 
	 setlocale(LC_ALL, "portuguese"); //definindo linguagem 
		
	 printf("Cart�rio da EBAC\n");  //inicio menu
	 printf("Escolha a op��o desejada no menu principal:\n\n");
	 printf("\t1 - Registrar nomes\n\n");
	 printf("\t2 - Consultar nomes\n\n");
	 printf("\t3 - Deletar nomes\n\n"); 
	 printf("\t4 - Encerrar sistema\n\n");
	 printf("Op��o: "); //fim menu
	
	 scanf("%d", &opcao); //armazenamento a escolha do usuario 
	
	 system("cls");
	 
	 switch(opcao)
	 {
	 	 case 1: 
	 	 registro(); //chamada de fun��es 
         break;
        
         case 2:
         consulta(); //chamada de fun��es
		 break;
		
		 case 3: 
		 deletar(); //chamada de fun��es
		 break;
		 
		 case 4:
		 printf("\n Obrigado por acessar sistema, seja sempre bem-vindo!\n");
		 return 0;
		 break;
		 
		 default:
		 printf("Op��o n�o disponivel, escolha outra op��o!\n");
	     system("pause");
	     break;
	     }
     }
}


