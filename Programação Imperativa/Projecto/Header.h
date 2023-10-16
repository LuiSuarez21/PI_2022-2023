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

struct Utilizacao{
    int ordem;
    int NIF;
    int tempoInicio;
    int tempoFim;
    int autonomiaInicial;
    char codigo[5];
};
#pragma endregion


//Funções que vamos utilizar ao longo do projecto;
    //Manipulação de strings;
char* strcpy(char* destination, const char* source);
int strcmp (const char* str1, const char* str2);
    //Menu;
void Menu(struct Transportes t1[], struct Pedidos p1[], struct Utilizacao u1[]);
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
    //Ponto 9
void Calculo_Custo(struct Pedidos p1[], struct Transportes t1[]);
    //Ponto 10
void Distribuir_Pedidos(struct Pedidos p1[], struct Transportes t1[], struct Utilizacao u1[]);
    //Ponto 11
void Listar_Fich3(struct Utilizacao u1[]);
    //Ponto 12
void Save_Fich1(struct Pedidos p1[]);
    //Ponto 13
void Save_Fich2(struct Transportes t1[]);

//------------------------------------------

    //Funções que foram feitar para ler ficheiros de texto;
int Ler_Fich1(struct Pedidos p1[]);
int Ler_Fich2(struct Transportes t1[]);
int Ler_Fich3(struct Utilizacao u1[]);

    //Faz alguma manipulação de strings;
int Comparar_Strings(char codigo [5], int count, struct Transportes t1[], int tipo);
