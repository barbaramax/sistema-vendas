#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// structs
struct Cliente{
    char nome[30];
    char sexo;
    int idade;
};

struct Venda{
    struct Cliente cliente; 
    int qtdItensAdc;
    float valorAdc;
    char nomeItem[30]; 
    float totalVenda;
};

typedef struct Venda Venda;

// funções
void cadastrarVenda(Venda **vendas, int *qtdVendas, int *novasVendas);
void verInformacoesNome(Venda *vendas, int qtdVendas);
void verInformacoesVenda(Venda *vendas, int qtdVendas);

int main()
{
    // menu
    int opcao = 0;
    Venda *vendas = NULL;
    int qtdVendas = 0;
    int novasVendas = 0;
    
    //Menu principal
    do{
        printf("\n----------------\n MENU PRINCIPAL \n----------------\n");
        printf("\n 1 - Cadastrar novas vendas");
        printf("\n 2 - Ver informações de uma venda específica, baseado no nome do cliente");
        printf("\n 3 - Ver informações de todas as vendas");
        printf("\n 4 - Encerrar o programa");
        printf("\n Digite uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                cadastrarVenda(&vendas, &qtdVendas, &novasVendas);
                break;
            case 2: 
                verInformacoesNome(vendas, qtdVendas);
                break;
            case 3:
                verInformacoesVenda(vendas, qtdVendas);
                break;
            case 4:
                return 0;
                break;
            default:
                printf("\n Opção inválida");
        }
        
    } while(opcao != 4);
    free(vendas);
    return 0;
}

