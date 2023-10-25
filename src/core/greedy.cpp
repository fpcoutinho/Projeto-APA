#include <vector>
#include <algorithm>
#include <numeric>

struct Solucao
{
  std::vector<std::vector<int>> rotas;
  int carga;
  int custo_roteamento;
  int custo_veiculos;
  int custo_terceirizacao;
  int rotas_percorridas;
  std::vector<int> nao_visitados;
};

Solucao greedy(const Instancia &instancia)
{
  Solucao solucao;
  solucao.rotas.resize(instancia.k);
  solucao.carga = 0;
  solucao.custo_roteamento = 0;

  std::vector<int> nao_visitados(instancia.n);
  std::iota(nao_visitados.begin(), nao_visitados.end(), 1);

  std::vector<int> visitados = {};
  int rota_atual = 0;
  int pos_atual = 0;
  int carga_atual = 0;
  int melhor;
  float custo;
  bool sem_troca;

  while (visitados.size() < instancia.n && rota_atual < instancia.k)
  {
    if (pos_atual == nao_visitados[0])
    {
      melhor = nao_visitados[1];
    }
    else
    {
      melhor = nao_visitados[0];
    }
    sem_troca = true;

    for (int j = 1; j < instancia.n + 1; ++j)
    {
      if (!(std::find(visitados.begin(), visitados.end(), j) != visitados.end()))
      {
        if (instancia.d[j - 1] + carga_atual < instancia.Q)
        {
          if (instancia.c[pos_atual][j] <= instancia.c[pos_atual][melhor])
          {
            melhor = j;
            sem_troca = false;
          }
        }
      }
    }

    if (sem_troca)
    {
      solucao.custo_roteamento += instancia.c[pos_atual][0];
      solucao.rotas[rota_atual].push_back(0);
      rota_atual++;
      pos_atual = 0;
      carga_atual = 0;
    }
    else
    {
      visitados.push_back(melhor);
      nao_visitados.erase(std::remove(nao_visitados.begin(), nao_visitados.end(), melhor), nao_visitados.end());
      solucao.rotas[rota_atual].push_back(melhor);
      carga_atual += instancia.d[melhor - 1];
      solucao.carga += instancia.d[melhor - 1];
      solucao.custo_roteamento += instancia.c[pos_atual][melhor];
      pos_atual = melhor;
    }
  }

  solucao.custo_veiculos = instancia.r * rota_atual;
  solucao.nao_visitados = nao_visitados;
  solucao.rotas_percorridas = rota_atual + 1;
  solucao.custo_terceirizacao = 0;
  for (int i = 0; i < nao_visitados.size(); ++i)
  {
    solucao.custo_terceirizacao += instancia.p[nao_visitados[i] - 1];
  }

  return solucao;
}

void imprimirSolucao(const Solucao &solucao)
{
  std::cout << "Valor total da solução: " << solucao.custo_roteamento + solucao.custo_terceirizacao + solucao.custo_veiculos << std::endl;
  std::cout << "Custo de roteamento: " << solucao.custo_roteamento << std::endl;
  std::cout << "Custo associado a utilização de veículos: " << solucao.custo_veiculos << std::endl;
  std::cout << "Custo de terceirização: " << solucao.custo_terceirizacao << std::endl;
  std::cout << std::endl;
  std::cout << "Lista de clientes terceirizados: ";
  for (int i = 0; i < solucao.nao_visitados.size(); ++i)
  {
    std::cout << solucao.nao_visitados[i];
    if (i < solucao.nao_visitados.size() - 1)
    {
      std::cout << "   ";
    }
  }
  std::cout << std::endl;

  std::cout << "\nNúmero de rotas: " << solucao.rotas_percorridas << std::endl;
  for (int i = 0; i < solucao.rotas_percorridas; ++i)
  {
    std::cout
        << "Rota " << i + 1 << ": 0   ";
    for (int j = 0; j < solucao.rotas[i].size(); ++j)
    {
      std::cout << solucao.rotas[i][j];
      if (j < solucao.rotas[i].size() - 1)
      {
        std::cout << "   ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void salvarSolucao(const Solucao &solucao, const std::string &filename)
{
  std::string filepath = "../data/resultados/" + filename + "_resultados.txt";
  std::ofstream arquivo(filepath);

  if (!arquivo.is_open())
    throw std::runtime_error("Erro ao abrir arquivo para escrita");

  arquivo << solucao.custo_roteamento + solucao.custo_terceirizacao + solucao.custo_veiculos << std::endl;
  arquivo << solucao.custo_roteamento << std::endl;
  arquivo << solucao.custo_veiculos << std::endl;
  arquivo << solucao.custo_terceirizacao << std::endl;
  arquivo << std::endl;
  for (int i = 0; i < solucao.nao_visitados.size(); ++i)
  {
    arquivo << solucao.nao_visitados[i];
    if (i < solucao.nao_visitados.size() - 1)
    {
      arquivo << "  ";
    }
  }
  arquivo << std::endl;

  arquivo << std::endl
          << solucao.rotas_percorridas << std::endl;
  for (int i = 0; i < solucao.rotas_percorridas; ++i)
  {
    for (int j = 0; j < solucao.rotas[i].size() - 1; ++j)
    {
      arquivo << solucao.rotas[i][j];
      if (j < solucao.rotas[i].size() - 1)
      {
        arquivo << "  ";
      }
    }
    arquivo << std::endl;
  }

  arquivo.close();
}