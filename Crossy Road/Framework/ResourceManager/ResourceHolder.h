#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "res_manager.h"
#include "res_manager.h"
//#include "../Util/NonCopyable.h"
//#include "../Util/NonMoveable.h"
#include "../Util/no_copy.h"

class ResourceHolder : public no_copy
{
    public:
        static ResourceHolder& get();

        res_manager<sf::Font>           fonts;
        res_manager<sf::Texture>        textures;
        res_manager<sf::SoundBuffer>    soundBuffers;

    private:
        ResourceHolder();
};
