#include <vector>
#include <algorithm>
#include <numeric>

struct Solucao
{
  std::vector<std::vector<int>> rotas;
  int carga;
  int tempo;
};

Solucao greedy(const Instancia &instancia)
{
  Solucao solucao;
  solucao.rotas.resize(instancia.k);
  solucao.carga = 0;
  solucao.tempo = 0;

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
    std::cout << "Rota: " << rota_atual << std::endl;

    for (int j = 1; j < instancia.n + 1; ++j)
    {
      if (!(std::find(visitados.begin(), visitados.end(), j) != visitados.end()))
      {
        if (instancia.d[j - 1] + carga_atual < instancia.Q)
        {
          std::cout << "Pos_atual: " << pos_atual << ", Destino: " << j << ", Valor: " << instancia.d[j - 1] << ", Custo: " << instancia.c[pos_atual][j] << std::endl;
          if (instancia.c[pos_atual][j] <= instancia.c[pos_atual][melhor])
          {
            melhor = j;
            sem_troca = false;
            std::cout << "Melhor: " << melhor << std::endl;
          }
        }
      }
    }

    if (sem_troca)
    {
      std::cout << "Carro cheio!" << std::endl;
      solucao.tempo += instancia.c[pos_atual][0];
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
      solucao.tempo += instancia.c[pos_atual][melhor];
      pos_atual = melhor;
    }

    std::cout << "Visitados: ";
    for (int i = 0; i < visitados.size(); ++i)
    {
      std::cout << visitados[i];
      if (i < visitados.size() - 1)
      {
        std::cout << "   ";
      }
    }
    std::cout << std::endl;

    std::cout << "Carga atual: " << carga_atual << std::endl;
  }

  int custo_rotas = instancia.r * rota_atual;
  solucao.tempo += custo_rotas;

  std::cout << "Custo de utilização de veículos: " << custo_rotas << std::endl;

  int custo_terceirizados = 0;
  std::cout << "Não visitados: ";
  for (int i = 0; i < nao_visitados.size(); ++i)
  {
    std::cout << nao_visitados[i];
    custo_terceirizados += instancia.p[nao_visitados[i] - 1];
    if (i < nao_visitados.size() - 1)
    {
      std::cout << "   ";
    }
  }
  std::cout << std::endl;

  solucao.tempo += custo_terceirizados;
  std::cout << "Custo de terceirização: " << custo_terceirizados << std::endl;

  return solucao;
}

void printSolucao(const Solucao &solucao)
{
  std::cout << "Custo da solução gulosa: " << solucao.tempo << std::endl;
  std::cout << "Carga da solução gulosa: " << solucao.carga << std::endl;
  std::cout << "Rotas da solução gulosa: ";
  for (int i = 0; i < solucao.rotas.size(); ++i)
  {
    std::cout << std::endl
              << "Rota " << i + 1 << ": 0   ";
    for (int j = 0; j < solucao.rotas[i].size(); ++j)
    {
      std::cout << solucao.rotas[i][j];
      if (j < solucao.rotas[i].size() - 1)
      {
        std::cout << "   ";
      }
    }
  }
  std::cout << std::endl;
}