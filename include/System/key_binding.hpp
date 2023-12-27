#ifndef KEY_BINDING_HPP_INCLUDED
#define KEY_BINDING_HPP_INCLUDED

//Prompt:
//make me a class Key_binding, it has a vector of Key_event structures that have a string with the name of the event and the keybiding from the SFML library.
//I need to be able to add a key binding to the class.
//I need to be able to ask the class if a key biding is present, and return the associated string

#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <string>

struct Key_event
{
    std::string name;
    sf::Keyboard::Key key;
};

class Key_binding
{
    public:
        Key_binding()
        {
            return;
        }

        int get_registered_events()
        {
            return gvst_key_events.size();
        }

        void add_key_event(const std::string& name, const sf::Keyboard::Key& key)
        {
            gvst_key_events.push_back({name, key});
        }

        std::string get_key_binding(const sf::Keyboard::Key& key) const
        {
            for (const auto& key_event : this->gvst_key_events)
            {
                if (key_event.key == key)
                {
                    return key_event.name;
                }
            }
            return "";
        }

        sf::Keyboard::Key get_event_key(const std::string& name) const
        {
            for (const auto& key_event : this->gvst_key_events)
            {
                if (key_event.name == name)
                {
                    return key_event.key;
                }
            }
            return sf::Keyboard::Unknown;
        }

    private:
        std::vector<Key_event> gvst_key_events;
};

#endif
