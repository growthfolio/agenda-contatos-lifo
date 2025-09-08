# Guia de Instalação - Agenda LIFO

Este documento fornece instruções detalhadas para instalação e configuração do projeto Agenda de Contatos LIFO em diferentes plataformas.

## 📋 Pré-requisitos

### Requisitos Mínimos do Sistema

- **Sistema Operacional**: Windows 10+, Linux (Ubuntu 18.04+), macOS 10.14+
- **Compilador C++**: GCC 7.0+, Clang 6.0+, ou MSVC 2017+
- **Padrão C++**: C++17 ou superior
- **RAM**: 512 MB (mínimo)
- **Espaço em Disco**: 50 MB

### Ferramentas Necessárias

- **Git**: Para clonagem do repositório
- **Make**: Para automação de build (opcional)
- **IDE/Editor**: Code::Blocks, Dev-C++, Visual Studio, VS Code, CLion

## 🪟 Instalação no Windows

### Opção 1: MinGW-w64 (Recomendado)

1. **Instalar MinGW-w64**:
   ```bash
   # Baixe de: https://www.mingw-w64.org/downloads/
   # Ou use o instalador MSYS2
   ```

2. **Configurar PATH**:
   ```bash
   # Adicione ao PATH do sistema:
   C:\mingw64\bin
   ```

3. **Verificar instalação**:
   ```bash
   gcc --version
   g++ --version
   ```

4. **Clonar e compilar**:
   ```bash
   git clone https://github.com/growthfolio/agenda-contatos-lifo.git
   cd agenda-contatos-lifo
   g++ -std=c++17 -Wall -Wextra -O2 src/main.cpp -o agenda.exe
   agenda.exe
   ```

### Opção 2: Visual Studio

1. **Instalar Visual Studio Community** (gratuito)
2. **Incluir**: "Desenvolvimento para desktop com C++"
3. **Abrir projeto**:
   - File → New → Project from Existing Code
   - Selecionar pasta do projeto
   - Configurar como Console Application

### Opção 3: Code::Blocks

1. **Baixar Code::Blocks** com MinGW incluído
2. **Criar novo projeto**:
   - File → New → Project → Console Application
   - Copiar código do `src/main.cpp`
3. **Configurar compilador**:
   - Settings → Compiler → GNU GCC Compiler
   - Compiler Flags: `-std=c++17 -Wall -Wextra`

## 🐧 Instalação no Linux

### Ubuntu/Debian

```bash
# Atualizar repositórios
sudo apt update

# Instalar ferramentas de desenvolvimento
sudo apt install build-essential git make

# Verificar versão do GCC
gcc --version  # Deve ser 7.0 ou superior

# Clonar repositório
git clone https://github.com/growthfolio/agenda-contatos-lifo.git
cd agenda-contatos-lifo

# Compilar usando Makefile
make build

# Ou compilar diretamente
g++ -std=c++17 -Wall -Wextra -O2 src/main.cpp -o agenda

# Executar
./agenda
```

### CentOS/RHEL/Fedora

```bash
# CentOS/RHEL
sudo yum groupinstall "Development Tools"
sudo yum install git

# Fedora
sudo dnf groupinstall "Development Tools"
sudo dnf install git

# Seguir mesmos passos do Ubuntu
```

### Arch Linux

```bash
# Instalar ferramentas
sudo pacman -S base-devel git

# Seguir mesmos passos do Ubuntu
```

## 🍎 Instalação no macOS

### Opção 1: Xcode Command Line Tools

```bash
# Instalar Xcode Command Line Tools
xcode-select --install

# Verificar instalação
clang --version

# Clonar e compilar
git clone https://github.com/growthfolio/agenda-contatos-lifo.git
cd agenda-contatos-lifo
clang++ -std=c++17 -Wall -Wextra -O2 src/main.cpp -o agenda
./agenda
```

### Opção 2: Homebrew

```bash
# Instalar Homebrew (se não tiver)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Instalar GCC
brew install gcc git

# Compilar com GCC
g++-11 -std=c++17 -Wall -Wextra -O2 src/main.cpp -o agenda
```

## 🔧 Usando o Makefile

O projeto inclui um Makefile para automação de build:

