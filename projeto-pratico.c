#include <stdio.h>
#include <string.h>


#define MAX_TAREFAS 20
#define MAX_STRING_LEN 50

int total = 0; 
char descricao[MAX_TAREFAS][MAX_STRING_LEN];
char nome[MAX_TAREFAS][MAX_STRING_LEN];
float tempoEstimado[MAX_TAREFAS];
char prioridade[MAX_TAREFAS];
int status[MAX_TAREFAS];


void exibirMenu(){
    printf("\n============ PLANEJADOR SEMANAL =============\n");
    printf("1. Cadastrar nova tarefa\n");
    printf("2. Listar todas as tarefas por prioridade\n");
    printf("3. Alterar status de uma tarefa\n");
    printf("4. Listar tarefas por status\n");
    printf("5. Calcular tempo total das tarefas pendentes\n");
    printf("6. Ver progresso da semana\n");
    printf("7. Buscar tarefas por palavra-chave\n");
    printf("8. Sugestão do dia\n");
    printf("0. Sair\n");
    printf("=============================================\n");
}

int verificarQntTarefas(){
    if(total < MAX_TAREFAS){
        return 1; 
    } else {
        return 0;
    }
}

void cadastrarTarefa(){ 
    int verificacao;
    int opcao;

    do{
        verificacao = verificarQntTarefas();

        if(verificacao == 1){
            printf("Tem %d tarefas cadastradas. Pode cadastrar...\n", total);

            printf("Digite um nome (max %d caracteres): ", MAX_STRING_LEN - 1);
            while (getchar() != '\n');
            fgets(nome[total], sizeof(nome[total]), stdin);
            nome[total][strcspn(nome[total], "\n")] = 0;
 

            printf("Digite uma breve descrição (max %d caracteres): ", MAX_STRING_LEN - 1);
            fgets(descricao[total], sizeof(descricao[total]), stdin);
            descricao[total][strcspn(descricao[total], "\n")] = 0;

            printf("Digite o tempo estimado em horas para completa-la: ");
            scanf("%f", &tempoEstimado[total]);
            while (getchar() != '\n');

            printf("Digite a prioridade [u] urgente | [i] importante | [a] acessorio: ");
            scanf("%c", &prioridade[total]);
            while (getchar() != '\n');

            printf("Digite o status [0] Pendente | [1] Em Andamento | [2] Concluido: ");
            scanf("%d", &status[total]);
            while (getchar() != '\n');

            
            total++; 
            printf("Tarefa cadastrada com sucesso!\n");
        } else {
            printf("O limite de %d tarefas já foram atingidos. Atualmente %d tarefas cadastradas.\n", MAX_TAREFAS, total);
        }

        printf("\nCadastrar nova tarefa [1]\nVoltar ao menu [0]\nOpção: ");
        scanf("%d", &opcao);

    }while(opcao == 1);

}


void listarTarefas() {
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada para listar.\n");
        return;
    }
    printf("\n--- Todas as Tarefas ---\n");
    for (int i = 0; i < total; i++) {
        printf("Tarefa %d - Nome: %s | Descrição: %s | Tempo: %.2f h | Prioridade: %c | Status: %d\n", 
            i + 1, nome[i], descricao[i], tempoEstimado[i], prioridade[i], status[i]);
    }
    printf("------------------------\n\n");
}

void exibirTarefasPrioridade() {
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada para listar por prioridade.\n");
        return;
    }

    printf("\n--- Tarefas URGENTES (u) ---\n");
    for (int i = 0; i < total; i++) {
        if (prioridade[i] == 'u') {
            printf("- %s | %s | %.2fh | Status: %d\n", nome[i], descricao[i], tempoEstimado[i], status[i]);
            
        }
    }

    printf("\n--- Tarefas IMPORTANTES (i) ---\n");
    for (int i = 0; i < total; i++) {
        if (prioridade[i] == 'i') {
            printf("- %s | %s | %.2f h | Status: %d\n", nome[i], descricao[i], tempoEstimado[i], status[i]);
        }
    }

    printf("\n--- Tarefas ACESSÓRIAS (a) ---\n");
    for (int i = 0; i < total; i++) {
        if (prioridade[i] == 'a') {
            printf("- %s | %s | %.2f h | Status: %d\n", nome[i], descricao[i], tempoEstimado[i], status[i]);
        }
    }
    printf("-------------------------------\n\n");
}


