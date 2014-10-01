#include <stdio.h>
#include <math.h>
#include <SFML/Graphics.hpp>
using namespace std;
double f(double theta){
  return 1 + cos(theta);
}

void compute(double (* f)(double theta)){
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
  sf::CircleShape shape(2);
  shape.setFillColor(sf::Color(100, 250, 50));
  for(int i = 0; i < 1000; i++){
    double theta = i / 1000.0;
    double output = f(theta);
    double x = cos(i);
    double y = sin(i);
    shape.setPosition(x,y);
  }
}

int main(){
  double i = f(10.0);
  printf("%f", i);

}


