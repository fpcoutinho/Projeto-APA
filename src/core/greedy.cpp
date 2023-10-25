#include <vector>
#include <algorithm>

struct Solucao
{
  std::vector<int> rotas;
  int carga;
  int tempo;
};

Solucao greedy(const Instancia &instancia)
{
  Solucao solucao;
  solucao.rotas.resize(instancia.n);
  solucao.carga = 0;
  solucao.tempo = 0;

  for (int i = 0; i < instancia.n; ++i)
  {
    solucao.rotas[i] = 0;
  }

  int pos_atual = 0;
  int custo = 0;
  int melhor;
  int tamanho_caminho = 0;

  while (tamanho_caminho < instancia.n)
  {
    melhor = 0;
    for (int j = 1; j < instancia.n + 1; ++j)
    {
      if (!(std::find(solucao.rotas.begin(), solucao.rotas.end(), j) != solucao.rotas.end()))
      {
        if (instancia.d[j - 1] + solucao.carga < instancia.Q)
        {
          float custo = float(instancia.d[j - 1]) / instancia.c[pos_atual][j];
          std::cout << "Pos_atual: " << pos_atual << ", Destino: " << j << ", Valor: " << instancia.d[j - 1] << ", Custo: " << instancia.c[pos_atual][j] << ", Valor/Custo: " << custo << std::endl;
          if (custo > melhor)
          {
            melhor = j;
          }
        }
      }
    }
    if (melhor == 0)
      break;
    std::cout << "Pos_atual: " << pos_atual << ", Melhor: " << melhor << ", Valor: " << instancia.d[melhor - 1] << ", Custo: " << instancia.c[pos_atual][melhor] << ", Valor/Custo: " << custo << std::endl;

    solucao.rotas[tamanho_caminho] = melhor;
    solucao.carga += instancia.d[melhor];
    solucao.tempo += instancia.c[pos_atual][melhor];
    pos_atual = melhor;
    tamanho_caminho++;
  }

  return solucao;
}

void printSolucao(const Solucao &solucao)
{
  std::cout << "Custo da solução gulosa: " << solucao.tempo << std::endl;
  std::cout << "Carga da solução gulosa: " << solucao.carga << std::endl;
  std::cout << "Rotas da solução gulosa: ";
  for (int i = 0; i < solucao.rotas.size(); ++i)
  {
    std::cout << solucao.rotas[i];
    if (i < solucao.rotas.size() - 1)
    {
      std::cout << "   ";
    }
  }
  std::cout << std::endl;
}