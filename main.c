#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // biblioteca pt-br


    //Estrutura struct para formato dos dados dos produtos
    typedef struct
    {
        int codigo;
        char nome[50];
        float preco;
    } Produto;  //Mudando o nome struct para "Produto" facilitar chama-lá

    //Com a estrutura struct cada iten da variável, são 4 a 5, vai ter seu dados
    Produto limpeza[] =
    {                                 //A condição da função para chamalá será limpeza
        {11,"Detergente",1.99},
        {12,"Sabão em pó",8.99},
        {13,"Esponja",1.50},
        {14,"Amaciante(1Lt)",15.00},
    };

    Produto alimentos[] =
    {                                 //A condição da função para chamalá será alimento
        {21,"Café",19.99},
        {22,"Leite(cx)",5.90},
        {23,"Arroz(1Kl)",4.50},
        {24,"Feijão preto",8.00},
        {25,"Açucar(1Kl)",5.00},
    };

    Produto padaria[] =
    {                                //A condição da função para chamalá será padaria
        {31,"Pão de forma",9.50},
        {32,"Pão integral",12.50},
        {33,"Pão frances(uni)",1.90},
        {34,"Sonho",8.50},
    };

    //Variáveis que recebem o total, utilizando *total para alterar o valor, de cada categoria
    float totalLimpeza = 0, totalAlimentos = 0, totalPadaria = 0;

    //Pode ser usado para pular linha
    void pularLinha()
    {
        printf("\n");
    }

    //Só declaramos para o computador que existe essas variáveis
    void   exibirProdutos(Produto produtos[], int tamanho,float*total);
    void realizarPagamento();

    int main ()
    {
        setlocale(LC_ALL, "portuguese");  //aceita as regras gramaticais.
        int opcao;

        do  // Pelo menos uma vez vai ser mostrado a menu principal
        {
            printf("\n                 MENU PRINCIPAL \n");
            printf("              1) Material de Limpeza\n");
            printf("              2) Venda de Alimentos\n");
            printf("              3) Padaria\n");
            printf("              4) Pagamento\n");
            printf("              5) Sair\n");
            printf("\t\t");
            scanf("%d", &opcao);

            switch(opcao)
            {
                case 1:
                    exibirProdutos(limpeza, 4, &totalLimpeza);     //chamamos a função e nos () colocamos as condições
                    break;
                case 2:
                    exibirProdutos(alimentos, 5, &totalAlimentos);
                    break;
                case 3:
                    exibirProdutos(padaria, 4, &totalPadaria);
                    break;
                case 4:
                    realizarPagamento();                           //chamamos a fução pagar, mas ela não precisa de condição
                    break;
                case 5:
                    printf(" \n                        Saindo do programa\n\n");
                    break;
                default:
                    printf(" \n          Opição invalida\n\n");
                    break;
            }
        }while(opcao != 5);  //Se a escolha for diferente de 5 vai repetir se não vai parar o programa
        return 0;
    }

    //Agora dissemos o que essas funções vão fazer
    void   exibirProdutos(Produto produtos[], int tamanho,float*total)
    {   //Função vai precisar de condições qual variavel na estrutura struct, tamanho e total
        int codigo, quantidade;
        printf("          Selecione o codigo do produto (precione 0 para voltar0):\n");
        //Vai escrever toda nossa estrutura struct
        for (int i = 0;i < 4; i++)
            {
                printf("           %d - %s - R$%.2f \n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
            }
        while (1)
        {
            printf(" \n           Codigo:");
            scanf("%d", &codigo);
            fflush(stdin);
                //se for 0 vai parar essa parte e vai voltar a return 0
                if(codigo == 0)break;
                for(int i =0; i < tamanho;i++)
                {   //vai fazer um loop até encontrar o codigo na variavel struct, se o codigo existir então vai entrar no if
                    if(codigo == produtos[i].codigo)
                    {
                        printf("           Quantidade:");
                        scanf("%d", &quantidade);
                        fflush(stdin);
                        *total += produtos[i].preco * quantidade; //Aqui que modificamos o ponteiro total
                        printf(" \n         %d x %s - Foi adicionado ao carrinho. \n", quantidade, produtos[i].nome);
                        break;
                    }
                }
        }
    }

    //Função para o pagamento
    void realizarPagamento()
    {   //Soma todas as caegorias
        float totalCompra = totalAlimentos + totalLimpeza + totalPadaria;
        if(totalCompra == 0)
        {
            printf("Nao foi realizado nem uma compra");
            return;
        }


        //nossa nota fiscal que vai ter o total de cade categoria
        printf("         Resulmo da Compra:\n");
        printf("         - Materiais de Limpeza - R$%2.f \n", totalLimpeza);
        printf("         - Vendas de Alimentos  - R$%2.f \n", totalAlimentos);
        printf("         -      Padaria         - R$%2.f \n\n", totalPadaria);
        printf("         -   Total a pagar      - R$%2.f \n", totalCompra);


        int opcao;
        printf("                 Escolha a forma de pagamento:\n                1) Dinheiro (Desconto)\n                2) Cartao\n                Opsao:");
        scanf("%d", &opcao);

        //opção 1 será a que terá os descontos, logo, os if e else
        if (opcao == 1)
        {
            float taxa;
            if (totalCompra <= 50)
            {
                taxa = totalCompra*0.95;
                printf(" Pagamento com dinheiro no valor R$%2.f com desconto de 5%\n", taxa);
            }else
                {
                    if(totalCompra >50 && totalCompra < 100)
                    {
                        taxa = totalCompra*0.90;
                        printf(" Pagamento com dinheiro no valor R$%2.f com desconto de 10%\n",taxa);
                    }else
                        {
                            taxa = totalCompra*0.82;
                            printf(" Pagamento com dinheiro no valor R$%2.f com desconto de 18%\n",taxa);
                        }
                }

        }else
            {
                printf("Pagamento em cartoa no valor de R$%2.f \n", totalCompra);
            }

        //Apos feito o pagamento vamos zerar os valores
        totalCompra = totalAlimentos = totalLimpeza = totalPadaria = 0;

    }
