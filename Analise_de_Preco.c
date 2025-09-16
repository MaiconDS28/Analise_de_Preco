#include <stdio.h> 

int main() {
    int n, i;

    printf("Digite a quantidade de produtos que deseja analisar: ");
    scanf("%d", &n);

    char nom[n][30];           
    float preco_ant[n];
    float preco_atu[n];
    float vari[n];
    char sit[n][30];      

   
    for (i = 0; i < n; i++) {
        printf("\nDigite o nome do produto %d: ", i+1);
        scanf(" %[^\n]", nom[i]);  

        printf("Digite o preço no mês anterior (R$): ");
        scanf("%f", &preco_ant[i]);

        printf("Digite o preço no mês atual (R$): ");
        scanf("%f", &preco_atu[i]);
    }

  
    for (i = 0; i < n; i++) {
        vari[i] = ((preco_atu[i] - preco_ant[i]) / preco_ant[i]) * 100;

        if (vari[i] > 0) {
            if (vari[i] > 10) {
                sprintf(sit[i], "AUMENTO ABUSIVO");
            } else {
                sprintf(sit[i], "AUMENTO");
            }
        } else if (vari[i] < 0) {
            sprintf(sit[i], "QUEDA");
        } else {
            sprintf(sit[i], "ESTAVEL");
        }
    }

    
    printf("\n===== RELATORIO DE PREÇOS =====\n");
    for (i = 0; i < n; i++) {
        printf("\nProduto: %s\n", nom[i]);
        printf("Preço anterior: R$ %.2f\n", preco_ant[i]);
        printf("Preço atual:    R$ %.2f\n", preco_atu[i]);
        printf("Variaçao: %.2f%%\n", vari[i]);
        printf("Situaçao: %s\n", sit[i]);
        printf("------------------------------\n");
    }

    return 0;
}
