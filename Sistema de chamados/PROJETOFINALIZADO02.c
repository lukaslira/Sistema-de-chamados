// AUTORIA: LUCAS ALVES DA CRUZ LIRA E RENNAN KLISMAN
// INSTITUI��O: IESP FACULDADES
// PROFESSORA: ALANA MORAIS
// DISCIPLINA: LINGUAGEM DE PROGRAMA��O 1

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#define ALANA_CLIENTES 15
#define CHAMADO "chamado.txt"
#define CADASTRO "cadastro.txt"
#define VISITA "visita.txt"
FILE * chamado;
FILE * cadastro; // bibliotecas utilizadas no projeto
FILE * visita;

struct s_cliente {
    char titulo[50];
    char descricao[100];
    char data[50];
    char protocolo[10];
    char telefone[30];
    char autoria[30];
    char status[30];
};

struct s_cliente clientes[ALANA_CLIENTES];
int i;
int n_clientes = 0;


void cadastraCliente(struct s_cliente cliente) {
    clientes[n_clientes] = cliente;
    n_clientes++;
}
struct s_cliente leDados() {
    struct s_cliente auxiliar;
    printf("\n\n");
    printf("AUTORIA: ");
    fflush(stdin);
    fgets(auxiliar.autoria,30,stdin);
	printf("TITULO: ");
    fflush(stdin);
    fgets(auxiliar.titulo, 50, stdin);
    printf("DATA: ");
    fflush(stdin);
    fgets(auxiliar.data, 30, stdin);
    printf("TELEFONE: ");
    fflush(stdin);
    fgets(auxiliar.telefone,30,stdin);
    printf("STATUS DO CHAMADO: ");
    fflush(stdin);
    fgets(auxiliar.status,30,stdin);
    printf("PROTOCOLO: ");
    fflush(stdin);
    fgets(auxiliar.protocolo, 10, stdin);
    
    
	return auxiliar;
}

void imprimeClientes() {
    for (i=0; i<n_clientes; i++) {
		printf("AUTORIA: %s",clientes[i].autoria);
		printf("TITULO: %s", clientes[i].titulo);
        printf("DATA DE ABERTURA: %s", clientes[i].data);
        printf("TELEFONE: %s",clientes[i].telefone);
        printf("PROTOCOLO: %s", clientes[i].protocolo);
        printf("STATUS DO CHAMADO: %s",clientes[i].status);
        printf("======================================================================================\n");
        
    }
}

void limpatela(){
	system("cls");

}

int menu() {
    int opcao;
	printf("\n======================================================================================\n");
	printf("                         PORTAL DO GERENTE\n");
	printf("======================================================================================\n");
    printf("\n1� - INSERIR CHAMADO DO CLIENTE\n");
    printf("2� - LISTAR CHAMADO\n");
    printf("3� - EXCLUIR CHAMADO\n");
    printf("4� - AGENDAR VISITA T�CNICA\n");
    printf("5� - RELAT�RIOS SOBRE OS CHAMADOS\n");
    printf("6� - ENVIAR MENSAGEM PARA O CLIENTE\n");
    printf("7� - SAIR DO SISTEMA\n");
    printf("\nSELECIONE UMA OP��O: ");
    scanf("%d", &opcao);
    return opcao;
}

void remover(int posicao) {
    int indice = posicao - 1;
    int i = 0;

    if ((posicao < 1) || (posicao > n_clientes)) {
        printf("\nPosicao invalida!\n");
        return;
    }


    if (posicao == n_clientes) {
        n_clientes--;
        return;
    }


    for (i=indice; i<n_clientes; i++) {
        clientes[i] = clientes[i+1];
    }
    n_clientes--;
}


