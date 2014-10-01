#include <stdio.h>
#include <math.h>
#include <SFML/Graphics.hpp>
using namespace std;
//true: print x and y 
const bool printxy = false;
//true: print i
const bool printi = false;
//true: puts images in a folder
const bool outputimages = false;
//time (in miliseconds) to wait to achieve 24 fps
const int Mil_Per_Frame = 42;

//--------------------functions--------------------//
double f(double theta){
  return 100 + cos(10*theta);
}
double f2(double theta){
  return 100 + sin(10*theta);
}
double f3(double theta){
  return (theta/5.0 * theta/5.0)/10.0;
}


//Number of times any function has been displayed
static int numCompute = 0;
static int numImage = 0;
//Function for displaying the polar function. 
//Changes color after each run, loops through 3 colours
void compute(double (* f)(double theta), sf::RenderWindow* window){
  double sx = (double)(window->getSize()).x;
  double sy = (double)(window->getSize()).y;
  sf::CircleShape dot(1);
  if (numCompute == 0)
    dot.setFillColor(sf::Color(100, 250, 50)); 
  if (numCompute == 1)
    dot.setFillColor(sf::Color(250, 100, 50));
  if (numCompute == 2)
    dot.setFillColor(sf::Color(50, 100, 250));
  if (numCompute == 3)
    dot.setFillColor(sf::Color(100, 50, 250));
  if (numCompute == 3)
    dot.setFillColor(sf::Color(50, 250, 100));
  if (numCompute == 3)
    dot.setFillColor(sf::Color(250, 50, 100));
  numCompute = (numCompute + 1) %3;
  double x = sx/2;
  double y = sy/2;
  int i = 0;
  //While x and y are within the window bounds, and i is less than 1000
  //i<1000 bound to prevent repeating functions from repeating forever.
  while((x < sx && x > 0.0 && y < sy && y > 0.0) && i < 1000){
    double theta = i;
    double r = f(theta);
    x = r * cos(theta);
    y = r * sin(theta);
    x = (x + sx/2);
    y = (y + sy/2);
    if (printxy){
      printf("x: %f < %f y: %f < %f\n",x, sx,y, sy);
    }
    if (printi){
      printf("i: %i\n", i);
    }
    dot.setPosition(x,y);
    window->draw(dot);
    window->display();
    if(outputimages){
      if(i < 400 and i % 3 == 0){
        char filename[50];
        if(numImage < 10){
          sprintf(filename,"images/00%i.png", numImage);
        }
        else if(numImage < 100){
          sprintf(filename,"images/0%i.png", numImage);
        }
        else{
          sprintf(filename,"images/%i.png", numImage);
        }
        (window->capture()).saveToFile(filename);
        numImage++;
        printf("numImages %i\n", numImage);
      }
    }
    i++;
  }
}
void paintAxes(sf::RenderWindow* window){
  double sx = (double)(window->getSize()).x;
  double sy = (double)(window->getSize()).y; 
  sf::RectangleShape xaxis(sf::Vector2f(1, sy));
  sf::RectangleShape yaxis(sf::Vector2f(sx, 1));
  xaxis.setPosition(sx/2,0);
  yaxis.setPosition(0,sy/2);
  window->draw(xaxis);
  window->draw(yaxis);
}
int main(){
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(500, 500), "Polar");
  window->clear();
  paintAxes(window);
  compute(f3,window);
  compute(f2,window);
  compute(f,window);
  window->clear();
  return 0;
}
