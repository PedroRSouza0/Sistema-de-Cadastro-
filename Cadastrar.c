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


void MascararSenha(char *senha, int max_tamanho) {
    int i = 0;
    char ch;
    while (1) {
        ch = getch(); // Captura um caractere sem exibir na tela

        if (ch == '\n' || ch == '\r') { // Enter (finaliza a senha)
            break;
        } else if (ch == '\b' || ch == 127) { // Backspace
            if (i > 0) {
                i--;
                printf("\b \b"); // Remove o último asterisco da tela
            }
        } else if (i < max_tamanho - 1) { // Limita o tamanho da senha
            senha[i++] = ch;
            printf("*"); // Mostra um asterisco
        }
    }
    senha[i] = '\0'; // Finaliza a string com um caractere nulo
    printf("\n");
}

void SalvarUsuarioEmArquivo(Usuario usuario) {
    FILE *arquivo = fopen("usuarios.txt", "a"); // Abre o arquivo em modo de adição

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Escreve os dados do usuário no arquivo
    fprintf(arquivo, "Nome: %s\nEmail: %s\nSenha: %s\n\n", usuario.nome, usuario.email, usuario.senha);
    fclose(arquivo); // Fecha o arquivo
}

int EmailJaExiste(char *email) {
    FILE *arquivo = fopen("usuarios.txt", "r");
    char linha[256];
    char emailLido[MAX_email];

    if (arquivo == NULL) {
        return 0; // Arquivo ainda não existe, nenhum e-mail duplicado
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "Email: %s", emailLido) == 1) {
            if (strcmp(emailLido, email) == 0) {
                fclose(arquivo);
                return 1; // E-mail já cadastrado
            }
        }
    }

    fclose(arquivo);
    return 0;
}

int CadastrarUsuario() {
    Usuario usuario;
    char saida = ' ';

    while (1) {
        printf("Informe o nome do usuario: "); // Leitura do nome do usuario
        scanf(" %[^\n]", usuario.nome); // Permite espaços

        // Leitura do email do usuario
        printf("\nInforme o email: ");
        scanf(" %s", usuario.email);

        // Verifica se o email já existe
        if (EmailJaExiste(usuario.email)) {
            printf("O email digitado ja foi cadastrado.\n");
            continue; // Permite ao usuário tentar cadastrar outro e-mail
        }

        // Lê a senha do usuário
        printf("Insira a senha: ");
        MascararSenha(usuario.senha, MAX_senha);

        printf("\nUsuario cadastrado com sucesso!\n");
        SalvarUsuarioEmArquivo(usuario);

        printf("Deseja cadastrar um novo usuario?[S/N]\n");
        scanf(" %c", &saida);

        if (toupper(saida) == 'N') {
            system("cls");
            break;
        }
    }
    return 0;
}