int menuGerencia()
{
    int opcao_selecionada,opcliente2;;
    int rem = 0;
    struct s_cliente novo_cliente;
    int r,opcaolistar,op6;
    char endereco[40],nome[40],data[30],motivo[50],nome2[40],matricula[30],relatorio[70],telefone5[20],protocolo[8];
    char email[40],hora[30],numero2[30],mensagem2[30],nome5[30],nome3[30],email2[50],mensagem3[40];

    do {
        opcao_selecionada = menu();
        switch(opcao_selecionada) {
            case 1: 
            	
				printf("\n======================================================================================\n");
				printf("                         INSERIR CHAMADO DO CLIENTE\n");
				printf("======================================================================================\n");
				if (n_clientes == ALANA_CLIENTES) {
                    printf("\nBANCO DE DADOS LOTADO!\n");
                    
                }
                novo_cliente = leDados();
                cadastraCliente(novo_cliente);
                break;
            	
			case 2:
				system("cls");
				printf("======================================================================================\n");
				printf("                       LISTA DE CHAMADOS\n");
				printf("======================================================================================\n");
				imprimeClientes();
				
                break;
            case 3:
                
				printf("\nDIGITE A POSI��O DO CHAMADO QUE DESEJA EXCLUIR: ");
                scanf("%d", &r);
                remover(r);
                printf("CHAMADO REMOVIDO COM SUCESSO\n");
                break;
            case 4:
           		system("cls");
				printf("======================================================================================\n");
				printf("                         PEDIDO DE VISITA T�CNICA EM DOM�CILIO\n");
				printf("======================================================================================\n");
				printf("\nNOME DO CLIENTE: ");
           		fflush(stdin);
           		gets(nome);
           		printf("DATA DA VISITA: ");
           		fflush(stdin);
           		gets(data);
           		printf("HORA DA VISITA: ");
           		fflush(stdin);
           		gets(hora);
           		printf("EMAIL DO CLIENTE: ");
           		fflush(stdin);
           		gets(email);
           		printf("TELEFONE DO CLIENTE: ");
           		fflush(stdin);
           		gets(telefone5);
           		printf("ENDERE�O: ");
           		fflush(stdin);
           		gets(endereco);
           		printf("MOTIVO: ");
           		fflush(stdin);
           		gets(motivo);
           		printf("\nCONFIRMA��O DA VISITA SER� ENVIADA PARA O EMAIL DO CLIENTE\n");
           		printf("GERENTE LOCAL: SEBASTI�O DA SILVA MARCULINO\n");
           		printf("EMAIL: SEBASTI�O_CORPORATION@GMAIL.COM\n");
           		break;
           	case 5:
           		system("cls");
				printf("======================================================================================\n");
				printf("                         RELAT�RIO DOS CHAMADOS\n");
				printf("======================================================================================\n");
				printf("\nNOME DO GERENTE: ");
           		fflush(stdin);
           		gets(nome2);
           		printf("MATRICULA: ");
           		fflush(stdin);
           		gets(matricula);
           		printf("N�MERO DE PROTOCOLO DO CHAMADO: ");
           		fflush(stdin);
           		gets(protocolo);
           		printf("RELAT�RIO: ");
           		fflush(stdin);
           		gets(relatorio);
           		printf("\nRELAT�RIO REALIZADO COM SUCESSO\n");
           		break;
           	case 6:
           		system("cls");
           		printf("======================================================================================\n");
				printf("                         MENSAGEM PARA O CLIENTE\n");
				printf("======================================================================================\n");
				printf("\n1� - MENSAGEM VIA TORPEDO\n");
				printf("2� - MENSAGEM VIA EMAIL\n");
				printf("\nESCOLHA UMA OP��O: ");
				scanf("%d",&op6);
				switch(op6)
				{
					case 1:
						printf("\nNOME DO CLIENTE: ");
						fflush(stdin);
						gets(nome5);
						printf("INFORME O N�MERO DO CLIENTE: ");
						fflush(stdin);
						gets(numero2);
						printf("MENSAGEM: ");
						fflush(stdin);
						gets(mensagem2);
						printf("\nTORPEDO ENVIADO COM SUCESSO PARA O CLIENTE\n");
						break;
					case 2:
						printf("\nNOME DO CLIENTE: ");
						fflush(stdin);
						gets(nome3);
						printf("INFORME O EMAIL DO CLIENTE: ");
						fflush(stdin);
						gets(email2);
						printf("MENSAGEM: ");
						fflush(stdin);
						gets(mensagem3);
						printf("\nEMAIL ENVIADO COM SUCESSO\n");
						break;
						
				}
				break;
           	case 7:
           		printf("\nSAINDO DO SISTEMA\n");
           		break;
           		
            default:
                printf("\nOP��O INV�LIDA\n");
                printf("TENTE NOVAMENTE\n");
                break;
        }
    }
    while (opcao_selecionada<7);
    return 0;
}
void formasAtendimento() //formas de atendimento ao cliente fun��o
{
	setlocale(LC_ALL,"portuguese");
	int opcao10,telefone2,senha;
	char mensagem[100],permissao,nome2[30],nome4[30],endereco[50],referencia[50],nome5[30],dia[30],email2[50],telefone3[20];
	char hora[30];
	system ("color 0E");
	
	printf("======================================================================================\n");
	printf("                         OP��ES DE ATENDIMENTO AO CLIENTE\n");
	printf("======================================================================================\n");
	printf("\n1� - ATENDIMENTO VIRTUAL: MENSAGEM\n");
	printf("2� - ATENDIMENTO VIRTUAL: CHAMADA DE VOZ\n");
	printf("3� - ATENDIMENTO REMOTO\n");
	printf("4� - VISITA T�CNICA\n");
	printf("5� - ATENDIMENTO PRESENCIAL: EMPRESA\n");
	printf("\nESCOLHA UMA OP��O ACIMA: ");
	scanf("%d",&opcao10);
	switch(opcao10)
	{
		case 1:
			system("cls");
			printf("======================================================================================\n");
			printf("                         INFORMA��ES SOBRE O CHAMADO\n");
			printf("======================================================================================\n");
			printf("\nSENHOR(A) CLIENTE ENVIE-NOS SUA MENSAGEM PARA PODERMOS AJUD�-LO\n");
			printf("MENSAGEM: ");
			fflush(stdin);
			gets(mensagem);
			printf("\nINFORME SEU NOME: ");
			fflush(stdin);
			gets(nome5);
			printf("POR FAVOR INFORME UM N�MERO PARA CONTATO: ");
			fflush(stdin);
			scanf("%d",&telefone2);
			printf("\nAGRADECEMOS SUA MENSAGEM SENHOR(A) %s\n",nome5);
			printf("LOGO ENTRAREMOS EM CONTATO!!\n");
			break;

		case 2:
			system("cls");
			printf("======================================================================================\n");
			printf("                         MEIOS DE CONTATO\n");
			printf("======================================================================================\n");
			printf("SENHOR(A) CLIENTE SEGUE ABAIXO OS TELEFONES PARA CONTATO:\n");
			printf("\nSEDE DE JO�O PESSOA: 4002-8922\n");
			printf("SEDE DE CAMPINA GRANDE: 4044-9666\n");
			printf("SEDE DE BAYEUX: (83)98657-2213\n");
			printf("EMAIL: CORPORATION_ALANAS@GMAIL.COM\n");
			printf("\nHOR�RIO DE FUNCIONAMENTO:\n");
			printf("MANH�: 07:30 �S 12:45\n");
			printf("TARDE: 13:30 �S 17:30\n");
			break;
		case 3:
			system("cls");
			printf("======================================================================================\n");
			printf("                         ATENDIMENTO REMOTO - ALANA'S CORPORATION\n");
			printf("======================================================================================\n");
			printf("\nSENHOR(A) CLIENTE PARA RESPONDER NOSSAS PERGUNTAS, DIGTE [S] PARA SIM E [N] PARA N�O.\n");
			printf("COM SUA PERMISS�O TEREMOS ACESSO AO SEU EQUIPAMENTO.\n");
			printf("PARA QUE ASSIM POSSAMOS CORRIGIR O SEU PROBLEMA.\n");
			printf("PARA A SUA SEGURAN�A, AO FINALIZAR O ATENDIMENTO, A PERMISS�O PARA A CONEX�O SER� EXPIRADA.\n");
			printf("\nO SENHOR(A) PERMITE O ACESSO AO EQUIPAMENTO? ");
			fflush(stdin);
			scanf("%c",&permissao);
			if(permissao=='S' || permissao=='s')
			{
				printf("\nVEJO QUE O ROTEADOR DA SUA RESID�NCIA FOI DESCONFIGURADO.\n");
				printf("FAREI UMA CONFIGURA��O DE VOLTA.\n");
				printf("\nPOR FAVOR, INFORME UM NOME PARA A SUA REDE: ");
				fflush(stdin);
				gets(nome2);
				printf("\nAGORA, INFORME UMA SENHA: ");
				fflush(stdin);
				scanf("%d",&senha);
				printf("\nO SEU ROTEADOR FOI CONFIGURADO COM SUCESSO!!\n");
				printf("\nNOME DA REDE: %s\n",nome2);
				printf("SENHA DA REDE: %d\n",senha);
				printf("\nAGRADECEMOS A SUA CONFIAN�A!!\n");
				printf("ATENDIMENTO FINALIZADO...\n");
				printf("\nATENDENTE: JO�O AGRIPINO\n");

			}
			else
			{
				printf("\nACESSO NEGADO!!\n");
				printf("ATENDIMENTO FINALIZADO\n");
			}
			break;
		case 4:
			system("cls");
			visita=fopen(VISITA,"a+b");
			if(visita==NULL)
			{
				visita=fopen(VISITA,"r+b");
			}
			else
				{
				
				printf("======================================================================================\n");
				printf("                         VISITA T�CNICA EM DOM�CILIO\n");
				printf("======================================================================================\n");
				printf("\nSENHOR(A) CLIENTE, PARA A VISITA DE UM T�CNICO AT� SUA CASA\n");
				printf("NECESSITAMOS DE ALGUMAS INFORMA��ES\n");
				printf("\nNOME: ");
				fflush(stdin);
				gets(nome4);
				printf("ENDERE�O: ");
				fflush(stdin);
				gets(endereco);
				printf("PONTO DE REFER�NCIA: ");
				fflush(stdin);
				gets(referencia);
				printf("TELEFONE PARA CONTATO: ");
				fflush(stdin);
				gets(telefone3);
				printf("EMAIL: ");
				fflush(stdin);
				gets(email2);
				printf("INFORME UMA DATA PARA O AGENDAMENTO DA VISITA: ");
				fflush(stdin);
				gets(dia);
				printf("INFORME UMA HORA DO DIA: ");
				fflush(stdin);
				gets(hora);
				printf("\nAGENDAMENTO ENVIADO PARA O GERENTE LOCAL...\n");
				printf("LOGO O T�CNICO IR� A SUA RESID�NCIA.\n");
				fprintf(visita,"======================================================================================\n");
				fprintf(visita,                         "VISITA T�CNICA EM DOM�CILIO\n");
				fprintf(visita,"======================================================================================\n");
				fprintf(visita,"NOME: %s\n",nome4);
				fprintf(visita,"ENDERE�O: %s\n",endereco);
				fprintf(visita,"PONTO DE REFER�NCIA: %s\n",referencia);
				fprintf(visita,"TELEFONE PARA CONTATO: %s\n",telefone3);
				fprintf(visita,"DATA PARA A VISITA: %s\n",dia);
				fprintf(visita,"HORA DA VISITA: %s\n",hora);
				fprintf(visita,"EMAIL: %s\n",email2);
				fclose(visita);
				}
			break;
		case 5:
			printf("======================================================================================\n");
			printf("                         LOCALIZA��O DAS SEDES\n");
			printf("======================================================================================\n");
			printf("\nSEDE DE JO�O PESSOA - MANA�RA\n");
			printf("ENDERE�O: AVENIDA GOVERNADOR FL�VIO RIBEIRO COUTINHO, N� 463\n");
			printf("PONTO DE REFER�NCIA: PR�XIMO AO SHOPPING MANA�RA\n");
			printf("\nSEDE DE BAYEUX - ALTO DA BOA VISTA\n");
			printf("ENDERE�OO: RUA EDVALDO PEREIRA VASCONCELOS, N� 544\n");
			printf("PONTO DE REFER�NCIA: PR�XIMO AO RACHIDE BAR\n");
			printf("\nSEDE DE CAMPINA GRANDE - MIRANTE\n");
			printf("ENDERE�O: AVENIDA PREFEITO SEVERINO BEZERRA CABRAL, N� 394\n");
			printf("PONTO DE REFER�NCIA: VILLAS BURGUER\n");
			break;
	}
}

