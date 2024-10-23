#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Definindo o tamanho máximo da fila

// Estrutura para representar a fila
typedef struct {
    int front, rear, size;
    int array[MAX];
} Queue;

// Função para criar uma fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

// Função para verificar se a fila está cheia
int isFull(Queue* q) {
    return q->size == MAX;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Função para adicionar um cliente à fila
void enqueue(Queue* q, int customer) {
    if (isFull(q)) {
        printf("Fila cheia! Não é possível adicionar mais clientes.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->array[q->rear] = customer;
    q->size++;
    printf("Cliente %d adicionado à fila.\n", customer);
}

// Função para remover um cliente da fila
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Fila vazia! Nenhum cliente para atender.\n");
        return -1;
    }
    int customer = q->array[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    printf("Cliente %d foi atendido.\n", customer);
    return customer;
}

// Função para exibir a fila
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila atual: ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->array[(q->front + i) % MAX]);
    }
    printf("\n");
}

// Função principal com interação com o usuário
int main() {
    Queue* queue = createQueue();
    int opcao, cliente, idCliente = 1;

    do {
        printf("\nSistema de Atendimento\n");
        printf("1. Adicionar cliente à fila\n");
        printf("2. Atender cliente\n");
        printf("3. Exibir fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // Adicionar cliente à fila
                printf("Adicionando cliente %d à fila...\n", idCliente);
                enqueue(queue, idCliente);
                idCliente++; // Incrementa o ID do próximo cliente
                break;
            case 2: // Atender cliente
                cliente = dequeue(queue);
                if (cliente != -1) {
                    printf("Cliente %d foi atendido.\n", cliente);
                }
                break;
            case 3: // Exibir fila
                displayQueue(queue);
                break;
            case 4: // Sair
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 4);
    
    free(queue);

    return 0;
}