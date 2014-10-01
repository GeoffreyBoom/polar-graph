#include <stdio.h>
#include <math.h>
#include <SFML/Graphics.hpp>
using namespace std;
const bool printxy = true;
const bool printi = true;
const int Mil_Per_Frame = 42;
double f(double theta){
  return 50 + cos(100*theta);
}
double f2(double theta){
  return 100 + sin(100*theta);
}
double f3(double theta){
  return (theta * theta);
}
static int numCompute = 0;
void compute(double (* f)(double theta), sf::RenderWindow* window){
  double sx = (double)(window->getSize()).x;
  double sy = (double)(window->getSize()).y;
  sf::CircleShape dot(1);
  if (numCompute == 0)
    dot.setFillColor(sf::Color(100, 250, 50)); 
  if (numCompute == 1)
    dot.setFillColor(sf::Color(250, 50, 100));
  numCompute = (numCompute + 1) %2;
  double x = sx/2;
  double y = sy/2;
  double i = 0.0;
  while((x < sx && x > 0.0 && y < sy && y > 0.0) && i < 1000.0){
    double theta = i / 10.0;
    double r = f(theta);
    x = r * cos(theta);
    y = r * sin(theta);
    x = (x + sx/2);
    y = (y + sy/2);
    if (printxy){
      printf("x: %f < %f y: %f < %f\n",x, sx,y, sy);
    }
    if (printi){
      printf("i: %f\n", i);
    }
    dot.setPosition(x,y);
    window->draw(dot);
    window->display();
    i++;
  }
}

int main(){
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(500, 500), "My window");
  window->clear();
  compute(f3,window);
  compute(f2,window);
  compute(f,window);
  window->clear();
  return 0;
}

