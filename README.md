# **SIG-Aninha: Uma Cigana Virtual**

## **Descrição do Projeto**

O **SIG-Aninha** é um sistema de gestão desenvolvido como uma **cigana virtual**. O projeto foi criado como parte da avaliação da disciplina de Programação na UFRN no 2° período de BSI.

O sistema permite gerenciar clientes, agendamentos, consultas online (serviços), funcionários e relatórios, facilitando o controle de atividades tanto online quanto presencialmente.

---

## **Estrutura, Modularização e Compilação**

O projeto é **modular**, com cada funcionalidade principal organizada em arquivos e pastas separadas, facilitando o desenvolvimento, manutenção e futuras expansões.

---

## **Compilação do Projeto no Linux**

1. Instale a extensão **Makefile Tools** no VSCode (opcional, mas facilita a gestão do Makefile).
2. Abra o terminal e navegue até a pasta do projeto.
3. Compile e execute o projeto:

```bash
make
./main
```

---

## **Compilação do Projeto no Windows**

O Windows requer o MSYS2, que emula um terminal Linux e permite usar ferramentas como `make` e `gcc`.

### **Pré-requisitos**

* MSYS2 instalado: [https://www.msys2.org](https://www.msys2.org)
* GCC instalado
* Make instalado

### **1. Instalação do MSYS2 e Make**

1. Baixe e instale o MSYS2.
2. Abra o terminal do MSYS2 e atualize os pacotes:

```bash
pacman -Syu
```

3. Instale o `make`:

```bash
pacman -S make
```

### **2. Configuração do GCC**

1. Verifique a instalação do GCC:

```bash
gcc --version
```

2. Caso não esteja instalado:

```bash
pacman -S mingw-w64-x86_64-gcc
```

3. Verifique se o GCC está no PATH:

```bash
echo $PATH
```

4. Se necessário, adicione o GCC ao PATH:

```bash
export PATH=$PATH:/mingw64/bin
```

5. Feche e abra o terminal do MSYS2 para aplicar as alterações.

### **3. Compilação e execução**

1. Navegue até a pasta do projeto:

```bash
cd caminho/para/o/projeto
```

2. Compile e execute o projeto usando o Makefile:

```bash
make run
```
Compilação Manual (alternativa):
Caso não queira usar o makefile (recomendável) você pode compilar manualmente com o comando abaixo no terminal do VSCode ou do MSYS2:
 
```bash
gcc main.c utilitarios.c cliente.c agendamento.c servicos.c funcionario.c relatorio.c informacoes.c -o projeto
```
E depois o comando:
```bash
./projeto
```
---

## **Tecnologias Utilizadas**

* Linguagem C
* GCC (GNU Compiler Collection)
* Make / Makefile
* MSYS2 (para ambiente Windows)
* VSCode (editor recomendado)

---

## **Principais Funcionalidades**

Gerenciamento de Clientes: cadastro, edição, consulta, listagem e exclusão.

Agendamentos: marcação, alteração, exclusão e controle completo de consultas.

Serviços Online: consultas interativas, incluindo Signos, Numerologia, Perguntas e Cartas de Tarot.

Gestão de Funcionários: cadastro, listagem, atualização e exclusão de funcionários.

Relatórios: geração de relatórios detalhados de clientes, agendamentos, funcionários e serviços.

Interface Modular: cada funcionalidade está separada em arquivos distintos, facilitando manutenção, leitura do código e expansão futura.