#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>
using namespace std;

void func1(int &a, int &b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void normolizetime(int &hours, int &minutes, int &seconds){
    //convert extra seconds to minutes
    int extraminutes = minutes / 60;
    seconds = seconds % 60; //remaining seconds
    minutes = minutes + extraminutes;
    //convert extra minutes to hours
    int extrahours = minutes/60;
    minutes = minutes % 60;
    hours = hours + extrahours; 
}
int convertToMinutes(int hours, int minutes, int seconds){
    normolizetime(hours, minutes, seconds);
    //hours to minutes
    int MinutesFromHours = hours * 60; 
    //seconds to minutes
    int MinutesFromSeconds = seconds*60;
    //all together
    int totalMinutes = MinutesFromHours + MinutesFromSeconds + minutes;
    return totalMinutes;
}

//calculate area of circle
float area(float radius){
    return M_PI * radius * radius;
}
//calculate area of rectangle
float area(float width, float length){
    return length * width;
}
//calculate area of triangle
float area(double base, double height){
    return 0.5 * base * height;
}
//calculate are of dquare
float area(int side){
    return side*side;
}

//largest out of three nums
float largest(float a, float b, float c){
    if (a >= b && a >= c){
        return a;
    }   else if (b >= a && b >= c){
        return b;
    }   else {
        return c;
    }
}

int main(){

cout << "enter which program you want: \n";
cout << "1. Swapping numbers\n";
cout << "2. Time -> minutes\n";
cout << "3. Circle, Rectangle, Trianle, Square Area calculator\n";
cout << "4. The largest among three numbers\n";
char a;
cin >> a;
switch(a){
    case '1':   
        int x, y; 
        cout << "Enter the first number: ";
        cin >> x; cout << endl;
        cout << "Enter the next number: ";
        cin >> y; cout << endl;
        cout << "Before swapping your nums: " << x << "and" << y << endl;
        func1(x,y);
        cout << "After swapping your nums: " << x << "and" << y << endl;
        break;
    case '2': {
        int hours, seconds, minutes;
        cout << "enter hours: ";
        cin >> hours;
        cout << "enter minutes: ";
        cin >> minutes;
        cout << "enter seconds: ";
        cin >> seconds;
        //convert to whole time minutes
        int totalMinutes = convertToMinutes(hours, minutes, seconds);
        cout << "total time: " << totalMinutes; 
        break;}
    case '3':
        float radius, length, width;
        double base, height;
        int side;

        //circle 
        cout << "enter the radius of a circle: ";
        cin >> radius;
        cout << "Area of circle: " << area(radius) << endl;

        //rectangle
        cout << "\nEnter length and width of the rectangle: ";
        cin >> length >> width;
        cout << "Area of a rectangle: " << area(length, width) << endl;

        //triangle
        cout << "Enter base and height of triangle: ";
        cin >> base >> height;
        cout << "Area of triangle: " << area(base, height) << endl;

        //square
        cout << "Enter side of square: ";
        cin  >> side;
        cout << "Area of square: " << area(side) << endl;
        break;

    case '4':
        float a,b,c;
        cout << "enter three numbers: ";
        cin >> a >> b >> c;
        cout << "the largest number is: " << largest(a,b,c) << endl;
        return 0;
}
    
}