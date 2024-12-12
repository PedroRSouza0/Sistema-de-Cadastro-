#ifndef HEADER_H
#define HEADER_H
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

// Protótipos das funções
void MascararSenha(char *senha, int max_tamanho);
void SalvarUsuarioEmArquivo(Usuario usuario);
int EmailJaExiste(char *email);
int CadastrarUsuario();

#endif