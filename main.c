#include <stdio.h>
#include <stdlib.h>
#include<locale.h> // biblioteca para setar em pt-br


 //Etiqueta para os produtos
    typedef struct {    // cria uma etiqueta para uma lista organizada
        int codigo;     // vai receber um numero inteiro = codigo
        char nome[50];  // recebe um array de no maxima 50 caracteres assim escrevendo os nomes
        float preco;    // determina o preço e colocaremos R$ para reais %.2f para só escrever duas casa decimais e não as seis que o floatf permite
    } Produto;

 //Lista de produtos
 // Aqui criamos arrays que serão acessadas futuramente para escrever os  produtos e percorrer esse array para acessar o codigo
    Produto limpeza[] = {
        {11,"Detergente",1.99},
        {12,"Sabao em po",8.99},
        {13,"Esponja",1.50},
        {14,"Amaciante(1Lt)",15.00},
    };

    Produto alimentos[] = {
        {21,"Cafe",19.99},
        {22,"Leite(cx)",5.90},
        {23,"Arroz(1Kl)",4.50},
        {24,"Feijao preto",8.00},
        {25,"Acucar(1Kl)",5.00},
    };

    Produto padaria[] = {
        {31,"Pao de forma",9.50},
        {32,"Pao integral",12.50},
        {33,"Pao frances(uni)",1.90},
        {34,"Sonho",8.50},
    };

    //Vamos declarar variaveis que vao servir para tatalizar o total de cada setor, no final vamos chamar pelo ponteiro *total
    float totalLimpeza = 0, totalAlimentos = 0, totalPadaria = 0;

    //Agora vamos criar um void junto com um for que irá escrever os produto de determinada categoria na tela
    void   exibirProdutos(Produto produtos[], int tamanho,float*total){  //Aqui criamos um poonteiro, 1 - vai entrar a arrayy desejada 2 - o tamanho da array 3- o ponteiro total alguma coisa
        int codigo, quantidade;
        printf("          Selecione o codigo do produto (precione 0 para voltar0):\n");
        for (int i = 0;i < tamanho; i++){     // definimos que i vai ser algo  e começa por 0 e vai ate ser menos que o tamanho da array se não vai soma 1
            printf("           %d - %s - R$%.2f \n", produtos[i].codigo, produtos[i].nome, produtos[i].preco); //array sendo chamadas e sua categoria
        }
        //Agora vamos fazer a quantidade do produto e somar tudo ao total
        while (1){
            printf(" \n           Codigo:");
            scanf("%d", &codigo);
                if(codigo == 0)break;
                for(int i =0; i < tamanho;i++){
                    if(codigo == produtos[i].codigo){
                        printf("           Quantidade:");
                        scanf("%d", &quantidade);
                        *total += produtos[i].preco * quantidade; //Aqui que modificamos o ponteiro total
                        printf(" \n         %d x %s - Foi adicionado ao carrinho. \n", quantidade, produtos[i].nome);
                        break;
                        }
                    }
            }
    }

    //Agora vamos fazer o pagamento com cartao e dinheiro
    // Essa parte vai ver se foi feito alguma compra
    void realizarPagamento(){
        float totalCompra = totalAlimentos + totalLimpeza + totalPadaria;
        if(totalCompra == 0){
            printf("Nao foi realizado nem uma compra");
            return;
        }

        //nossa nota fiscal que vai ter o total de cade categoria
        printf("         Resulmo da Compra:\n");
        printf("         - Materiais de Limpeza - R$%2.f \n", totalLimpeza);
        printf("         - Vendas de Alimentos  - R$%2.f \n", totalAlimentos);
        printf("         -      Padaria         - R$%2.f \n\n", totalPadaria);
        printf("         -   Total a pagar      - R$%2.f \n", totalCompra);


    //vamos entra na area de pagamento
    int opcao;
    printf("                 Escolha a forma de pagamento:\n                1) Dinheiro\n                2) Cartao\n                Opsao:");
    scanf("%d", &opcao);

    if (opcao == 1){
        float taxa;
        if (totalCompra <= 50){
            taxa = totalCompra*0.95;
            printf(" Pagamento com dinheiro no valor R$%2.f com desconto de 5%\n", taxa);
        }else{
            if(totalCompra >50 && totalCompra < 100){
                taxa = totalCompra*0.90;
                printf(" Pagamento com dinheiro no valor R$%2.f com desconto de 10%\n",taxa);
            }else{
                taxa = totalCompra*0.82;
                printf(" Pagamento com dinheiro no valor R$%2.f com desconto de 18%\n",taxa);
            }
        }

    }else {
        printf("Pagamento em cartoa no valor de R$%2.f \n", totalCompra);
    }
    //Apos feito o pagamento vamos zerar os valores, mas precisa arrumar !!!!!!!
    totalCompra = totalAlimentos = totalLimpeza = totalPadaria = 0;

    }

    int main (){
        int opcao;
        do { // vamos escrever o menu principal dentro do main
            printf("\n                 MENU PRINCIPAL \n");
            printf("              1) Material de Limpeza\n");
            printf("              2) Venda de Alimentos\n");
            printf("              3) Padaria\n");
            printf("              4) Pagamento\n");
            printf("              5) Sair\n");
            printf("\t\t");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1:
                    //aqui temos um ponteiro chamamos por exibirprodutos en dentro do () colocamos o arrym, numeros de itens e o endereço do valor que será modificado
                    exibirProdutos(limpeza, 4, &totalLimpeza);
                    break;
                case 2:
                    exibirProdutos(alimentos, 5, &totalAlimentos);
                    break;
                case 3:
                    exibirProdutos(padaria, 4, &totalPadaria);
                    break;
                case 4:
                    realizarPagamento();
                    break;
                case 5:
                    printf(" \n          Saindo do programa\n\n");
                    break;
                default:
                    printf(" \n          Opicao invalida\n\n");
                    break;
            }
        }while(opcao != 5);
        return 0;
    }
