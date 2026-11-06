#include <stdio.h>
#include "produto.h"
#include "util.h"

int main()
{
    struct Produto produtos[MAX_PRODUTOS];
    struct Categoria categorias[MAX_CATEGORIAS];
    
    int totalCategorias = carregarCategorias(categorias);
    int totalProdutos = carregarProdutos(produtos);

    int opcao;
    int subopcao;

    do
    {
        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Pesquisar Produto\n");
        printf("4 - Alterar Estoque de um Produto\n");
        printf("5 - Remover Produto\n");
        printf("6 - Categorias\n");
        printf("7 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            if (totalCategorias == 0)
            {
                printf("\nCadastre ao menos uma categoria antes de cadastrar produtos.\n");
            }
            else
            {
                totalProdutos = cadastrarProduto(produtos, totalProdutos, categorias, totalCategorias);
            }
        }
        else if (opcao == 2)
        {
            listarProdutos(produtos, totalProdutos, categorias, totalCategorias);
        }
        else if (opcao == 3)
        {
            pesquisarProduto(produtos, totalProdutos, categorias, totalCategorias);
        }
        else if (opcao == 4)
        {
            alterarEstoque(produtos, totalProdutos);
        }
        else if (opcao == 5)
        {
            removerProduto(produtos, totalProdutos);
        }
        else if (opcao == 6)
        {
            do
            {
                printf("\n--- SUBMENU CATEGORIAS ---\n");
                printf("1 - Cadastrar Categoria\n");
                printf("2 - Listar Categorias\n");
                printf("3 - Voltar\n");
                printf("Digite uma opcao: ");
                scanf("%d", &subopcao);

                if (subopcao == 1)
                {
                    totalCategorias = cadastrarCategoria(categorias, totalCategorias);
                }
                else if (subopcao == 2)
                {
                    listarCategorias(categorias, totalCategorias);
                }
                else if (subopcao != 3)
                {
                    printf("\nOpcao invalida.\n");
                }

            } while (subopcao != 3);
        }
        else if (opcao == 7)
        {
            salvarCategorias(categorias, totalCategorias);
            salvarProdutos(produtos, totalProdutos);
            printf("\nPrograma encerrado.\n");
        }
        else
        {
            printf("\nOpcao invalida.\n");
        }

    } while (opcao != 7);

    return 0;
}