void clienteCadastrado() //fun��o do cliente cadastrado
{

	setlocale(LC_ALL,"portuguese");
	char titulo[50],descricao[100],autoria[50],feedback[100],telefone[50],pergunta,pergunta2,nome3[20];
	int opcao3,protocolo,opcaocontinua;
	system ("color 0E");
	srand((unsigned) time(NULL));

	do {
	
	printf("\nSELECIONE UMA OP��O ABAIXO:\n");
	printf("\n1� - CHAMADO RELACIONADO A INTERNET - CONEX�O E ACESSO\n");
	printf("2� - ENVIAR FEEDBACK DO PROCESSO PARA A EQUIPE\n");
	printf("3� - FORMAS DE ATENDIMENTO\n");
	printf("4� - CHAMADOS RELACIONADOS A SERVI�OS DE REDE\n");
	printf("5� - SAIR DO SISTEMA\n");
	printf("\nINFORME UMA OP��O: ");
	fflush(stdin);
	scanf("%d",&opcao3);
	switch(opcao3)
	{
		case 1:
			system("cls");
			chamado=fopen(CHAMADO,"a+b");
			if(chamado==NULL)
			{
				chamado=fopen(CHAMADO,"r+b");
			}
			else
				{
				system("cls");
				printf("======================================================================================\n");
				printf("                         CHAMADO RELACIONADO A INTERNET - CONEX�O E ACESSO\n");
				printf("======================================================================================\n");
				printf("\nTITULO DO CHAMADO: ");
				fflush(stdin);
				gets(titulo);
				printf("DESCRI��O DO CHAMADO: ");
				fflush(stdin);
				gets(descricao);
				printf("AUTORIA DO CHAMADO: ");
				fflush(stdin);
				gets(autoria);
				printf("TELEFONE PARA CONTATO: ");
				fflush(stdin);
				gets(telefone);
				fprintf(chamado,"======================================================================================\n");
				fprintf(chamado,"PROBLEMAS COM CONEX�O E ACESSO A INTERNET\n");
				fprintf(chamado,"======================================================================================\n");
				fprintf(chamado,"TITULO DO CHAMADO: %s\n",titulo);
				fprintf(chamado,"DESCRI��O DO CHAMADO: %s\n",descricao);
				fprintf(chamado,"AUTORIA DO CHAMADO: %s\n",autoria);
				fprintf(chamado,"TELEFONE PARA CONTATO: %s\n",telefone);
				fprintf(chamado,"PROTOCOLO: %d\n",1000+(rand())%3000);
				printf("\nCHAMADO REALIZADO COM SUCESSO!!!\n");
			    fclose(chamado);
				}

			break;

		case 2:
			system("cls");
			printf("======================================================================================\n");
			printf("                         FEEDBACK\n");
			printf("======================================================================================\n");
			printf("\nFA�A UM FEEDBACK DO NOSSO ATENDIMENTO\n");
			printf("\nA SUA OPNI�O � DE SUMA IMPORT�NCIA PARA NOSSO APRIMORAMENTO\n");
			printf("\nINFORME SEU NOME: ");
			fflush(stdin);
			gets(nome3);
			printf("FEEDBACK: ");
			fflush(stdin);
			gets(feedback);
			printf("\nA ALANA'S CORPORATION AGRADECE SEU FEEDBACK\n");
			break;
		case 3:
			system("cls");
			formasAtendimento();
			break;
		case 4:
			chamado=fopen(CHAMADO,"a+b");
			if(chamado==NULL)
			{
				chamado=fopen(CHAMADO,"r+b");
			}
			else
				{
				system("cls");
				printf("======================================================================================\n");
				printf("                         CHAMADO RELACIONADO A SERVI�OS DE REDE\n");
				printf("======================================================================================\n");
				printf("\nTITULO DO CHAMADO: ");
				fflush(stdin);
				gets(titulo);
				printf("DESCRI��O DO CHAMADO: ");
				fflush(stdin);
				gets(descricao);
				printf("AUTORIA DO CHAMADO: ");
				fflush(stdin);
				gets(autoria);
				printf("TELEFONE PARA CONTATO: ");
				fflush(stdin);
				gets(telefone);
				fprintf(chamado,"======================================================================================\n");
				fprintf(chamado,                       "PROBLEMAS RELACIONADOS A SERVI�OS DE REDE\n");
				fprintf(chamado,"======================================================================================\n");
				fprintf(chamado,"TITULO DO CHAMADO: %s\n",titulo);
				fprintf(chamado,"DESCRI��O DO CHAMADO: %s\n",descricao);
				fprintf(chamado,"AUTORIA DO CHAMADO: %s\n",autoria);
				fprintf(chamado,"TELEFONE PARA CONTATO: %s\n",telefone);
				fprintf(chamado,"PROTOCOLO: %d\n",1000+(rand())%3000);
				printf("\nCHAMADO REALIZADO COM SUCESSO!!!\n");
			    fclose(chamado);
				}
			break;
		case 5:
			printf("DESEJA SAIR DO SISTEMA? [S] OU [N]: ");
			fflush(stdin);
			scanf("%c",&pergunta2);
			if(pergunta2=='S' || pergunta2=='s')
			{
				printf("ENCERRANDO SISTEMA.....\n");
        		printf("A ALANA'S CORPORATION AGRADECE A SUA VISITA\n");
        		printf("........................\n");
        		
			}
			
			
			break;
			

	}

	}while(opcao3<5);


}

