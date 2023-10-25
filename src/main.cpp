#include "utils/fileops.cpp"
#include "core/greedy.cpp"
#include "core/vnd.cpp"
#include "core/neighborhood.cpp"

using namespace std;

int main()
{
  setlocale(LC_ALL, "pt_BR.UTF-8");
  // Ler nome do arquivo por input do usuário
  /*std::string nomeArquivo;
  std::cout << "Digite o nome do arquivo (sem o caminho, apenas o nome do arquivo): ";
  std::cin >> nomeArquivo;*/

  std::string nomeArquivo = "test";
  std::string caminhoArquivo = "../data/instancias/" + nomeArquivo + ".txt";

  try
  {
    Instancia instancia = lerArquivo(caminhoArquivo);
    Solucao solucao = greedy(instancia);
    printSolucao(solucao);
    imprimirValores(instancia);
  }
  catch (FileReadError &e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}