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
    //Menu;
void Menu(struct Transportes t1[], struct Pedidos p1[]);