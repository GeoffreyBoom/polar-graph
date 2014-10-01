#include <stdio.h>
#include <math.h>
#include <SFML/Graphics.hpp>
using namespace std;
const int Mil_Per_Frame = 42;
double f(double theta){
  return cos(2*theta);
}
double f2(double theta){
  return 100 + sin(100*theta);
}
double f3(double theta){
  return (theta * theta);
}
static int numCompute = 0;
void compute(double (* f)(double theta), sf::RenderWindow* window){
  sf::CircleShape shape(1);
  if (numCompute == 0)
    shape.setFillColor(sf::Color(100, 250, 50)); 
  if (numCompute == 1)
    shape.setFillColor(sf::Color(250, 50, 100));
  numCompute = (numCompute + 1) %2;
  for(int i = 0; i < 10000000; i++){
    double theta = i / 10.0;
    double r = f(theta);
    double x = r * cos(theta);
    double y = r * sin(theta);
    printf("%f ",r);
    x = (x + 500);
    y = (y + 500);
    shape.setPosition(x,y);
    window->draw(shape);
    window->display();
  }
}

int main(){
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "My window");
  //std::thread one(compute, f, window);
  //std::thread two(compute, f2, window);
  window->clear();
  compute(f3,window);
  compute(f2,window);
  compute(f,window);
  window->clear();
  return 0;
}

