#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
  //Imagem em tons de cinza
  Mat img = imread("C:/Users/joaov/Downloads/foto.jpeg", IMREAD_GRAYSCALE);
  //Cria uma estrutura para guarda os três canais da imagem
  vector<Mat> channels;
  //Separa os canais
  split(img, channels);
  //Adiciona um nome a janela que vai apresentar a imagem
  namedWindow("Imagem Original", WINDOW_NORMAL);
  //Define o tamanho da janela
  resizeWindow("Imagem Original", 300, 300);
  //Mostra a imagem na janela
  imshow("Imagem Original", img);
  //Espera que uma tecla seja pressionada
   waitKey(0);
  //Retorna 0 ao termino do programa
   return 0;
}
