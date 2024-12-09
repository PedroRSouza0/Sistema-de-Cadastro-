#include "Cadastrar.c"
#include "Tela.c"
#include <stdbool.h>

void Login(){
    //Abre o arquivo
    FILE *arquivo =  fopen("usuarios.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo, Tente novamente\n");
        return;
    }

    char EmailLogin[MAX_email], SenhaLogin[MAX_senha]; // Variaveis de Entrada
    char EmailArquivo[MAX_email], SenhaArquivo[MAX_senha]; // Variaveis para comparação
    bool Login = false; 

    // Entrada do Login
    printf("Digite o seu email:\n");
    scanf("")







    // Leitura da senha e email
    // Compara com a do arquivo
    // Se True deixa logat
    // Se False retorna uma mensagem de erro
    // Fecha o arquivo
    //IF usuarioscadastrados == 0 mensagem de erro

}