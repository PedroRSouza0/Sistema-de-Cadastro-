#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "Tela.c"
#include "Cadastrar.c"

int main(void){
    int opcao;

while(true){

    tela();

    printf("\nDigite a sua opcao abaixo:\n");
    scanf("%d",&opcao);  

    switch(opcao){
        case 1: //Cadastrar usuario
            system("cls");
            CadastrarUsuario();
            break;
        case 2:
            break;
        case 3:
            system("cls");
            printf("Obrigado por usar nosso sistema!\n");
            printf("Saindo...\n");    
            Sleep(2000);
            break; //Força a saída do Switch case
        default:
            printf("Digite uma opção válida\n");
            break;    

    }
    if(opcao == 3)
        break; // Força a saída do loop
}   
    printf("Programa Encerrado\n");
    return 0;
}