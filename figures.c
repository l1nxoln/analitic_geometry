#include <iostream>
#include <math.h>
#include <vector>
#define PI 3.14
using namespace std;

class Figure{
    public:
        vector<float> x;
        vector<float> y;
        int dots;
        Figure(){
            
        }
        Figure(vector<float> &xx, vector<float> &yy){
               x = xx;
               y = yy;
        }
        virtual float Perimeter(){
            return 0;
        }
        virtual float Area(){
            return 0;
        }
        virtual void getDots(){
            
        }
};

class Dot: public Figure{
    protected:
        double x;
        double y;
        int dots = 1;
    public:
        Dot(double xx, double yy){
          x = xx;
          y = yy;
        }
        virtual float Area(){
            cout << "None";
            return 0;
        }
        virtual float Perimeter(){
            cout << "None";
            return 0;
        }
        void getDots(){
            cout<<x<<" "<<y<<endl;
        }
        
};
class Circle: public Figure{
    public:
      float r;
      float s;
      int dots = 1;
        Circle(float rr){
            r = rr;
        }
        virtual float Area(){
            s = pow(r, 2)*PI;
            return s;
        }
        virtual float Perimeter(){
            return 2*PI*r;
        }
        void getDots(){
            cout<<dots;
        }
};
class Triangle: public Figure{
    protected:
        int dots = 3;
        float p;
        int x_plus;
        int y_plus;
    public:
        Triangle(){
        
        }
        Triangle(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y){
            x.push_back(a_x);
            x.push_back(b_x);
            x.push_back(c_x);
            y.push_back(a_y);
            y.push_back(b_y);
            y.push_back(c_y);
        }
        double side(int i){ 
            double x2,x1,y2,y1;
            if (i == 2)
            {
                x2 = x[0];
                x1 = x[2];
                y2 = y[0];
                y1 = y[2];
            }
            else
            {
                x2 = x[i+1];
                x1 = x[i];
                y2 = y[i+1];
                y1 = y[i];
            }
            return sqrt(pow(x2 - x1, 2)+pow(y2 - y1, 2));
        }
        virtual float Perimeter(){
            p = 0;
            for(int j = 0; j < dots; j++){
                p += side(j);
            }
            return p;
        }
        virtual float Area(){
            p = 0;
            for(int i = 0; i < dots; i++){
                if (i == x.size()-1){
                    x_plus = x[0];
                }
                else{
                    x_plus = x[i+1];
                }
                if (i == y.size()-1){
                    y_plus = y[0];
                }
                else{
                    y_plus = y[i+1];
                }
            }
            for(int j = 0; j < dots; j++){
                p += side(j);
            }
            return sqrt((p/2)*((p/2)-side(0))*((p/2)-side(1))*((p/2)-side(2)));
        }
        void getDots(){
            cout<<dots;
        }
};
class Polygon: public Figure{
    protected:
        vector<double> x;
        vector<double> y;
        int y_plus;
        float p;
        float s;
    public:
        Polygon(){
          
        }
        void set_points(vector<double> xx, vector<double> yy){
          x = xx;
          y = yy;
        }
        double side(int i){ 
            double x2,x1,y2,y1;
            if (i == x.size()-1)
            {
                x2 = x[0];
                x1 = x[x.size()-1];
                y2 = y[0];
                y1 = y[x.size()-1];
            }
            else
            {
                x2 = x[i+1];
                x1 = x[i];
                y2 = y[i+1];
                y1 = y[i];
            }
            return sqrt(pow(x2 - x1, 2)+pow(y2 - y1, 2));
        }
        virtual float Perimeter(){
            p = 0.0;
            for(int j = 0; j < x.size(); j++){
                p += side(j);
            }
            return p;
        }
        virtual float Area(){
            s = 0.0;
            // create triangle: i,i+1, centre
            for(int i = 0; i < x.size() - 2; i++){
                Triangle *t = new Triangle(x[0], y[0], x[i+1], y[i+1], x[i+2], y[i+2]);
                s += t->Area();
            }
            return s;
        }
        void getDots(){
          cout<<dots;
        }
};
class Square: public Polygon{
    protected:
        int dots = 4;
    public:
        Square(){
        
        }
        Square(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y, double d_x, double d_y){
            x.push_back(a_x);
            x.push_back(b_x);
            x.push_back(c_x);
            x.push_back(d_x);
            y.push_back(a_y);
            y.push_back(b_y);
            y.push_back(c_y);
            y.push_back(d_y);
        }
        void getDots(){
            cout<<dots;
        }
        
};
class Rhombus: public Square{
    protected:
        double diagonal[];
    public:
        Rhombus(){
        
        }
        Rhombus(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y, double d_x, double d_y){
            x.push_back(a_x);
            x.push_back(b_x);
            x.push_back(c_x);
            x.push_back(d_x);
            y.push_back(a_y);
            y.push_back(b_y);
            y.push_back(c_y);
            y.push_back(d_y);
        }
        void getDots(){
            cout<<dots;
        }
};
int main(){
    vector<double> xdot, ydot;
    xdot.push_back(0);
    ydot.push_back(0);
    vector<double> xpol, ypol;
    xpol.push_back(0);
    xpol.push_back(0);
    xpol.push_back(1);
    xpol.push_back(1);
    ypol.push_back(1);
    ypol.push_back(0);
    ypol.push_back(0);
    ypol.push_back(1);
    Triangle *t = new Triangle(0, 1, 0, 0, 1, 0);
    Polygon *p = new Polygon();
    p->set_points(xpol, ypol);
    Square *s = new Square(0, 1, 0, 0, 1, 0, 1, 1);
    Rhombus *r = new Rhombus(0, 1, 0, 0, 1, 0, 1, 1);
    Circle *c = new Circle(2);
    Dot *d = new Dot(0, 0);
    vector <Figure*> f;
    f.push_back(d);
    f.push_back(c);
    f.push_back(t);
    f.push_back(p);
    f.push_back(s);
    f.push_back(r);
    Figure *fig1 = new Figure();
    Figure *dot1 = d;
    Figure *fig2 = new Figure();
    Figure *circle1 = c;
    Figure *fig3 = new Figure();
    Figure *triangle1 = t;
    Figure *fig4 = new Figure();
    Figure *polygon1 = p;
    Figure *fig5 = new Figure();
    Figure *square1 = s;
    Figure *fig6 = new Figure();
    Figure *rhombus1 = r;
    for(int i = 0; i < f.size(); i++){
        f[i]->Area();
        f[i]->Perimeter();
        cout<<f[i]->Area()<<endl;
        cout<<f[i]->Perimeter()<<endl;
    }
}
