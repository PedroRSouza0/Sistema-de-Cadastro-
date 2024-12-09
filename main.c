#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "Tela.h"
#include "Cadastrar.h"
#include "Login.h"

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
            system("cls");
            if (Login()){
                telaLogado();}
            else   
                printf("Falha no login, tente novamente\n");    
            break;
        case 3:
            system("cls");
            printf("Obrigado por usar nosso sistema!\n");
            printf("Saindo...\n");    
            Sleep(2000);
            break; //Força a saída do Switch case
        default:
            printf("Por favor, digite uma opção valida\n");
            break;    

    }
    if(opcao == 3)
        break; // Força a saída do loop
}

    printf("Programa Encerrado\n");
    return 0;
}