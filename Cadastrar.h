#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX_email 100
#define MAX_senha 100

typedef struct {
    char nome[50];
    char email[MAX_email];
    char senha[MAX_senha];
} Usuario;

void MascararSenha(char *senha, int max_tamanho){
    int i = 0;
    char ch; 
while(1){
    ch = getch(); // Captura um caractere sem exibir na tela

    if(ch == '\n' || ch == '\r'){ //Enter (finaliza a senha)
        break;
    } else if(ch == '\b' || ch == 127){ //Backspace
        if(i > 0){
            i--;
            printf("\b \b"); //Remove o ultimo asterisco da tela
        }
    }else if(i < max_tamanho - 1){ //Limita o tamanho da senha
            senha[i++] = ch;
            printf("*"); //mostra um asterisco
    }
}
    senha[i] = '\0'; //Finaliza a string com um caractere nulo
    printf("\n");

}

void SalvarUsuarioEmArquivo(Usuario usuario, int total_usuarios) {
    FILE *arquivo = fopen("usuarios.txt", "a"); // Abre o arquivo em modo de adição

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Escreve os dados do usuário no arquivo
    fprintf(arquivo, "Total Cadastrados : %d\nNome: %s\nEmail: %s\nSenha: %s\n\n", total_usuarios, usuario.nome, usuario.email, usuario.senha);
    fclose(arquivo); // Fecha o arquivo
    
}


int CadastrarUsuario(){
    Usuario usuario;
    char Emailjaexiste[MAX_email] = " ";
    char saida = ' ';
    int total_usuarios = 0;

while(1){
    total_usuarios++;
    printf("Informe o nome do usuario: "); // Leitura do nome do usuario
    scanf(" %[^\n]",usuario.nome); //Permite Espaços

    //Leitura do email do usuario
    printf("\nInforme o email: ");
    scanf(" %s",usuario.email);

    //Verifica se o email ja existe
    if(strcmp(Emailjaexiste, usuario.email) == 0){
        printf("O email digitado ja foi cadastrado.\n");
        return 1;
        //break; Adicionar quando for tratar os dados com arquivos
    }

    //if email existe return

    //Lê a senha do usuario
    // Fazer função mascarar senha
    printf("Insira a senha: ");
    MascararSenha(usuario.senha, MAX_senha);
    

    printf("\nUsuario cadastrado com sucesso!\n");
    SalvarUsuarioEmArquivo(usuario, total_usuarios);

    printf("Deseja cadastrar um novo usuario?[S/N]\n");
    scanf(" %c",&saida);

    if(toupper(saida) == 'N'){
        system("cls");
        break;
}
}
    return 0;
}
