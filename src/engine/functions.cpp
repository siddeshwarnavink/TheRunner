#include "engine/functions.h"
#include <iostream>

void place_text(sf::RenderWindow& window, const std::string& message, const sf::Font& font, unsigned int fontSize, const sf::Vector2f& position, const sf::Color& color) {
    sf::Text text;
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(fontSize);
    text.setPosition(position);
    text.setFillColor(color);

    window.draw(text);
}


float Move_Logic(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        return -0.2f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        return 0.2f;
    }

    return 0.0f;
}


void Jump_Logic(sf::Sprite& character,bool& IsJumping){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && IsJumping==false){
        IsJumping= true ;
        for(int i =0; i<1000;i++){
            character.move(0.0f,-0.1f);
        }
        // character.move(0.0f,-100.0f);
        return ;
    }
    else{
        character.move(0.0f,0.0f);
        return ;
    }
}

void Collision_Logic(sf::RectangleShape obstacles[],sf::Sprite& character,int ArrSize, bool& IsJumping){
    for(int i=0 ; i<ArrSize;i++){
        if(character.getPosition().x>=obstacles[i].getPosition().x && character.getPosition().x<= (obstacles[i].getPosition().x+obstacles[i].getGlobalBounds().width)){
            if(obstacles[i].getPosition().y-(character.getPosition().y+character.getGlobalBounds().height)<=1.0f){
                // return 0.0f;
                IsJumping=false;
                character.move(0.0f,0.0f);
                return;
            }
        }
    }
    // return 0.1f;
    IsJumping=true;
    character.move(0.0f,0.2f);
}