void cadastrarVenda(Venda **vendas, int *qtdVendas, int *novasVendas){
    // variaveis de validação
    int nomeInvalido = 0;
    int sexoInvalido = 0;
    
    int item = 0;
    int adicionais = 0;
    int nenhumAdicional = 0;
    
    // quantidade de vendas
    printf("\n Quantas vendas deseja cadastrar agora? ");
    scanf("%d", novasVendas);
    *vendas = realloc(*vendas, (*qtdVendas + *novasVendas) * sizeof(Venda));
    
    if(*vendas == NULL){
        printf("erro");
    }
    getchar();
    
    // preenchendo vendas
    for(int i = *qtdVendas; i < *qtdVendas + *novasVendas; i++){
        (*vendas)[i].qtdItensAdc = 0;
        (*vendas)[i].valorAdc = 0;
        (*vendas)[i].totalVenda = 0;
        nenhumAdicional = 0;
        // dados do cliente 
        
        // nome 
        do{
            nomeInvalido = 0;
            printf("\n Nome do cliente? ");
             fgets((*vendas)[i].cliente.nome, sizeof((*vendas)[i].cliente.nome), stdin);
            (*vendas)[i].cliente.nome[strcspn((*vendas)[i].cliente.nome, "\n")] = '\0';
                
            int tamanho = strlen((*vendas)[i].cliente.nome);
            if(tamanho < 3){
                printf("\n Nome inválido. Seu nome deve ter mais de 3 letras.\n");
                nomeInvalido++;
            }
        }while(nomeInvalido != 0);
        
        // sexo
        do{
            sexoInvalido = 0;
            printf("\n Sexo do cliente? ");
            scanf(" %c", &(*vendas)[i].cliente.sexo);
            if((*vendas)[i].cliente.sexo != 'F' && (*vendas)[i].cliente.sexo != 'f' && (*vendas)[i].cliente.sexo != 'M' && (*vendas)[i].cliente.sexo != 'm' && (*vendas)[i].cliente.sexo != 'O' && (*vendas)[i].cliente.sexo != 'o'){
                printf("\n Sexo inválido. Digite novamente.");
                sexoInvalido++;
            }
            
        }while(sexoInvalido != 0);
        getchar();
        
        // idade 
        do{
            printf("\n Idade do cliente? ");
            scanf("%d", &(*vendas)[i].cliente.idade);
            getchar();
            
            if((*vendas)[i].cliente.idade <= 0){
                printf("\n Idade inválida");
            }
        }while((*vendas)[i].cliente.idade <= 0);
        
        // dados da venda 
        
        //item
        do{ 
            printf("\n-----------\n PRODUTOS \n-----------");
            printf("\n 1 - PC Gamer (R$ 6.800,00)");
            printf("\n 2 - PC Office (R$ 3.500,00)");
            printf("\n 3 - Notebook Lenovo ThinkBook (R$ 5.200,00)");
            printf("\n 4 - MacBook Air M2 (R$ 8.900,00)");
            printf("\n 5 - Mac mini (R$ 8.000,00)");
            printf("\n 6 - Acer Aspire Nitro 5 (R$ 3.700,00)");
            printf("\n Digite o número do modelo desejado: ");
            scanf("%d", &item);
            getchar();
        } while(item < 1 || item > 6);
        
        switch(item){
            case 1:
                strcpy((*vendas)[i].nomeItem, "PC Gamer");
                (*vendas)[i].totalVenda += 6800.0;
                break;
            case 2:
                strcpy((*vendas)[i].nomeItem, "PC Office");
                (*vendas)[i].totalVenda += 3500.0;
                break;
            case 3:
                strcpy((*vendas)[i].nomeItem, "Notebook Lenovo");
                (*vendas)[i].totalVenda += 5200.0;
                break;
            case 4:
                strcpy((*vendas)[i].nomeItem, "MacBook Air M2");
                (*vendas)[i].totalVenda += 8900.0;
                break;
            case 5:
                strcpy((*vendas)[i].nomeItem, "Mac mini");
                (*vendas)[i].totalVenda += 8000.0;
                break;
            case 6:
                strcpy((*vendas)[i].nomeItem, "Acer Aspire Nitro 5");
                (*vendas)[i].totalVenda += 3700.0;
                break;
            default:
                printf("\n Modelo inválido. Digite novamente.");
        }
        
        // adicionais 
        do{
            int adicionais = 0;
            printf("\n-----------\n ADICIONAIS \n-----------");
            printf("\n 1 - SSD NVMe 1TB (R$ 650,00)");
            printf("\n 2 - Memória RAM 16GB (R$ 400,00)");
            printf("\n 3 - Mouse Gamer (R$ 250,00)");
            printf("\n 4 - Headset (R$ 350,00)");
            printf("\n 5 - Teclado Mecânico (R$ 600,00)");
            printf("\n 6 - Monitor 144Hz (R$ 1.200,00)");
            printf("\n 7 - Nenhum adicional");
            printf("\n Escolha um adicional (1-7): ");
            scanf("%d", &adicionais);
            getchar();
            
            
            switch(adicionais){
                case 1:
                    (*vendas)[i].totalVenda += 650.0;
                    (*vendas)[i].valorAdc += 650.0;
                    (*vendas)[i].qtdItensAdc++;
                    break;
                case 2:
                    (*vendas)[i].totalVenda += 400.0;
                    (*vendas)[i].valorAdc += 400.0;
                    (*vendas)[i].qtdItensAdc++;
                    break;
                case 3:
                    (*vendas)[i].totalVenda += 250.0;
                    (*vendas)[i].valorAdc += 250.0;
                    (*vendas)[i].qtdItensAdc++;
                    break;
                case 4:
                    (*vendas)[i].totalVenda += 350.0;
                    (*vendas)[i].valorAdc += 350.0;
                    (*vendas)[i].qtdItensAdc++;
                    break;
                case 5:
                    (*vendas)[i].totalVenda += 600.0;
                    (*vendas)[i].valorAdc += 600.0;
                    (*vendas)[i].qtdItensAdc++;
                    break;
                case 6:
                    (*vendas)[i].totalVenda += 1200.0;
                    (*vendas)[i].valorAdc += 1200.0;
                    (*vendas)[i].qtdItensAdc++;
                    break;
                case 7:
                    nenhumAdicional = 1;
                    break;
                default:
                    printf("\n Adicional inválido.");
            }
            if((*vendas)[i].qtdItensAdc == 5){
                printf("\n Máximo de 5 adicionais.");
            }
        
        }while((*vendas)[i].qtdItensAdc < 5 && nenhumAdicional == 0);
        
        printf("\n Cadastro realizado com sucesso!");
        printf("\n Total venda: R$%.2f", (*vendas)[i].totalVenda);
        printf("\n Total valor gasto com adicionais: R$%.2f", (*vendas)[i].valorAdc);
        printf("\n Itens adicionados: %.d", (*vendas)[i].qtdItensAdc);
    }
    *qtdVendas += *novasVendas;
}

