#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int width = 1024;
int height = 768;


int main(){
    cout << "test";
    RenderWindow app(VideoMode(width, height), "Racing Game");
    app.setFramerateLimit(60);
    
    // loading images into Sprite object vector
    Texture t[50];
    Sprite object[50];
    for(int i=1; i<=7; i++){
        t[i].loadFromFile("images/"+std::to_string(i)+".png");
        t[i].setSmooth(true);
        object[i].setTexture(t[i]);
    }

    // Setting background image
    Texture bg;
    bg.loadFromFile("images/bg.png");
    bg.setRepeated(true);
    Sprite sBackground(bg);
    sBackground.setTextureRect(IntRect(0,0,5000,411));
    sBackground.setPosition(-2000,0);

    // render background image
    app.clear(Color(105,205,4));
    app.draw(sBackground);


    app.display();

    while (app.isOpen()){
        Event event;
        while (app.pollEvent(event)){
            if (event.type == Event::Closed)
                app.close();
        }
    }    

    return 0;

}