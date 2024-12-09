#include "Cadastrar.c"
#include "Tela.c"
#include <stdbool.h>


bool Login(){
    Usuario usuario;
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
    scanf(" %s",EmailLogin);
    // Entrada da Senha
    printf("Inisra a sua senha:\n");
    MascararSenha(SenhaArquivo, MAX_senha);

// Leitura do arquivo e comparação
    while(fscanf(arquivo, "%s %s", EmailArquivo, SenhaArquivo) != EOF){
        if(strcmp(EmailLogin, EmailArquivo) == 0 && strcmp(SenhaLogin, SenhaArquivo))
            Login = true;
            break;
    }

    // Verifica se o login foi bem sucedido 
    if(Login){
        printf("Logado com sucesso! Seja bem vindo!\n", usuario.nome);
        return true;
    }else{
        printf("Falha no login, email ou senha incorretos\n");
        return false;}

    fclose(arquivo);    

    // Compara com a do arquivo
    // Se True deixa logat
    // Se False retorna uma mensagem de erro
    // Fecha o arquivo
    //IF usuarioscadastrados == 0 mensagem de erro

}