void alterarStatus(){
    int indice;
    int statusNovo;

    if (total == 0) {
        printf("Nenhuma tarefa cadastrada para alterar o status.\n");
        return;
    }

    listarTarefas();

    printf("Digite o número da tarefa que deseja alterar o status: ");
    scanf("%d", &indice);

    indice--; 

    if (indice >= 0 && indice < total) { 
        printf("A tarefa selecionada é: %s\n", nome[indice]);
        printf("Deseja alterar para qual status? [0] Pendente | [1] Em Andamento | [2] Concluido: ");
        scanf("%d", &statusNovo);

        if (statusNovo >= 0 && statusNovo <= 2) {
            status[indice] = statusNovo;
            printf("Status da tarefa '%s' alterado para %d com sucesso!\n", nome[indice], statusNovo);
        } else {
            printf("Status inválido. Por favor, digite 0, 1 ou 2.\n");
        }
    } else {
        printf("Índice de tarefa inválido. Por favor, digite um número entre 1 e %d.\n", total);
    }
}

void exibirStatus(){ 
    int statusEscolhido;

    if (total == 0) {
        printf("Nenhuma tarefa cadastrada para exibir por status.\n");
        return;
    }

    printf("As tarefas de qual status deseja verificar? [0] Pendente | [1] Em Andamento | [2] Concluido: ");
    scanf("%d", &statusEscolhido);

    if (statusEscolhido < 0 || statusEscolhido > 2) {
        printf("Status inválido. Por favor, digite 0, 1 ou 2.\n");
        return;
    }

    printf("\n--- Tarefas com Status %d ---\n", statusEscolhido);
    for(int i = 0; i < total; i++){
        if(statusEscolhido == status[i]){
            printf("Nome: %s | Descrição: %s | Tempo: %.2f h | Prioridade: %c\n", 
                   nome[i], descricao[i], tempoEstimado[i], prioridade[i]);
        }
    }
    printf("-------------------------------\n\n");
}

void calcularTempoTotal(){
    float tempoTotal = 0;

    if (total == 0) {
        printf("Nenhuma tarefa cadastrada para calcular o tempo.\n");
        return;
    }

    for(int i = 0; i < total; i++){
        if (status[i] == 0) {
            tempoTotal += tempoEstimado[i];
        }
    }

    printf("O tempo total estimado das tarefas pendentes é: %.2fh\n", tempoTotal);
}


void exibirProgresso(){
    int qntConcludas = 0;
    float porcentualConclusao = 0;

    printf("O total de tarefas cadastradas é %d\n", total);

    for(int i = 0; i < total; i++){
        if(status[i] == 2){
            qntConcludas++;
        }
    }

    porcentualConclusao = ((float)qntConcludas / total) * 100;

    printf("Você tem %d/%d de tarefas concluidas um porcentual de %.2f%% \n", qntConcludas, total, porcentualConclusao);

}

void buscarPalavraChave(){
    char strDigitada[MAX_STRING_LEN];
    int verificador = 0;

    printf("Digite a palavra-chave que deseja buscar: ");
    scanf("%s", strDigitada);

    for(int i = 0; i < total; i++){
        if(strstr(nome[i], strDigitada) || strstr(descricao[i], strDigitada)){
            printf("Tarefa encontrada: %s | Descrição: %s | Tempo: %.2f h | Prioridade: %c | Status: %d\n", 
                   nome[i], descricao[i], tempoEstimado[i], prioridade[i], status[i]);
            verificador++;
        }
    }

    if(verificador == 0){
        printf("Nenhuma tarefa encontrada com esta palavra.\n");
    }
}

void exibirSugestao(){
    srand(time(NULL));
    int numeroMaximoSorteio = 0;
    int numeroSorteado = 0;
    int tarefasValidas[MAX_TAREFAS];

    for(int i = 0; i < total; i++){
        if(status[i] == 0){
            tarefasValidas[numeroMaximoSorteio] = i;
            numeroMaximoSorteio++;
        }
    }

    if (numeroMaximoSorteio == 0) {
        printf("Nenhuma tarefa com status 0 disponível para sugestão.\n");
        return;
    }

    numeroSorteado = rand() % numeroMaximoSorteio;
    int indice = tarefasValidas[numeroSorteado];

    printf("A sugestão do dia é a tarefa: %s | Descrição: %s | Tempo: %.2f h | Prioridade: %c | Status: %d\n", nome[indice], descricao[indice], tempoEstimado[indice], prioridade[indice], status[indice]);
}

int main(){
    int opcao = 0;

    do{
        exibirMenu();
        printf("\nQual sua opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                printf("Saindo do software...\n");
                break;
            
            case 1:
                cadastrarTarefa();
                break;

            case 2:
                exibirTarefasPrioridade();
                break;

            case 3:
                alterarStatus(); 
                break;

            case 4:
                exibirStatus(); 
                break;
            
            case 5:
                calcularTempoTotal();
                break;

            case 6:
                exibirProgresso();
                break;

            case 7:
                buscarPalavraChave();
                break;

            case 8:
                exibirSugestao();
                break;

            default:
                printf("Opção inválida! Por favor, escolha uma opção entre 0 e 8.\n");
                break;
        }
    }while(opcao != 0);

    return 0;
}