#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente{
  char nome[50];
  char telefone;
  char rua [50];
  char bairro [50];
  char numero;
  char complemento [30];
  char cidade [30];
  char estado [50];
  int cep;
  int codigo;

}Cliente;

void cadastro_do_cliente (Cliente *cliente){ //CADASTRO DO CLIENTE
    
  puts("Nome: ");
  fgets(cliente->nome, sizeof(cliente->nome),stdin);
  puts("Telefone: ");
  scanf("%s", &cliente->telefone);
  puts("Rua: ");
  fgets(cliente->rua, sizeof(cliente->rua),stdin);
  puts("Bairro: ");
  fgets(cliente->bairro, sizeof(cliente->bairro),stdin);
  puts("Numero: ");
  scanf("%s", &cliente->numero);
  puts("Complemento: ");
  fgets(cliente->complemento, sizeof(cliente->complemento),stdin);
  puts("Cidade: ");
  fgets(cliente->cidade, sizeof(cliente->cidade),stdin);
  puts("Estado: ");
  fgets(cliente->estado, sizeof(cliente->estado),stdin);
  puts("CEP: ");
  scanf("%i", &cliente->cep);
  printf("\nCódigo: ");
  for (int i = 0; i < 10; i++){
  printf("%d",rand() %10);
  }
}

void printCliente (Cliente cliente){
  printf("Nome: %s", cliente.nome);
  printf("Telefone: %i", cliente.telefone);
  printf("Rua: %s", cliente.rua);
  printf("Bairro: %s", cliente.bairro);
  printf("Numero: %i", cliente.numero);
  printf("Complemento: %s", cliente.complemento);
  printf("Cidade: %s",cliente.cidade);
  printf("Estado: %s", cliente.estado);
  printf("CEP: %i", cliente.cep);
  printf("Código: %d",cliente.codigo);

  printf("\n");
}

void salvarCliente (Cliente cliente){
  FILE *arq;
  arq = fopen ("Cliente.db","ab");
  fwrite (&cliente, sizeof(cliente), 1, arq);
  fclose(arq);
}

void loadCliente (int a, Cliente *cliente){
  FILE *arq;
  arq = fopen ("Cliente.db","rb");
  fseek(arq, sizeof(Cliente)*a, SEEK_SET);
  fread(cliente, sizeof(Cliente), 1, arq);
  fclose(arq);
}


typedef struct Funcionario{ //CADASTRO DO FUNCIONARIO
  char nome[50];
  int telefone;
  int codigo;
  char cargo [20];
  float salario;

}Funcionario;

void cadastro_do_funcionario (Funcionario *funcionario){ 
  puts("Nome: ");
  fgets(funcionario->nome, sizeof(funcionario->nome),stdin);
  puts("Telefone: ");
  scanf("%i", &funcionario->telefone);
  puts("Cargo: ");
  fgets(funcionario->cargo, sizeof(funcionario->cargo),stdin);
  puts("Salário: ");
  scanf("%f", &funcionario->salario);
  printf("\nCódigo: ");
  for (int i = 0; i < 10; i++){
  printf("%d",rand() %10);
  }
}

void printFuncionario (Funcionario funcionario){
  printf("Nome: %s", funcionario.nome);
  printf("Telefone: %i", funcionario.telefone);
  printf("Cargo: %s", funcionario.cargo);
  printf("Salário: %f", funcionario.salario);
  printf("Código: %d",funcionario.codigo);

  printf("\n");
}

void salvarFuncionario (Funcionario funcionario){
  FILE *arq;
  arq = fopen ("Funcionario.db","ab");
  fwrite (&funcionario, sizeof(funcionario), 1, arq);
  fclose(arq);
}

void loadFuncionario (int a, Funcionario *funcionario){
  FILE *arq;
  arq = fopen ("Funcionario.db","rb");
  fseek(arq, sizeof(Funcionario)*a, SEEK_SET);
  fread(funcionario, sizeof(Funcionario), 1, arq);
  fclose(arq);
}

int main(){

  printf("\n\n\t\t\t\t Hotel Descanso Garantido \n\n\n");

  Cliente cliente;
  
  Cliente c1;
  printCliente(c1);

  return 0;
  
}