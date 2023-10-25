#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

struct FileReadError : public std::runtime_error
{
  FileReadError(const std::string &message) : std::runtime_error(message) {}
};

struct Instancia
{
  int n;
  int k;
  int Q;
  int L;
  int r;
  std::vector<int> d;
  std::vector<int> p;
  std::vector<std::vector<int>> c;
};

Instancia lerArquivo(const std::string &filepath)
{
  Instancia instancia;

  std::ifstream file(filepath);

  if (!file.is_open())
  {
    throw FileReadError("Erro ao abrir arquivo: " + filepath);
  }

  if (!(file >> instancia.n >> instancia.k >> instancia.Q >> instancia.L >> instancia.r))
  {
    throw FileReadError("Erro ao ler do arquivo: " + filepath);
  }

  instancia.d.clear();
  int value;
  for (int i = 0; i < instancia.n; ++i)
  {
    if (file >> value)
    {
      instancia.d.push_back(value);
    }
    else
    {
      throw FileReadError("Erro ao ler linha 7 do arquivo: " + filepath);
    }
  }

  instancia.p.clear();
  for (int i = 0; i < instancia.n; ++i)
  {
    if (file >> value)
    {
      instancia.p.push_back(value);
    }
    else
    {
      throw FileReadError("Erro ao ler linha 9 do arquivo: " + filepath);
    }
  }

  std::string line;
  std::getline(file, line);

  instancia.c.clear();
  for (int i = 0; i < instancia.n + 1; ++i)
  {
    std::vector<int> row;
    for (int j = 0; j < instancia.n + 1; ++j)
    {
      if (file >> value)
      {
        row.push_back(value);
      }
      else
      {
        throw FileReadError("Erro ao ler linha " + std::to_string(i + 1) + " da matriz c do arquivo: " + filepath);
      }
    }
    instancia.c.push_back(row);
  }

  return instancia;
}

// só é necessário para checagem
void imprimirValores(const Instancia &instancia)
{
  std::cout << "Valores lidos do arquivo:\n"
            << std::endl;
  std::cout << "n: " << instancia.n << std::endl;
  std::cout << "k: " << instancia.k << std::endl;
  std::cout << "Q: " << instancia.Q << std::endl;
  std::cout << "L: " << instancia.L << std::endl;
  std::cout << "r: " << instancia.r << std::endl;

  std::cout << "\nd: ";
  for (int i = 0; i < instancia.d.size(); ++i)
  {
    std::cout << instancia.d[i];
    if (i < instancia.d.size() - 1)
    {
      std::cout << "   ";
    }
  }
  std::cout << std::endl;

  std::cout << "\np: ";
  for (int i = 0; i < instancia.p.size(); ++i)
  {
    std::cout << instancia.p[i];
    if (i < instancia.p.size() - 1)
    {
      std::cout << "   ";
    }
  }
  std::cout << std::endl;

  std::cout << "\nc:" << std::endl;
  for (const auto &linha : instancia.c)
  {
    for (int valor : linha)
    {
      std::cout << valor << "   ";
    }
    std::cout << std::endl;
  }
}

void salvarDados(const std::string &filename, const Instancia &instancia)
{
  std::string filepath = "../data/resultados/" + filename + "_resultados.txt";
  std::ofstream arquivo(filepath);

  if (!arquivo.is_open())
  {
    throw std::runtime_error("Erro ao abrir arquivo para escrita");
  }

  arquivo << "Valores da instância " + filename + "\n"
          << std::endl;
  arquivo << "n: " << instancia.n << std::endl;
  arquivo << "k: " << instancia.k << std::endl;
  arquivo << "Q: " << instancia.Q << std::endl;
  arquivo << "L: " << instancia.L << std::endl;
  arquivo << "r: " << instancia.r << std::endl;

  arquivo << "\nd: ";
  for (int i = 0; i < instancia.d.size(); ++i)
  {
    arquivo << instancia.d[i];
    if (i < instancia.d.size() - 1)
    {
      arquivo << "   ";
    }
  }
  arquivo << std::endl;

  arquivo << "\np: ";
  for (int i = 0; i < instancia.p.size(); ++i)
  {
    arquivo << instancia.p[i];
    if (i < instancia.p.size() - 1)
    {
      arquivo << "   ";
    }
  }
  arquivo << std::endl;

  arquivo << "\nc:\n"
          << std::endl;
  for (const auto &linha : instancia.c)
  {
    for (int valor : linha)
    {
      arquivo << valor << "   ";
    }
    arquivo << std::endl;
  }

  arquivo.close();
}

int main()
{
  // Ler nome do arquivo por input do usuário
  /*std::string nomeArquivo;
  std::cout << "Digite o nome do arquivo (sem o caminho, apenas o nome do arquivo): ";
  std::cin >> nomeArquivo;*/

  std::string nomeArquivo = "n9k5_A";
  std::string caminhoArquivo = "../data/instancias/" + nomeArquivo + ".txt";

  try
  {
    Instancia instancia = lerArquivo(caminhoArquivo);
    imprimirValores(instancia);
    salvarDados(nomeArquivo, instancia);
  }
  catch (FileReadError &e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}