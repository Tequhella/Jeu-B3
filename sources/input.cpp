#include "input.h"


void Input::input()
{

    // Handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		m_UpPressed = true;
    }
    else
    {
        m_UpPressed = false;
	}
    if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		m_DownPressed = true;
    }
    else
    {
        m_DownPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}
}