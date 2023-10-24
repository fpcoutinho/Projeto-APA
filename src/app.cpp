#include <iostream>
#include <fstream>
#include <vector>
#include <vector>

bool lerArquivo(const std::string &filename, int &n, int &k, int &Q, int &L, int &r, std::vector<int> &d, std::vector<int> &p, std::vector<std::vector<int>> &c)
{
  std::ifstream file(filename);

  if (!file.is_open())
  {
    std::cerr << "Erro ao abrir arquivo: " << filename << std::endl;
    return false;
  }

  // Read the first 5 lines and assign values to variables
  if (!(file >> n >> k >> Q >> L >> r))
  {
    std::cerr << "Erro ao ler do arquivo: " << filename << std::endl;
    return false;
  }

  // Read line 7 into vector d
  d.clear();
  int value;
  for (int i = 0; i < n; ++i)
  {
    if (file >> value)
    {
      d.push_back(value);
    }
    else
    {
      std::cerr << "Erro ao ler linha 7 do arquivo: " << filename << std::endl;
      return false;
    }
  }

  // Read line 9 into vector p
  p.clear();
  for (int i = 0; i < n; ++i)
  {
    if (file >> value)
    {
      p.push_back(value);
    }
    else
    {
      std::cerr << "Erro ao ler linha 9 do arquivo: " << filename << std::endl;
      return false;
    }
  }

  // Clear the next line
  std::string line;
  std::getline(file, line);

  // Read the next (n+1) lines as an (n+1)x(n+1) matrix (renamed to c)
  c.clear();
  for (int i = 0; i < n + 1; ++i)
  {
    std::vector<int> row;
    for (int j = 0; j < n + 1; ++j)
    {
      if (file >> value)
      {
        row.push_back(value);
      }
      else
      {
        std::cerr << "Erro ao ler linha " << (i + 1) << " da matriz c do arquivo: " << filename << std::endl;
        return false;
      }
    }
    c.push_back(row);
  }

  return true;
}

void imprimirValores(const int n, const int k, const int Q, const int L, const int r, const std::vector<int> &d, const std::vector<int> &p, const std::vector<std::vector<int>> &c)
{
  std::cout << "Valores lidos do arquivo:\n"
            << std::endl;
  std::cout << "n: " << n << std::endl;
  std::cout << "k: " << k << std::endl;
  std::cout << "Q: " << Q << std::endl;
  std::cout << "L: " << L << std::endl;
  std::cout << "r: " << r << std::endl;

  std::cout << "\nVetor d: ";
  for (int i = 0; i < d.size(); ++i)
  {
    std::cout << d[i];
    if (i < d.size() - 1)
    {
      std::cout << "   ";
    }
  }
  std::cout << std::endl;

  std::cout << "\nVetor p: ";
  for (int i = 0; i < p.size(); ++i)
  {
    std::cout << p[i];
    if (i < p.size() - 1)
    {
      std::cout << "   ";
    }
  }
  std::cout << std::endl;

  std::cout << "\nMatriz c:" << std::endl;
  for (const auto &linha : c)
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

  int n, k, Q, L, r;
  std::vector<int> d, p;
  std::vector<std::vector<int>> c;

  if (lerArquivo(caminhoArquivo, n, k, Q, L, r, d, p, c))
  {
    imprimirValores(n, k, Q, L, r, d, p, c);
  }
  else
  {
    std::cerr << "Falha ao ler os valores do arquivo." << std::endl;
  }

  return 0;
}