void verInformacoesNome(Venda *vendas, int qtdVendas){
    char nomeInformado[30];
    int comp = 0;
    float media = 0; 
    float soma = 0;
    int total = 0;
    
    printf("Digite um nome: ");
    fgets(nomeInformado, sizeof(nomeInformado), stdin);
    nomeInformado[strcspn(nomeInformado, "\n")] = '\0';
    
    for(int i = 0; i < qtdVendas; i++){
        comp = strcmp(vendas[i].cliente.nome, nomeInformado);
        if(comp == 0){
            printf("\n--------------------\n DADOS DO PEDIDO \n--------------------\n");
                        //Valor da compra
                        printf(" \n O valor total da compra foi de: R$%.2f\n ", vendas[i].totalVenda);
                        
                        //Valor dos adicionais
                        printf(" \n O valor dos adicionais foi de: %.2f\n", vendas[i].valorAdc);
                        
                        //Quantidade de adicionais 
                        printf(" \n O número de adicionais foi: %d\n", vendas[i].qtdItensAdc);
                        
                        //Modelo comprado
                        printf(" \n O modelo comprado foi: %s\n", vendas[i].nomeItem);
                        
                        soma += vendas[i].totalVenda;
                        total++;
        }
    }
    
    if(total > 0) {
        media = soma / total;
        printf("\n Média de valor das compras feitas por %s: %.2f", nomeInformado, media);
    } 
    else {
        printf("\n Nenhuma venda encontrada para o cliente %s.", nomeInformado);
    }
}
void verInformacoesVenda(Venda *vendas, int qtdVendas){
    float valorDigitado = 0;
    int qtdAcima = 0;
    int qtdMaxima = 0;
    int qtdMacbook = 0;
    int qtdMulheres = 0;
    
    // variaveis totais
    float totalProdutos = 0;
    float totalAdicionais = 0;
    float totalGeral = 0;
    
    printf("Digite um valor para consulta: ");
    scanf("%f", &valorDigitado);
    
    for(int i = 0; i < qtdVendas; i++){
        if(vendas[i].totalVenda > valorDigitado){
            qtdAcima++;
        }
        if(vendas[i].qtdItensAdc == 5){
            qtdMaxima++;
        }
        if(strcmp(vendas[i].nomeItem, "MacBook Air M2") == 0) {
            qtdMacbook++;
        }
        if(vendas[i].cliente.sexo == 'f' || vendas[i].cliente.sexo == 'F'){
            qtdMulheres++;
        }
        
        totalProdutos += (vendas[i].totalVenda - vendas[i].valorAdc);
        totalAdicionais += vendas[i].valorAdc;
        totalGeral += vendas[i].totalVenda;
    }
    
    
    printf("\n----------------\n INFORMAÇÕES \n----------------\n");
    printf("\n Quantidade de vendas acima do valor informado: %d \n", qtdAcima);
    printf("\n Quantidade de vendas que atingiram o limite de adicionais: %d \n", qtdMaxima);
    printf("\n Quantidade de vendas do MacBook Air M2: %d \n", qtdMacbook);
    printf("\n quantidade de compradores que preferiram não informar o sexo: %d \n", qtdMulheres);
    
    printf("\n Total vendido em produtos: R$%.2f\n", totalProdutos);
    printf("\n Total vendido em adicionais: R$%.2f\n", totalAdicionais);
    printf("\n Total geral vendido: R$%.2f\n", totalGeral);
}
