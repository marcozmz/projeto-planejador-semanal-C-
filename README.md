# 📅 Planejador Semanal em C

Este é um projeto de console desenvolvido em linguagem C como trabalho para a faculdade. O objetivo é permitir que o usuário organize e acompanhe suas tarefas semanais com funcionalidades completas de cadastro, listagem, busca e acompanhamento de progresso.

## 🛠 Funcionalidades

- Cadastro de tarefas com:
  - Nome
  - Descrição
  - Tempo estimado (horas)
  - Prioridade (`u` - urgente, `i` - importante, `a` - acessório)
  - Status (`0` - Pendente, `1` - Em Andamento, `2` - Concluído)
- Listagem de tarefas por:
  - Prioridade
  - Status
- Alteração do status de tarefas
- Cálculo do tempo total das tarefas pendentes
- Exibição do progresso semanal (porcentagem de tarefas concluídas)
- Busca de tarefas por palavra-chave (nome ou descrição)
- Sugestão aleatória de tarefa pendente (sugestão do dia)

## ▶️ Como executar

1. Compile o código com um compilador C, por exemplo:

```bash
gcc -o planejador planejador.c
