#include <stdio.h>
#include <stdlib.h>

//BIBLIOTECA DE FUNÇÕES******************************************************
void menu();
void listar();
void addcontato();
void editcontato();
void delcontato();
void restart();



//BIBLIOTECA DE DADOS********************************************************
char resposta, owner[15];
int opcao, qcontatos=0, index = 0;


struct contato{
    int ordem;
    char nome[29];
    int telefone[14];
    char email[24];
};

struct contato pessoa[99];



//MAIN***********************************************************************
int main(){

    printf("Bem vindo(a) a sua agenda!\n");
    printf("\nQual o seu nome?\n>");
    fgets(owner, 15, stdin);
    menu();

    return 0;
}
//FIM DA MAIN**************************************************************

menu(){

    printf("\nOla, %s, o que voce deseja fazer?", owner);

    printf("\n\n\tMenu\n");
    printf("1- Ver Agenda\n");
    printf("2- Novo Contato\n");
    printf("3- Editar Contato\n");
    printf("4- Excluir Contato\n");
    printf("5- Sair\n\n>");
    fflush(stdin);
    scanf(" %d", &opcao);
    while(opcao!= 5){
            switch(opcao){
                case 1:
                    listar();
                    break;
                case 2:
                    addcontato();
                    break;
                case 3:
                    editcontato();
                    break;
                case 4:
                    delcontato();
                    break;
                default:
                    printf("Entrada invalida.\n");
                    system("pause");
                    system("cls");
                    menu();
            }
    }

    system("cls");
}


listar(){

    system("cls");

    printf("\nAgenda\n\n");

    for(int i=0; i <= qcontatos; i++){
            printf(">Nome: %s\n>", &pessoa[i].nome);
            printf("Telefone: %s\n>", &pessoa[i].telefone);
            printf("Email: %s\n", &pessoa[i].email);
            printf("\n");
    }
    printf("Fim da Lista\n");

    restart();
}

addcontato(){

    system("cls");
    printf("Adicionar Contato\n");

    printf("Digite o nome do novo contato:\n>");
    fflush(stdin);
    fgets(pessoa[index].nome, 30, stdin);

    printf("Digite o telefone de %s:\n>", &pessoa[index].nome);
    scanf("%s", &pessoa[index].telefone);

    printf("Digite o email de %s:\n>", &pessoa[index].nome);
    scanf("%s", &pessoa[index].email);

    printf("\nContato adicionado!\n");
    printf("Nome: %s\n>", &pessoa[index].nome);
    printf("Telefone: %s\n>", &pessoa[index].telefone);
    printf("Email: %s\n", &pessoa[index].email);

    pessoa[index].ordem = ++index ;
    qcontatos =+1;
    index =+ 1;

    printf("\nDeseja adicionar outro contato(S/N?)\n>");
    scanf(" %c", &resposta);

    if(resposta == 115 || resposta == 83){
        system("cls");
        addcontato();
    }else{
        restart();
    }

}

editcontato(){
    system("cls");
    printf("Editar\n");
    restart();
}

delcontato(){
    system("cls");
    printf("Deletar\n");
    restart();
}

restart(){
    int reload;
    printf("\nDeseja voltar ao menu ou encerrar?\n");
    printf("1- Menu\n\nOu digite qualquer tecla para encerrar...\n\n>");
    scanf("%d",&reload);
    if(reload == 1){
        system("cls");
        menu();
    }else{
        opcao = 5;
        menu;
    }
}

