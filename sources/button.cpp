/**
 * @file button.cpp
 * @author Lilian CHARDON (lilian.chardon@ynov.com)
 * @brief 
 * @version 0.1
 * @date 17-01-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../headers/button.h"

/****************/
/* CONSTRUCTEUR */
/****************/

Button::Button() : 
    rectangle(RectangleShape(Vector2f(30, 10))), 
    text(Text()), 
    font(Font()), 
    color(Color::White), 
    colorHover(Color::White), 
    colorClick(Color::White), 
    colorText(Color::White), 
    colorTextHover(Color::White), 
    colorTextClick(Color::White), 
    x(0), 
    y(0), 
    width(0), 
    height(0), 
    textString(""), 
    hover(false), 
    click(false)
{
    // rectangle
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(Color::Black);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(x, y);
    rectangle.setSize(Vector2f(width, height));

    // texte
    text.setFont(font);
    text.setString(textString);
    text.setFillColor(colorText);
    text.setCharacterSize(24);
    text.setPosition(x + (width / 2) - (text.getLocalBounds().width / 2), y + (height / 2) - (text.getLocalBounds().height / 2));
}

Button::Button(int x,
            int y,
            int width,
            int height,
            string textString,
            Color color,
            Color colorHover,
            Color colorClick,
            Color colorText,
            Color colorTextHover,
            Color colorTextClick) : 
    rectangle(RectangleShape(Vector2f(30, 10))),
    text(Text()),
    font(Font()),
    color(color),
    colorHover(colorHover),
    colorClick(colorClick),
    colorText(colorText),
    colorTextHover(colorTextHover),
    colorTextClick(colorTextClick),
    x(x),
    y(y),
    width(width),
    height(height),
    textString(textString),
    hover(false),
    click(false)
{
    // rectangle
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(Color::Black);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(x, y);
    rectangle.setSize(Vector2f(width, height));

    // texte
    text.setFont(font);
    text.setString(textString);
    text.setFillColor(colorText);
    text.setCharacterSize(24);
    text.setPosition(x + (width / 2) - (text.getLocalBounds().width / 2), y + (height / 2) - (text.getLocalBounds().height / 2));
}

Button::Button(ButtonArgs args) : 
    rectangle(args.rectangle), 
    text(args.text), 
    font(args.font), 
    color(args.color), 
    colorHover(args.colorHover), 
    colorClick(args.colorClick), 
    colorText(args.colorText), 
    colorTextHover(args.colorTextHover), 
    colorTextClick(args.colorTextClick), 
    x(args.x), 
    y(args.y), 
    width(args.width), 
    height(args.height), 
    textString(args.textString), 
    hover(args.hover), 
    click(args.click)
{
    // rectangle
    rectangle.setFillColor(color);
    rectangle.setOutlineColor(Color::Black);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(x, y);
    rectangle.setSize(Vector2f(width, height));

    // texte
    text.setFont(font);
    text.setString(textString);
    text.setFillColor(colorText);
    text.setCharacterSize(24);
    text.setPosition(x + (width / 2), y + (height / 2));
}

/***************/
/* DESTRUCTEUR */
/***************/

Button::~Button()
{
}

/***********/
/* SETTERS */
/***********/

void Button::setX(int x)
{
    this->x = x;
    rectangle.setPosition(x, y);
    text.setPosition(x + (width / 2) - (text.getLocalBounds().width / 2), y + (height / 2) - (text.getLocalBounds().height / 2));
}

void Button::setY(int y)
{
    this->y = y;
    rectangle.setPosition(x, y);
    text.setPosition(x + (width / 2) - (text.getLocalBounds().width / 2), y + (height / 2) - (text.getLocalBounds().height / 2));
}

void Button::setWidth(int width)
{
    this->width = width;
    rectangle.setSize(Vector2f(width, height));
    text.setPosition(x + (width / 2) - (text.getLocalBounds().width / 2), y + (height / 2) - (text.getLocalBounds().height / 2));
}

void Button::setHeight(int height)
{
    this->height = height;
    rectangle.setSize(Vector2f(width, height));
    text.setPosition(x + (width / 2) - (text.getLocalBounds().width / 2), y + (height / 2) - (text.getLocalBounds().height / 2));
}

void Button::setText(string textString)
{
    this->textString = textString;
    text.setString(textString);
    text.setPosition(x + (width / 2) - (text.getLocalBounds().width / 2), y + (height / 2) - (text.getLocalBounds().height / 2));
}

void Button::setColor(Color color)
{
    this->color = color;
    rectangle.setFillColor(color);
}

void Button::setColorHover(Color colorHover)
{
    this->colorHover = colorHover;
}

void Button::setColorClick(Color colorClick)
{
    this->colorClick = colorClick;
}

void Button::setColorText(Color colorText)
{
    this->colorText = colorText;
    text.setFillColor(colorText);
}

void Button::setFont(Font font)
{
    this->font = font;
    text.setFont(font);
}

/************/
/* METHODES */
/************/

void Button::draw(RenderWindow* window)
{
    window->draw(rectangle);
    //window->draw(text);
}

void Button::update(Vector2i mousePosition, bool mouseClick)
{
    if (mousePosition.x >= x && mousePosition.x <= x + width && mousePosition.y >= y && mousePosition.y <= y + height)
    {
        hover = true;
        rectangle.setFillColor(colorHover);
        text.setFillColor(colorTextHover);
    }
    else
    {
        hover = false;
        rectangle.setFillColor(color);
        text.setFillColor(colorText);
    }

    if (mouseClick && hover)
    {
        if (mousePosition.x >= x && mousePosition.x <= x + width && mousePosition.y >= y && mousePosition.y <= y + height)
        {
            click = true;
            rectangle.setFillColor(colorClick);
            text.setFillColor(colorTextClick);
            cout << "click" << endl;
        }
        else
        {
            click = false;
            rectangle.setFillColor(color);
            text.setFillColor(colorText);
            cout << "pas click" << endl;
        }
    }
    else /*--->*/ click = false;
}

bool Button::isHover()
{
    return hover;
}

bool Button::isClick()
{
    return click;
}

void Button::setHover(bool hover)
{
    this->hover = hover;
}

void Button::setClick(bool click)
{
    this->click = click;
}

void Button::updateText()
{
    text.setPosition(x + (width / 2) - (text.getLocalBounds().width / 2), y + (height / 2) - (text.getLocalBounds().height / 2));
}