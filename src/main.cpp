#include "utils/fileops.cpp"
#include "core/greedy.cpp"
#include "core/vnd.cpp"
#include "core/neighborhood.cpp"

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