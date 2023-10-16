//Header do nosso projecto

//Structs que vamos utilizar:
    //Struct que vai guardar os pedidos feitos pelos utilizadores;
#pragma region Estruturas de dados
struct Pedidos
{
    int ordem;
    int NIF;
    char codigo[5];
    float tempo;
    float distancia;
};

    //Struct que vai guardar meios de transportes disponíveis;
struct Transportes
{
    char codigo[5];
    char tipo[20];
    float preco;
    float autonomia;
};
#pragma endregion

//Funções que vamos utilizar ao longo do projecto;
    //Manipulação de strings;
char* strcpy(char* destination, const char* source);
    //Menu;
void Menu(struct Transportes t1[], struct Pedidos p1[]);
    //Ponto 3
void Insercao_Dados_Fich2(struct Transportes t1[]);
    //Ponto 4
void Eliminar_Fich2(struct Transportes t1[]);
    //Ponto 5
void Insercao_Dados_Fich1(struct Pedidos p1[]);
    //Ponto 6
void Eliminar_Fich1(struct Pedidos p1[]);
    //Ponto 7
void Listar_Fich2(struct Transportes t1[]);
    //Ponto 8
void Listar_Fich1(struct Pedidos p1[]);

//------------------------------------------

    //Funções que foram feitar para ler ficheiros de texto;
int Ler_Fich1(struct Pedidos p1[]);
int Ler_Fich2(struct Transportes t1[]);

    //Faz alguma manipulação de strings;
int Comparar_Strings(char codigo [5], int count, struct Transportes t1[], int tipo);