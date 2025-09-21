algoritmo "Analise_de_Preco"
var
   n, i: inteiro
   nom: vetor[1..100] de caractere
   preco_ant, preco_atu, vari: vetor[1..100] de real
   sit: vetor[1..100] de caractere

inicio
   escreval("Digite a quantidade de produtos que deseja analisar: ")
   leia(n)


   para i de 1 ate n faca
        escreval("")
        escreva("Digite o nome do produto ", i, ": ")
        leia(nom[i])

        escreva("Digite o preco no mes anterior (R$): ")
        leia(preco_ant[i])

        escreva("Digite o preco no mes atual (R$): ")
        leia(preco_atu[i])
   fimpara


   para i de 1 ate n faca
        vari[i] <- ((preco_atu[i] - preco_ant[i]) / preco_ant[i]) * 100

        se (vari[i] > 0) entao
             se (vari[i] > 10) entao
                  sit[i] <- "AUMENTO ABUSIVO"
             senao
                  sit[i] <- "AUMENTO"
             fimse
        senao
             se (vari[i] < 0) entao
                  sit[i] <- "QUEDA"
             senao
                  sit[i] <- "ESTAVEL"
             fimse
        fimse
   fimpara


   escreval("")
   escreval("===== RELATORIO DE PRECOS =====")

   para i de 1 ate n faca
        escreval("")
        escreval("Produto: ", nom[i])
        escreval("Preco anterior: R$ ", preco_ant[i]:4:2)
        escreval("Preco atual:    R$ ", preco_atu[i]:4:2)
        escreval("Variacao: ", vari[i]:4:2, "%")
        escreval("Situacao: ", sit[i])
        escreval("------------------------------")
   fimpara

fimalgoritmo