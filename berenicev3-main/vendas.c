#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "headers.h"

void menuDeVendas(cadastro_produtos *ptrProdutos,
                  int tamanhoVetorProdts)
{

    float subtotal=0;
    int flag = 1, codigo, quantidade;
    char voltar = 'q';
    long int iddesejado;

    while(flag == 1)
    {
        while(codigo != 3)
        {
            system("cls");

            printf("\n\n=====\t\t||\t\t MENU DE PRODUTOS \t\t||\t\t=====\n\n");

            printf("\n \t Código  \t Opção              \t\n");
            printf("\n \t 1       \t Realizar venda           \t");
            printf("\n \t 2       \t Relatorio de venda          \t");
            printf("\n \t 3       \t Voltar             \t\n");

            printf("\nDigite o código para selecionar a opção: ");
            scanf("%d", &codigo);
            getchar();

            switch(codigo)
            {
            case 1:
                flag = 0;

                exibirProdutos( ptrProdutos,
                                tamanhoVetorProdts);

                int indice = procuraProduto(ptrProdutos,
                                            tamanhoVetorProdts, iddesejado);
                printf("%d",indice);
                //validacao se o id existe
                do
                {
                    printf("\nDigite a id do produto desejado: ");
                    scanf("%ld",&iddesejado);
                    indice = procuraProduto(ptrProdutos, tamanhoVetorProdts, iddesejado);

                    if(indice==-1)
                    {
                        printf("\nProduto nao existente, digite novamente: ");
                    }

                }
                while(indice==-1);//fechamento da validacao do id

                printf("%ld",exibirProdutos( ptrProdutos[indice]));
                system("cls");

//validacao de estoque
                do
                {
                    printf("\nQuantidade disponivel:%d",ptrProdutos[indice].estoque);
                    printf("\nDigite a quantidade desejada: ");
                    scanf("%d",&quantidade);
                    indice = procuraProduto(ptrProdutos, tamanhoVetorProdts, iddesejado);

                    if(quantidade>ptrProdutos[indice].estoque)
                    {
                        printf("\nesotque invalido: ");
                    }


                }
                while(quantidade>ptrProdutos[indice].estoque);//fechamento da validacao de estqoue
                ptrProdutos[indice].estoque=ptrProdutos[indice].estoque-quantidade;
                //calculo do subtotal de item
                ptrProdutos[indice].subtotal=ptrProdutos[indice].subtotal+quantidade*ptrProdutos[indice].preco;
                subtotal=subtotal+quantidade*ptrProdutos[indice].preco;
                printf("\n%.2f",ptrProdutos[indice].subtotal);
                printf("\no valor total da compra é: %.2f",subtotal);



                system("pause");
                break;

            case 2:
                flag = 0;

                break;

            case 3:
                flag = 0;

                printf("\nVocê será redirecinado ao menu principal. Aperte qualquer tecla para continuar.");
                scanf("%c", &voltar);

                system("cls");

                break;

            default:
                flag = 1;
                printf("\n\aCódigo inválido! Digite qualquer tecla para retornar ao menu de vendas.");
                scanf("%c", &voltar);

                system("cls");

                break;
            }
        }
    }
}

void efetuarvenda(long int iddesej)
{


    return 0;
}


/*void formaDePagamento(){

    flistaDeCompras();

    printf("\n\n=====\t\t||\t\t ESCOLHA DA FORMA DE PAGAMENTO \t\t||\t\t=====\n\n");

    int i = 0, flag = 1, flag2, formaDePagamento, quantidadeDeParcelas, precisaDeTroco;
    float total = 0, valorEntreguePeloCliente, troco, valorDaParcela;
    char sair;

    for(i; i<5; i++)
    {
        total = total + ;
    }

    printf("\nAgora escolha a forma de pagamento. Temos o pagamento A VISTA e o pagamento A PRAZO.\n\nNo pagamento A VISTA, em compras de ate R\$ 50.00, damos 5 porcento de desconto, em compras de R\$ 50.00 a R\$ 99.99 oferecemos 10 porcento de desconto e em compras acima de R\$ 99.99 promovemos 18 porcento de desconto.\n\nNo pagamento A PRAZO, em compras parceladas em ate 3x temos um acrescimo de 5 porcento e, em compras com parcelas acima de 3x, um acrescimo de 8 porcento");

    printf("\n\nDigite 1 para pagamento A VISTA e 2 para pagamento A PRAZO: ");
    scanf("%i", &formaDePagamento);
    getchar();

    while(flag == 1)
    {


        switch(formaDePagamento)
        {

        case 1:
            flag = 0;
            if(total <= 50)
            {
                total = total - (total * 0.05);
            }
            else if((total > 50)&&(total < 100))
            {
                total = total - (total * 0.1);
            }
            else
            {
                total = total - (total * 0.18);
            }

            break;

        case 2:
            flag = 0;
            printf("\n\nPor favor, nos diga a quantidade de parcelas: ");
            scanf("%i", &quantidadeDeParcelas);
            getchar();

            while(quantidadeDeParcelas<1)
            {
                printf("\nNúmero de parcelas inválido, digite um valor igual ou acima de 1: ");
                scanf("%i", &quantidadeDeParcelas);
                getchar();
            }

            if(quantidadeDeParcelas <= 3)
            {
                total = total + (total * 0.05);
            }
            else
            {
                total = total + (total * 0.08);
            }

            break;

        default:
            flag = 1;
            printf("\nOpção de pagamento inválida, digite 1 para pagamento A VISTA e 2 para A PRAZO: ");
            scanf("%i", &formaDePagamento);
            getchar();

        }
    }

    printf("\nTotal da compra: R$%.2f\n", total);

    if(formaDePagamento==1)
    {
        printf("\nVocê precisa de troco? Digite 1 para SIM ou qualquer outra tecla para NÃO: ");
        scanf("%i", &precisaDeTroco);
        getchar();

        printf("\nPor favor, nos diga o valor que voce ira entregar: ");
        scanf("%f", &valorEntreguePeloCliente);
        getchar();

        if(precisaDeTroco != 1)
        {
            while(valorEntreguePeloCliente != total)
            {
                printf("\nValor inválido, sua compra tem um total de: R$%f. Por favor, nos entregue o mesmo valor: ", total);
                scanf("%f", &valorEntreguePeloCliente);
                getchar();
            }
        }

        while (valorEntreguePeloCliente<total)
        {
            printf("\nValor insuficiente, sua compra tem um total de: R$%.2f. Digite um valor válido: ", total);
            scanf("%f", &valorEntreguePeloCliente);
            getchar();
        }
        troco = valorEntreguePeloCliente - total;
        if(precisaDeTroco == 1)
        {
            printf("\nAqui esta seu troco: R$%.2f\n", troco);
        }
    }
    else
    {
        valorDaParcela = total / quantidadeDeParcelas;
        printf("\nO valor de suas parcelas ficou em: R$%.2f\n", valorDaParcela);
    }

    printf("\nMuito obrigado pela sua compra, volte sempre!\n");

    for (int i=0; i<5; i++)
    {
        compras[i] = 0;
        subtotal[i] = 0;
    }

    printf("\nVocê será redirecionado ao menu, digite qualquer tecla para continuar");
    scanf("%c", &sair);
    system("cls");


    return 0;
}
*/
