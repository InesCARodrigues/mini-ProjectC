#define NOME 60
#define DESCRI 200
#define NUM 9
#define HORA 3

/*estruturas*/


typedef struct utilizadores *List_u;
typedef struct utilizadores{
    char nome[NOME];
    int bi;
    int n_utilizador;
    List_u next;
    }UTILIZADORES;

typedef struct salas *List_s;
typedef struct salas{
    char sala[NOME];
    int num;
    List_s next;
    }SALAS;

typedef struct reservas *List_r;
typedef struct reservas{
    int n_utilizador;
    int n_sala;
    int dia;
    int mes;
    int ano;
    int hora_ini1;
    int hora_ini2;
    int hora_fim1;
    int hora_fim2;
    List_r next;
    }RESERVAS;