void clienteNaocadastrado() // fun��o do cliente n�o cadastrado
{

	char nome[50],endereco[50],email[50],cidade[100],estado[50],telefone2[20];
	setlocale(LC_ALL,"Portuguese");
	system ("color 0E");
	
	cadastro=fopen(CADASTRO,"a+b");
	if(cadastro==NULL)
	{
		cadastro=fopen(CADASTRO,"r+b");
	}
	else
		{
		
		printf("\nNOME COMPLETO: ");
		fflush(stdin);
		gets(nome);
		printf("ENDERE�O: ");
		fflush(stdin);
		gets(endereco);
		printf("EMAIL: ");
		fflush(stdin);
		gets(email);
		printf("CIDADE: ");
		fflush(stdin);
		gets(cidade);
		printf("ESTADO: ");
		fflush(stdin);
		gets(estado);
		printf("TELEFONE: ");
		fflush(stdin);
		gets(telefone2);
		fprintf(cadastro,"======================================================================================\n");
		fprintf(cadastro,                              "CADASTRAMENTO ONLINE\n");
		fprintf(cadastro,"======================================================================================\n");
		fprintf(cadastro,"NOME COMPLETO: %s\n",nome);
		fprintf(cadastro,"ENDERE�O: %s\n",endereco);
		fprintf(cadastro,"EMAIL: %s\n",email);
		fprintf(cadastro,"CIDADE: %s\n",cidade);
		fprintf(cadastro,"ESTADO: %s\n",estado);
		fprintf(cadastro,"TELEFONE: %s\n",telefone2);
		fclose(cadastro);
		clienteCadastrado();
		}

}

