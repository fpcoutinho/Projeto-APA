#include <iostream>
#include <fstream>
#include <vector>

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
    std::cerr << "Erro ao abrir arquivo: " << std::endl;
    return instancia; // Retorna uma struct vazia em caso de erro
  }

  if (!(file >> instancia.n >> instancia.k >> instancia.Q >> instancia.L >> instancia.r))
  {
    std::cerr << "Erro ao ler do arquivo: " << std::endl;
    return instancia;
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
      std::cerr << "Erro ao ler linha 7 do arquivo: " << std::endl;
      return instancia;
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
      std::cerr << "Erro ao ler linha 9 do arquivo: " << std::endl;
      return instancia;
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
        std::cerr << "Erro ao ler linha " << (i + 1) << " da matriz c do arquivo: " << std::endl;
        return instancia;
      }
    }
    instancia.c.push_back(row);
  }

  return instancia;
}

void imprimirValores(const Instancia &instancia)
{
  std::cout << "Valores lidos do arquivo:\n"
            << std::endl;
  std::cout << "n: " << instancia.n << std::endl;
  std::cout << "k: " << instancia.k << std::endl;
  std::cout << "Q: " << instancia.Q << std::endl;
  std::cout << "L: " << instancia.L << std::endl;
  std::cout << "r: " << instancia.r << std::endl;

  std::cout << "\nVetor d: ";
  for (int i = 0; i < instancia.d.size(); ++i)
  {
    std::cout << instancia.d[i];
    if (i < instancia.d.size() - 1)
    {
      std::cout << "   ";
    }
  }
  std::cout << std::endl;

  std::cout << "\nVetor p: ";
  for (int i = 0; i < instancia.p.size(); ++i)
  {
    std::cout << instancia.p[i];
    if (i < instancia.p.size() - 1)
    {
      std::cout << "   ";
    }
  }
  std::cout << std::endl;

  std::cout << "\nMatriz c:" << std::endl;
  for (const auto &linha : instancia.c)
  {
    for (int valor : linha)
    {
      std::cout << valor << "   ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  // Ler nome do arquivo por input do usuário
  /*std::string nomeArquivo;
  std::cout << "Digite o nome do arquivo (sem o caminho, apenas o nome do arquivo): ";
  std::cin >> nomeArquivo;*/

  std::string nomeArquivo = "n9k5_A";

  std::string caminhoArquivo = "../data/instancias/" + nomeArquivo + ".txt";

  Instancia instancia = lerArquivo(caminhoArquivo);

  if (instancia.n == 0)
  {
    std::cerr << "Falha ao ler o arquivo." << std::endl;
    return 1;
  }
  else
  {
    imprimirValores(instancia);
  }

  return 0;
}