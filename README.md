# Pipex

Um programa em C que replica o comportamento de pipes do shell Unix/Linux, permitindo redirecionar a entrada e saída de comandos através de pipes.

## 📋 Índice

- [Sobre o Projeto](#sobre-o-projeto)
- [Compilação](#compilação)
- [Como Usar](#como-usar)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Funcionamento](#funcionamento)
- [Exemplos](#exemplos)
- [Tratamento de Erros](#tratamento-de-erros)
- [Requisitos](#requisitos)

## 🎯 Sobre o Projeto

O **Pipex** é um projeto da 42 School que implementa um programa capaz de executar dois comandos sequencialmente, conectados por um pipe, redirecionando a entrada do primeiro arquivo e a saída para um segundo arquivo.

### Comportamento

O programa simula o seguinte comando shell:
```bash
< infile cmd1 | cmd2 > outfile
```

Equivalente a:
```bash
./pipex infile cmd1 cmd2 outfile
```

## 🔨 Compilação

### Compilar o projeto

```bash
make
```

Este comando irá:
1. Compilar a biblioteca `libft`
2. Compilar os arquivos fonte do pipex
3. Gerar o executável `pipex`

### Outros comandos disponíveis

```bash
make clean   # Remove arquivos objeto
make fclean  # Remove arquivos objeto e executável
make re      # Recompila tudo do zero
```

## 💻 Como Usar

### Sintaxe

```bash
./pipex <arquivo_entrada> <comando1> <comando2> <arquivo_saida>
```

### Parâmetros

- **arquivo_entrada**: Arquivo que será usado como entrada para o primeiro comando
- **comando1**: Primeiro comando a ser executado
- **comando2**: Segundo comando a ser executado (recebe a saída do primeiro)
- **arquivo_saida**: Arquivo onde será gravada a saída final

### Observações

- Os comandos devem estar entre aspas se contiverem argumentos
- O programa procura os executáveis nas pastas definidas na variável PATH
- O arquivo de saída é criado com permissões 0644 (rw-r--r--)

## 📁 Estrutura do Projeto

```
pipex/
├── includes/
│   └── pipex.h              # Header principal do projeto
├── srcs/
│   ├── pipex.c              # Função main e lógica principal
│   └── utils.c              # Funções auxiliares
├── libft/                   # Biblioteca de funções customizadas
│   ├── includes/
│   │   └── libft.h
│   └── srcs/
│       ├── ctypes/          # Funções de caracteres
│       ├── gnl/             # Get Next Line
│       ├── lists/           # Manipulação de listas
│       ├── memory/          # Gerenciamento de memória
│       ├── printf/          # Printf customizado
│       ├── stdio/           # Funções de I/O
│       ├── stdlib/          # Funções padrão
│       └── string/          # Manipulação de strings
├── makefile
└── LICENSE
```

## ⚙️ Funcionamento

### Estrutura de Dados

```c
typedef struct s_pipex
{
    char    **cmd1_args;     // Argumentos do comando 1
    char    **cmd2_args;     // Argumentos do comando 2
    char    *infile;         // Nome do arquivo de entrada
    char    *outfile;        // Nome do arquivo de saída
} t_pipex;
```

### Fluxo de Execução

1. **Validação**: Verifica se foram passados exatamente 4 argumentos
2. **Inicialização**: Parse dos comandos e criação da estrutura de dados
3. **Criação do Pipe**: Estabelece a comunicação entre processos
4. **Fork 1**: Cria o primeiro processo filho
   - Abre o arquivo de entrada
   - Redireciona STDIN para o arquivo
   - Redireciona STDOUT para o pipe
   - Executa o primeiro comando
5. **Fork 2**: Cria o segundo processo filho
   - Redireciona STDIN para o pipe
   - Abre/cria o arquivo de saída
   - Redireciona STDOUT para o arquivo
   - Executa o segundo comando
6. **Processo Pai**: Aguarda o término dos processos filhos

### Funções Principais

#### `get_cmd_path()`
Procura o caminho completo de um comando na variável PATH do sistema.

```c
char *get_cmd_path(char *cmd, char **envp);
```

#### `execute_command()`
Executa um comando com seus argumentos usando `execve`.

```c
void execute_command(char **cmds_args, char **envp);
```

#### `error_exit()`
Exibe mensagem de erro, libera memória e encerra o programa.

```c
void error_exit(char *msg, t_pipex *data);
```

## 📝 Exemplos

### Exemplo 1: Contando linhas

Simula: `< input.txt cat | wc -l > output.txt`

```bash
./pipex input.txt "cat" "wc -l" output.txt
```

### Exemplo 2: Buscando e contando

Simula: `< file.txt grep "pattern" | wc -w > result.txt`

```bash
./pipex file.txt "grep pattern" "wc -w" result.txt
```

### Exemplo 3: Listando e ordenando

Simula: `< /dev/null ls -la | grep ".c" > files.txt`

```bash
./pipex /dev/null "ls -la" "grep .c" files.txt
```

### Exemplo 4: Processamento de texto

Simula: `< data.txt sort | uniq > unique.txt`

```bash
./pipex data.txt "sort" "uniq" unique.txt
```

## ⚠️ Tratamento de Erros

O programa trata os seguintes erros:

### Erro de Argumentos
```bash
# Número incorreto de argumentos
./pipex file1 cmd1
# Output: parse error near `\n'
```

### Erro de Arquivo de Entrada
```bash
# Arquivo não existe ou sem permissão de leitura
./pipex arquivo_inexistente.txt "cat" "wc -l" output.txt
# Output: pipex: infile: No such file or directory
```

### Erro de Comando
```bash
# Comando não encontrado no PATH
./pipex input.txt "comando_invalido" "wc -l" output.txt
# Output: pipex: command not found: comando_invalido
```

### Erro de Pipe/Fork
```bash
# Falha ao criar pipe ou processo
# Output: pipex: pipe: [mensagem do sistema]
# ou
# Output: pipex: fork: [mensagem do sistema]
```

## 📦 Requisitos

### Sistema Operacional
- Linux ou macOS (Unix-like)

### Compilador
- GCC ou Clang com suporte a C99

### Bibliotecas
- Bibliotecas padrão do C (libc)

### Flags de Compilação
```
-Wall -Wextra -Werror -g3
```

## 🔍 Chamadas de Sistema Utilizadas

- `open()`: Abertura de arquivos
- `close()`: Fechamento de file descriptors
- `read()`: Leitura de dados
- `write()`: Escrita de dados
- `malloc()` / `free()`: Alocação/liberação de memória
- `fork()`: Criação de processos
- `pipe()`: Criação de pipes
- `dup2()`: Duplicação de file descriptors
- `execve()`: Execução de comandos
- `waitpid()`: Espera por processos filhos
- `access()`: Verificação de permissões
- `perror()`: Exibição de erros

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

## 👤 Autor

**Claudio Matheus** - [clados-s](https://github.com/claudio1code)

---

*Projeto desenvolvido como parte do currículo da 42 School*