```bash
# Compilar o projeto
make build

# Compilar em modo debug
make debug

# Executar o programa
make run

# Limpar arquivos compilados
make clean

# Mostrar ajuda
make help
```

### Targets Disponíveis

- `build`: Compilação otimizada para produção
- `debug`: Compilação com símbolos de debug
- `run`: Executa o programa após compilar
- `clean`: Remove arquivos executáveis
- `install`: Instala o programa no sistema (Linux/macOS)
- `test`: Executa testes básicos

## 🏫 Configuração para IDEs Populares

### Visual Studio Code

1. **Instalar extensões**:
   - C/C++ (Microsoft)
   - C++ Intellisense
   - Code Runner

2. **Configurar tasks.json**:
   ```json
   {
       "version": "2.0.0",
       "tasks": [
           {
               "label": "build",
               "type": "shell",
               "command": "g++",
               "args": [
                   "-std=c++17",
                   "-Wall",
                   "-Wextra",
                   "-O2",
                   "src/main.cpp",
                   "-o",
                   "agenda"
               ],
               "group": {
                   "kind": "build",
                   "isDefault": true
               }
           }
       ]
   }
   ```

### CLion

1. **Abrir projeto**: File → Open → Selecionar pasta
2. **CMakeLists.txt** será criado automaticamente
3. **Configurar**: Run → Edit Configurations

### Dev-C++

1. **Criar novo projeto**: File → New → Project
2. **Selecionar**: Console Application
3. **Copiar código** do `src/main.cpp`
4. **Configurar compilador**: Tools → Compiler Options
   - Adicionar: `-std=c++17`

## 🧪 Verificação da Instalação

Execute os seguintes testes para verificar se tudo está funcionando:

```bash
# Teste 1: Compilação
g++ -std=c++17 -Wall -Wextra src/main.cpp -o teste_agenda

# Teste 2: Execução básica
echo "7" | ./teste_agenda  # Deve mostrar menu "Sobre"

# Teste 3: Verificar funcionalidades
# Execute o programa e teste cada opção do menu
```

## 🚨 Solução de Problemas

### Erro: "g++ não é reconhecido"

**Windows**:
- Verificar se MinGW está no PATH
- Reiniciar terminal/prompt
- Usar caminho completo: `C:\mingw64\bin\g++`

**Linux/macOS**:
```bash
# Instalar build-essential (Ubuntu)
sudo apt install build-essential

# Verificar PATH
echo $PATH
which g++
```

### Erro: "std::c++17 não suportado"

```bash
# Verificar versão do compilador
g++ --version

# Usar versão específica se necessário
g++-9 -std=c++17 src/main.cpp -o agenda
```

### Erro de Permissão (Linux/macOS)

```bash
# Dar permissão de execução
chmod +x agenda

# Ou executar com sudo se necessário
sudo ./agenda
```

### Problemas de Encoding

Se caracteres especiais não aparecem corretamente:

**Windows**:
```bash
# No prompt, configurar UTF-8
chcp 65001
```

**Linux/macOS**:
```bash
# Verificar locale
locale
export LANG=pt_BR.UTF-8
```

## 📚 Recursos Adicionais

### Documentação Oficial

- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [C++ Reference](https://en.cppreference.com/)
- [Git Documentation](https://git-scm.com/doc)

### Tutoriais Recomendados

- [C++ Tutorial - cplusplus.com](http://www.cplusplus.com/doc/tutorial/)
- [Learn C++ - learncpp.com](https://www.learncpp.com/)
- [Git Tutorial - Atlassian](https://www.atlassian.com/git/tutorials)

### Comunidades

- [Stack Overflow - C++](https://stackoverflow.com/questions/tagged/c%2b%2b)
- [Reddit - r/cpp](https://www.reddit.com/r/cpp/)
- [C++ Brasil - Telegram](https://t.me/cppbrasil)

## 📞 Suporte

Se encontrar problemas durante a instalação:

1. **Verifique os pré-requisitos** listados acima
2. **Consulte a seção de troubleshooting**
3. **Abra uma issue** no repositório GitHub
4. **Entre em contato** com o desenvolvedor

---

**Desenvolvido por Felipe Macedo - FMU | FIAM-FAAM**  
*Projeto Acadêmico - Ciências da Computação*