#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_email 100
#define MAX_senha 100

typedef struct {
    char nome[50];
    char email[MAX_email];
    char senha[MAX_senha];
} Usuario;

int CadastrarUsuario(){
    Usuario usuario;
    int total_usuarios = 0;
    int Emailjaexiste = 0;

    printf("Informe o nome do usuario: "); // Leitura do nome do usuario
    scanf(" %[^\n]",usuario.nome); //Permite Espaços

    //Leitura do email do usuario
    printf("\nInforme o email: ");
    scanf(" %s",usuario.email);

    //Verifica se o email ja existe
    if(strcmp(Emailjaexiste, usuario.email) == 0){
        printf("O email digitado ja foi cadastrado.\n");
        //break; Adicionar quando for tratar os dados com arquivos
    }

    //if email existe return

    //Lê a senha do usuario
    // Fazer função mascarar senha
    printf("Insira a senha: ");
    scanf(" %s",&usuario.senha);

    total_usuarios++;

    return 0;
}
