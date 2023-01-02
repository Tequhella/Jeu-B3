#include <SFML/Graphics.hpp>

using namespace sf;

class Input{
private:
    RenderWindow window;

    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;

    void input();
};