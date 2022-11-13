#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

typedef struct
{
    char nome[25];
    long int id;
    int estoque;
    float preco;
    int qtdVendida;

} cadastro_produtos;

// Fun��es de produtos

void menuDeProdutos(cadastro_produtos **ptrProdutos,
                    int *tamanhoVetorProdts,
                    int *contadorProdutos);

void exibirProdutos(cadastro_produtos *ptrProdutos,
                    int tamanhoVetorProdts);

void cadastrarProdutos(cadastro_produtos *ptrProdutos,
                       int tamanhoVetorProdts);

void atualizarProduto(cadastro_produtos *ptrProdutos,
                      int tamanhoVetorProdts);

void excluirProduto(cadastro_produtos *ptrProdutos,
                    int *tamanhoVetorProdts);

// Procura um produto com codigo id no vetor de produtos,
// se encontrar devolve a posica��o no vetor, ou seja a variavel i
// se n�o encontrar ou o ID = 0 devolve uma posi��o invalida (-1)
int procuraProduto(cadastro_produtos *ptrProdutos,
                   int tamanhoVetorProdts, long int idDigitado);

// Fun��es de venda

void menuDeVendas(cadastro_produtos *ptrProdutos,
                  int tamanhoVetorProdts);

//void formaDePagamento(void);
void subtotal(int codigo);

void listaDeCompras(void);
#endif // HEADERS_H_INCLUDED