int main(void) //fun��o principal do c�digo
{
	int opcaoAcesso,opcliente,opcaoAtend,opcaoAtend2;
	char atendimento;
	char login[60] = "SEBASTIAO@321";
	char login1[60];
	char senha[40] = "SE@321";
	char senha1[40];
	setlocale(LC_ALL,"portuguese");
	system ("color 0E");
	
	do{
		system("cls");
		printf("======================================================================================\n");
		printf("                         ALANA'S CORPORATION - SISTEMA GERENCIAL \n");
		printf("======================================================================================\n");
		printf("\nMENU PRINCIPAL\n");
		printf("\n1� - PORTAL DO CLIENTE\n");
		printf("2� - PORTAL DO GERENTE\n");
		printf("3� - SAIR DO SISTEMA COM SEGURAN�A\n");
		printf("\nESCOLHA UMA OP��O DE ACESSO: ");
		scanf("%d",&opcaoAcesso);

switch(opcaoAcesso)
{
    case 1:

		system("cls");
		printf("======================================================================================\n");
		printf("                         PORTAL DO CLIENTE\n");
		printf("======================================================================================\n");
        printf("\nATRAV�S DO PORTAL, O CLIENTE PODER� UTILIZAR OS SEGUINTES SERVI�OS: \n");
        printf("\n1� - ABRIR CHAMADOS\n");
        printf("2� - EXCLUIR CHAMADOS\n");
        printf("3� - ENVIAR FEEDBACK PARA A EQUIPE\n");
        printf("4� - ATENDIMENTO REMOTO\n");
        printf("5� - ATENDIMENTO VIRTUAL(CHAMADA DE VOZ/MENSAGEM)\n");
        printf("6� - SOLICITAR VISITA T�CNICA\n");
        printf("\nJ� � CADASTRADO NO SISTEMA? DIGITE [1] PARA SIM E [0] PARA N�O: ");
        fflush(stdin);
        scanf("%d",&opcliente);
        switch(opcliente)
        {
            case 1:

				clienteCadastrado();
                break;
            case 0:
				system("cls");
				printf("======================================================================================\n");
				printf("                         CADASTRAMENTO ONLINE\n");
				printf("======================================================================================\n");
				clienteNaocadastrado();
            	break;

        }
        break;
    case 2:
		printf("\nENTRE CORRETAMENTE COM SEUS DADOS PARA ACESSAR O PORTAL\n");
		printf("\nLOGIN: ");
		scanf("%s",login1);
		fflush(stdin);
		printf("SENHA: ");
		scanf("%s",&senha1);
		if(strcmp(login,login1)==0 && strcmp(senha,senha1)==0)
		{
			printf("\nACESSO LIBERADO!!\n");
			menuGerencia();
		}
		else
			printf("\nACESSO NEGADO, TENTE NOVAMENTE!!\n");
		
        break;
    case 3:
		printf("\nSISTEMA SENDO ENCERRADO...\n");
        printf("PARA MELHOR ATEND�-LOS, DEIXE SUA AVALIA��O!\n");
		printf("\nDESEJA AVALIAR NOSSA PLATAFORMA DE ATENDIMENTO? [1] PARA SIM, [0] PARA N�O: ");
        scanf("%d",&opcaoAtend);
        if(opcaoAtend==1)
        {

			printf("\n1� - ATENDIMENTO EXCELENTE\n");
        	printf("2�- ATENDIMENTO �TIMO\n");
        	printf("3�- ATENDIMENTO BOM\n");
        	printf("4�- ATENDIMENTO P�SSIMO/RUIM\n");
        	printf("\nESCOLHA UMA OP��O: ");
        	scanf("%d",&opcaoAtend2);
        	switch(opcaoAtend2)
        	{
        		case 1:
        			printf("\nAGRADECEMOS SUA AVALIA��O...\n");
        			printf("A ALANA'S CORPORATION AGRADECE SUA VISITA!\n");
					printf("SISTEMA FINALIZADO COM SUCESSO...\n");
					break;
				case 2:
					printf("\nAGRADECEMOS SUA AVALIA��O...\n");
        			printf("A ALANA'S CORPORATION AGRADECE SUA VISITA!\n");
					printf("SISTEMA FINALIZADO COM SUCESSO...\n");
					break;
				case 3:
					printf("\nAGRADECEMOS SUA AVALIA��O...\n");
        			printf("A ALANA'S CORPORATION AGRADECE SUA VISITA!\n");
					printf("SISTEMA FINALIZADO COM SUCESSO...\n");
					break;
				case 4:
					printf("\nAGRADECEMOS SUA AVALIA��O...\n");
					printf("ESTAMOS SEMPRE BUSCANDO A MELHOR FORMA PARA ATENDER NOSSOS CLIENTES\n");
        			printf("A ALANA'S CORPORATION AGRADECE SUA VISITA!\n");
					printf("SISTEMA FINALIZADO COM SUCESSO...\n");
					break;
			}

		}
		else
			{

			printf("\nENCERRANDO SISTEMA!\n");
			printf("A ALANA'S CORPORATION AGRADECE SUA VISITA!\n");
			printf("SISTEMA FINALIZADO COM SUCESSO...\n");
			}


        break;


}
	}while(opcaoAcesso<3);

	
}



