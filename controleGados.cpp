#include <stdio.h> //cabeçalho padrão de entrada/saída
#include <iostream> //Recursos de entrada/saída baseados em fluxo. 
#include <locale.h> //Modifica a linguagem

#define FAZENDA_GADOS 100 //Define maximo de gados em 100

//Armazena os dados
typedef struct Gado {	
	char codigo[5];
	char abate;	
	float leite;	
	int alimento, mes, ano;
} Gado;

Gado fazenda[FAZENDA_GADOS];


//Calcula a idade do animal usando apenas o ano
int calcularIdade(int ano) {
    int anoAtual = 2024;
    int idade = anoAtual - ano;
    return idade;
}

//Imprime a quantidade de leite produzido.
void imprimir_leite(Gado fazenda[], int quantidade_gado) {
    float totalLeite = 0;

    for (int i = 0; i < quantidade_gado; ++i) {
        totalLeite += fazenda[i].leite;
    }

    printf("\n\tTotal de leite produzido por semana: %.2f litros", totalLeite);
}
//Imprime a quantidade leite apos abate
void imprimir_leiteAbate(Gado fazenda[], int quantidade_gado) {
    float totalLeite = 0;

    for (int i = 0; i < quantidade_gado; ++i) {
    	if (fazenda[i].abate == 'N'){
        	totalLeite += fazenda[i].leite;
			}
    }

    printf("\n\tTotal de leite produzido por semana após o abate: %.2f litros\n", totalLeite);
}
//Imprime a quantidade de alimento consumido
void imprimir_alimento(Gado fazenda[], int quantidade_gado) {
    float totalAlimento = 0;

    for (int i = 0; i < quantidade_gado; ++i) {
        totalAlimento += fazenda[i].alimento;
    }

    printf("\n\tTotal de alimento gasto por semana: %.2f kg\n", totalAlimento);
}
//Imprime a quantidade de alimento consumido após abate
void imprimir_alimentoAbate(Gado fazenda[], int quantidade_gado) {
    float totalAlimento = 0;

    for (int i = 0; i < quantidade_gado; ++i) {
    	if (fazenda[i].abate == 'N'){
        	totalAlimento += fazenda[i].alimento;
    	}
    }

    printf("\tTotal de alimento gasto por semana após abate: %.2f kg\n\n", totalAlimento);
}
//Imprime a quantidade de abates
void imprimir_abates(Gado fazendo[], int quantidade_gado){
	int gadosAbate = 0;
	for (int i = 0; i < quantidade_gado; i++){
		if(fazenda[i].abate == 'S'){
			gadosAbate++;
		}
	}
	printf("\nTotal de gados que foram para o abate: %d\n", gadosAbate);
}


int main() {	
	setlocale(LC_ALL, "");	//Modifica linguagem, permite acentos
	Gado gado;	// Atalho da struct
	int opcao, i;	
	int quantidade_gado = 0;
	
	
	printf("\n\n\t\t\t\t\t BEM-VINDO AO GERENCIAMENTO DE GADOS.\t\t\t\t\t\t\n");
	do{		
		printf("\n\n Para adicionar o gado, digite: 1");
		printf("\n Para acessar Informações sobre a Fazenda, digite: 2");
		printf("\n Para sair, digite: 3 \n");
		printf("\n Digite a sua opção: ");	
		scanf("%d",&opcao);		
		
		switch (opcao){		
			case 1:	//Opçao para adicionar gados ao sistema	
				if (quantidade_gado < FAZENDA_GADOS) {
	                printf("\n\n\t\t\t\t\t\t MENU DE INFORMAÇÕES \t\t\t\t\t\t\n\n\n");
	                printf("\n\tCódigo do Gado: ");
	                scanf("%s", gado.codigo);
	                printf("\tQuantidade de leite que produz: ");
	                scanf("%f", &gado.leite);
	                printf("\tQuantidade de alimento que consome: ");
	                scanf("%d", &gado.alimento);
	                printf("\tMês de nascimento: ");
	                scanf("%d", &gado.mes);
	                printf("\tAno de nascimento: ");
	                scanf("%d", &gado.ano);
	 
	 				//Verifica se o gado adicionado, está apto ou não para o abate
	                int idade = calcularIdade(gado.ano);
	                if (idade > 5 || (idade == 5 && gado.mes <= 6) || (gado.leite < 40 && gado.leite > 0) || 
					(gado.leite >= 50 && gado.leite <= 70 && gado.alimento >= 50)) {
	                    	gado.abate = 'S';
	                    	printf("\tCampo abate preenchido.");
	                } else {
	                    	gado.abate = 'N';
	                    	printf("\tCampo abate não preenchido.");
	                    }
	                fazenda[quantidade_gado++] = gado;
	            } else {
	            	//Limite de gados disponiveis
	                printf("A fazenda já atingiu o limite de 100 gados.\n");
	            }
			break;
			
			case 2: //Imprime os dados coletados do case1
			printf("\n\nQuantidade total de gados %d\n", quantidade_gado);
			imprimir_leite(fazenda, quantidade_gado);
			imprimir_alimento(fazenda, quantidade_gado);
			imprimir_abates(fazenda, quantidade_gado);
			imprimir_leiteAbate(fazenda, quantidade_gado);
			imprimir_alimentoAbate(fazenda, quantidade_gado);
			break;
			
			case 3: //Opcao para sair do programa
			printf("\nFinalizando programa...\n");
			break;
							
			default: //Caso digite opcao não existente
				printf("\nDigite novamente...\n");		
				break;		
			}	
	}while(opcao != 3);	// Programa roda enquanto o usuario não escolher sair

return 0;
}
