#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(){
  //Lendo uma imagem em tons de cinza
  Mat bolha = imread("C:/Users/joaov/opencv_cpp/src/bolhas.png", IMREAD_GRAYSCALE);
  //Pegando a altura e largura da imagem
  int width = bolha.cols, height = bolha.rows;
  //Acumuladora que vai servir para contar e rotular a imagem de saida
  int qtdObj = 0;
  //Estrutura capaz de guardar coordenadas em um plano bidimensional
  Point p;
  //Definindo os pontos iniciais
  p.x = 0;
  p.y = 0;
  //Percorre toda a imagem
  for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
          //Entra somente se for um obj
            if(bolha.at<uchar>(i,j) == 255){
                //Soma o acumulador
                qtdObj++;
                //Guarda a posição atual
                p.x = j;
                p.y = i;
                //Percorre toda a vizinhaça que tem a mesma caracteristica da posiçao atual(mesmo objeto) e rotula todas com o mesmo valor
                floodFill(bolha, p, qtdObj);
            }
        }
   }
  //Define como vai ser a janela e mostra a imagem
  namedWindow("Resultado", WINDOW_NORMAL);
  resizeWindow("Resultado", 300, 300);
  imshow("Resultado", bolha);
  //Mostra no console a quantidade de objetos
   cout << "a figura tem " << qtdObj << " bolhas\n";

   waitKey(0);
   return 0;

}
